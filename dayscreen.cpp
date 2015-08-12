#include "dayscreen.h"
#include "gamevariables.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QSound>

DayScreen::DayScreen(QWidget *parent) : QFrame(parent)
{
    formalBellEffect.setSource(QUrl("qrc:/sounds/FormalTimerBell.wav"));
    formalBellEffect.setVolume(0.80f);

    dayBellEffect.setSource(QUrl("qrc:/sounds/DayTimerBell.wav"));
    dayBellEffect.setVolume(0.80f);



    // Label showing day number with button to restart (send to character screen) in same row
    dayLabel = new QLabel;
    restartButton = new QPushButton("Restart");
    restartButton->setFocusPolicy(Qt::NoFocus);

    // Sends user to info screen
    infoButton = new InfoButton;

    QHBoxLayout *dayLayout = new QHBoxLayout;
    dayLayout->addWidget(dayLabel);
    dayLayout->addStretch();
    dayLayout->addWidget(restartButton);
    dayLayout->addWidget(infoButton);


    // Labels displaying day timer
    dayTimerButton = new QPushButton("Timer");
    dayTimerButton->setCheckable(true);
    dayTimerButton->setFocusPolicy(Qt::NoFocus);
    dayTimerLabel = new QLabel;
    dayTimerLabel->setObjectName("dayTimerLabel");
    dayTimer = new QTimer(this);

    /*
    QHBoxLayout *dayTimerLayout = new QHBoxLayout;
    dayTimerLayout->addWidget(dayTimerButton);
    dayTimerLayout->addStretch();
    dayTimerLayout->addWidget(dayTimerLabel);
    dayTimerLayout->addStretch();
    */

    // Button which when pushed, starts the formal timer
    formalTimerButton = new QPushButton("Formal");
    formalTimerButton->setCheckable(true);
    formalTimerButton->setFocusPolicy(Qt::NoFocus);
    formalTimerLabel = new QLabel;
    formalTimerLabel->setObjectName("formalTimerLabel");
    formalTimer = new QTimer(this);
    resetTimers();

    /*
    QHBoxLayout *formalTimerLayout = new QHBoxLayout;
    formalTimerLayout->addWidget(formalTimerButton);
    formalTimerLayout->addStretch();
    formalTimerLayout->addWidget(formalTimerLabel);
    formalTimerLayout->addStretch();
    */

    QGridLayout *timersLayout = new QGridLayout;
    timersLayout->addWidget(dayTimerButton, 0, 0);
    timersLayout->addWidget(dayTimerLabel, 0, 2);
    timersLayout->addWidget(formalTimerButton, 2, 0);
    timersLayout->addWidget(formalTimerLabel, 2, 2);
    //timersLayout->setContentsMargins(30, 30, 30, 30);
    timersLayout->setColumnMinimumWidth(1, 40);
    timersLayout->setRowMinimumHeight(1, 40);

    // Buttons for navigating to the morning phase, or start a new night phase
    prevButton = new QPushButton("Previous");
    prevButton->setFocusPolicy(Qt::NoFocus);
    nightButton = new QPushButton("Night");
    nightButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *navigBtnLayout = new QHBoxLayout;

    navigBtnLayout->addWidget(prevButton);
    navigBtnLayout->addStretch();
    navigBtnLayout->addWidget(nightButton);

    QVBoxLayout *dayScreenLayout = new QVBoxLayout;
    dayScreenLayout->addLayout(dayLayout);
    dayScreenLayout->addStretch();
    dayScreenLayout->addLayout(timersLayout);
    //dayScreenLayout->addLayout(dayTimerLayout);
    //dayScreenLayout->addLayout(formalTimerLayout);
    dayScreenLayout->addStretch();
    dayScreenLayout->addLayout(navigBtnLayout);

    setLayout(dayScreenLayout);

    connect(dayTimer, &QTimer::timeout, this, &DayScreen::updateDayTimer);
    connect(dayTimerButton, &QPushButton::clicked, this, &DayScreen::startDayTimer);

    connect(formalTimer, &QTimer::timeout, this, &DayScreen::updateFormalTimer);
    connect(formalTimerButton, &QPushButton::clicked, this, &DayScreen::startFormalTimer);
}

// Stop the day and formal timers then reset the minutes and second values to the game variables
void DayScreen::resetTimers()
{
    if (dayTimer->isActive())
    {
        dayTimer->stop();
        dayTimerButton->setChecked(false);
    }
    dayMinutes = GameVariables::dayTimerMinutes;
    daySeconds = 0;
    dayTimerLabel->setText(QString("<h1>%1:%2</h1>").arg(dayMinutes, 2, 10, QChar(' '))
                                       .arg(daySeconds, 2, 10, QChar('0')));

    if (formalTimer->isActive())
    {
        formalTimer->stop();
        formalTimerButton->setChecked(false);
    }

    formalMinutes = GameVariables::formalTimerMinutes;
    formalSeconds = GameVariables::formalTimerSeconds;
    formalTimerLabel->setText(QString("<h1>%1:%2</h1>").arg(formalMinutes, 2, 10, QChar(' '))
                                       .arg(formalSeconds, 2, 10, QChar('0')));

}

void DayScreen::startDayTimer()
{
    if (dayTimer->isActive()) {
        dayTimer->stop();
        dayTimerButton->setChecked(false);
    } else {
        if (dayMinutes == 0 && daySeconds == 0) {
            dayMinutes = GameVariables::dayTimerMinutes;
        }

        dayTimer->start(1000);
        dayTimerButton->setChecked(true);
    }
}

void DayScreen::updateDayTimer()
{
    if (dayTimer->isActive())
        dayTimerButton->setChecked(true);
    else
        dayTimerButton->setChecked(false);

    if (daySeconds == 0) {
        if (dayMinutes == 0) {
            dayTimer->stop();
            dayTimerButton->setChecked(false);
            dayBellEffect.play();

        } else {
            --dayMinutes;
            daySeconds = 59;
        }
    } else {
        --daySeconds;
    }

    dayTimerLabel->setText(QString("<h1>%1:%2</h1>").arg(dayMinutes, 2, 10, QChar(' '))
                                       .arg(daySeconds, 2, 10, QChar('0')));
}


void DayScreen::startFormalTimer()
{

    if (formalTimer->isActive()) {
        formalTimer->stop();

    } else {
        if (GameVariables::pauseDay)
        {

            startDayTimer();
        }
        if (formalMinutes == 0 && formalSeconds == 0) {
            formalMinutes = GameVariables::formalTimerMinutes;
            formalSeconds = GameVariables::formalTimerSeconds;
        }

        formalTimer->start(1000);
        formalTimerButton->setChecked(true);
    }
}

void DayScreen::updateFormalTimer()
{
    if (formalTimer->isActive())
        formalTimerButton->setChecked(true);
    else
        formalTimerButton->setChecked(false);

    if (formalSeconds == 0) {
        if (formalMinutes == 0) {
            formalTimer->stop();
            formalTimerButton->setChecked(false);
            formalBellEffect.play();
        } else {
            --formalMinutes;
            formalSeconds = 59;
        }
    } else {
        --formalSeconds;
    }

    formalTimerLabel->setText(QString("<h1>%1:%2</h1>").arg(formalMinutes, 2, 10, QChar(' '))
                                       .arg(formalSeconds, 2, 10, QChar('0')));
}

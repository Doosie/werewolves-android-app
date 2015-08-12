#include "settingsscreen.h"
#include "gamevariables.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

SettingsScreen::SettingsScreen(QFrame *parent) : QFrame(parent)
{
    titleLabel = new QLabel("<h1>Settings</h1>");

    // Label and SpinBox to input day Timer in minutes
    QLabel *dayTimerLabel = new QLabel("Day Timer");
    dayTimerButton = new SetTimerButton("Day");

    QLabel *formalTimerLabel = new QLabel("Formal Timer");
    formalTimerButton = new SetTimerButton("Formal");

    QGridLayout *timerLayout = new QGridLayout;
    timerLayout->addWidget(dayTimerLabel, 0, 0);
    timerLayout->addWidget(dayTimerButton, 0, 2);
    timerLayout->addWidget(formalTimerLabel, 2, 0);
    timerLayout->addWidget(formalTimerButton, 2, 2);

    pauseDayCheckBox = new QCheckBox;
    pauseDayCheckBox->setFocusPolicy(Qt::NoFocus);
    pauseDayLabel = new QLabel("Pause day timer when formal is started");
    pauseDayLabel->setWordWrap(true);

    QHBoxLayout *pauseDayLayout = new QHBoxLayout;
    pauseDayLayout->addWidget(pauseDayCheckBox);
    pauseDayLayout->addWidget(pauseDayLabel);
    //pauseDayLayout->addStretch();


    doneButton = new QPushButton("Done");
    doneButton->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *settingsScreenLayout = new QVBoxLayout;
    settingsScreenLayout->addWidget(titleLabel);
    settingsScreenLayout->addStretch();
    settingsScreenLayout->addLayout(timerLayout);
    settingsScreenLayout->addStretch();
    settingsScreenLayout->addLayout(pauseDayLayout);
    settingsScreenLayout->addStretch();
    settingsScreenLayout->addWidget(doneButton);

    setLayout(settingsScreenLayout);

    connect(dayTimerButton, &QPushButton::clicked, this, &SettingsScreen::showDayDialog);
    connect(formalTimerButton, &QPushButton::clicked, this, &SettingsScreen::showFormalDialog);

}

void SettingsScreen::showDayDialog()
{
    dayTimerButton->timerDialog->show();

    QPoint pos = mapToGlobal(QPoint(width()/2  - dayTimerButton->timerDialog->width()/2,
                                     height()/2 - dayTimerButton->timerDialog->height()/2 ));
    dayTimerButton->timerDialog->move( pos );
}

void SettingsScreen::showFormalDialog()
{
    formalTimerButton->timerDialog->show();

    QPoint pos = mapToGlobal(QPoint(width()/2  - formalTimerButton->timerDialog->width()/2,
                                     height()/2 - formalTimerButton->timerDialog->height()/2 ));
    formalTimerButton->timerDialog->move(pos);
}

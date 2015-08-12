#include "settimerbutton.h"
#include "gamevariables.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

SetTimerButton::SetTimerButton(QString name, QWidget *parent) : buttonName(name), QPushButton(parent)
{

    setFocusPolicy(Qt::NoFocus);

    timerDialog = new QDialog(parent);
    //timerDialog->setFixedSize(200, 200);
    timerDialog->setObjectName("timerDialog");
    timerDialog->setStyleSheet(".QDialog { background-color: #2E77B2; }");
    timerDialog->setModal(true);

    timeLabel = new QLabel;
    if (buttonName == "Day") {
        setText(QString("%1:00").arg(GameVariables::dayTimerMinutes, 2, 10, QChar(' ')));
        timeLabel->setText(QString("%1:00").arg(GameVariables::dayTimerMinutes, 2, 10, QChar(' ')));

    } else {
        setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                .arg(GameVariables::formalTimerSeconds, 2, 10, QChar('0')));
        timeLabel->setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                           .arg(GameVariables::formalTimerSeconds, 2, 10, QChar('0')));
    }

    minusButton = new QPushButton("-");
    minusButton->setFocusPolicy(Qt::NoFocus);
    minusButton->setAutoRepeat(true);
    plusButton = new QPushButton("+");
    plusButton->setFocusPolicy(Qt::NoFocus);
    plusButton->setAutoRepeat(true);

    QVBoxLayout *timeLayout = new QVBoxLayout;
    timeLayout->addWidget(minusButton);
    timeLayout->addWidget(timeLabel);
    timeLayout->addWidget(plusButton);

    okButton = new QPushButton("OK");
    okButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *dialogLayout = new QHBoxLayout;
    dialogLayout->addLayout(timeLayout);
    dialogLayout->addWidget(okButton);

    timerDialog->setLayout(dialogLayout);


    connect(minusButton, &QPushButton::clicked, this, &SetTimerButton::on_minusButton_clicked);
    connect(plusButton, &QPushButton::clicked, this, &SetTimerButton::on_plusButton_clicked);
    connect(okButton, &QPushButton::clicked, this, &SetTimerButton::on_okButton_clicked);
}

void SetTimerButton::on_minusButton_clicked()
{
    // if day button is pressed
    if (buttonName == "Day") {
        // if dayTimerMinutes is above its minimum (1) decrement the minutes by 1 then update timeLabel
        if (GameVariables::dayTimerMinutes > 1) {
            --GameVariables::dayTimerMinutes;
            timeLabel->setText(QString("%1:00").arg(uint(GameVariables::dayTimerMinutes), 2, 10, QChar(' ')));
        }
    } else {
        // if formalTimerSeconds is not at 0 (it will be 30)
        if (GameVariables::formalTimerSeconds != 0)
        {
            // if formalTimerMinutes is above its minimum (0:30 is lowest value the timer will go)
            if (GameVariables::formalTimerMinutes > 0) {
                GameVariables::formalTimerSeconds = 0;  // decrement 30 secs to 0 secs and update label
                timeLabel->setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                                   .arg(GameVariables::formalTimerSeconds, 2, 10, QChar('0')));
            }
        } else {
            // if formalTimerSeconds is at 0, take 30 seconds off, which will take minutes down by 1
            --GameVariables::formalTimerMinutes;
            GameVariables::formalTimerSeconds = 30;
            timeLabel->setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                               .arg(GameVariables::formalTimerSeconds, 2, 10, QChar(' ')));
        }
    }
}

void SetTimerButton::on_plusButton_clicked()
{

    if (buttonName == "Day") {
        ++GameVariables::dayTimerMinutes;
        timeLabel->setText(QString("%1:00").arg(GameVariables::dayTimerMinutes, 2, 10, QChar(' ')));

    } else {
        // if formalTimerSeconds is at 30, add 1 to minutes and reduce seconds back to 0, update label
        if (GameVariables::formalTimerSeconds != 0)
        {
            ++GameVariables::formalTimerMinutes;
            GameVariables::formalTimerSeconds = 0;
            timeLabel->setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                               .arg(GameVariables::formalTimerSeconds, 2, 10, QChar('0')));

        } else {
        // if formalTimerSeconds is at 0, just add 30 to seconds, update label

            GameVariables::formalTimerSeconds = 30;
            timeLabel->setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                               .arg(GameVariables::formalTimerSeconds, 2, 10, QChar('0')));
        }
    }

}

void SetTimerButton::on_okButton_clicked()
{
    timerDialog->close();
    if (buttonName == "Day")
        setText(QString("%1:00").arg(GameVariables::dayTimerMinutes, 2, 10, QChar(' ')));
    else
        setText(QString("%1:%2").arg(GameVariables::formalTimerMinutes, 2, 10, QChar(' '))
                                           .arg(GameVariables::formalTimerSeconds, 2, 10, QChar('0')));

}


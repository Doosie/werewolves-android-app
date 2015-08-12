#include "morningscreen.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

MorningScreen::MorningScreen(QFrame *parent) : QFrame(parent)
{
    // Label showing day number with button to restart (send to character screen) in same row
    dayLabel = new QLabel("<h1>Day n</h1>");
    restartButton = new QPushButton("Restart");
    restartButton->setFocusPolicy(Qt::NoFocus);

    // Sends user to info screen
    infoButton = new InfoButton;


    QHBoxLayout *dayLayout = new QHBoxLayout;
    dayLayout->addWidget(dayLabel);
    dayLayout->addStretch();
    dayLayout->addWidget(restartButton);
    dayLayout->addWidget(infoButton);

    morningInfoLabel = new QLabel("<i>The sun rises. Everybody wakes up and opens their eyes...<br>Everyone that is except for the one who was killed in the night.</i>");
    morningInfoLabel->setWordWrap(true);
    morningCharInfoLabel = new QLabel("Moderator do action if\ncertain role is in game");
    morningCharInfoLabel->setWordWrap(true);

    // Buttons for navigating to the last character of  the previous night phase, or start day phase
    prevButton = new QPushButton("Previous");
    prevButton->setFocusPolicy(Qt::NoFocus);
    startDayButton = new QPushButton("Start Day");
    startDayButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *navigBtnLayout = new QHBoxLayout;

    navigBtnLayout->addWidget(prevButton);
    navigBtnLayout->addStretch();
    navigBtnLayout->addWidget(startDayButton);

    QVBoxLayout *morningScreenLayout = new QVBoxLayout;
    morningScreenLayout->addLayout(dayLayout);
    morningScreenLayout->addWidget(morningInfoLabel);
    morningScreenLayout->addWidget(morningCharInfoLabel);
    morningScreenLayout->addLayout(navigBtnLayout);

    setLayout(morningScreenLayout);
}

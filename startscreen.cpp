#include "startscreen.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>

StartScreen::StartScreen(QFrame *parent) : QFrame(parent)
{

    // Sends user to info screen
    infoButton = new InfoButton;

    QHBoxLayout *infoLayout = new QHBoxLayout;
    infoLayout->addStretch();
    infoLayout->addWidget(infoButton);

    QLabel *titleLabel = new QLabel(QString("<h1>Werewolves</h1><h2>of</h2><h1>Miller's Hollow</h1>"));
    titleLabel->setWordWrap(true);
    titleLabel->setAlignment(Qt::AlignCenter);


    // Buttons to change the settings or change roles
    settingsButton = new QPushButton("Settings");
    settingsButton->setFocusPolicy(Qt::NoFocus);
    rolesButton = new QPushButton("Roles");
    rolesButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *settingsBtnLayout = new QHBoxLayout;
    settingsBtnLayout->addWidget(settingsButton);
    settingsBtnLayout->addStretch();
    settingsBtnLayout->addWidget(rolesButton);

    // Button to start game, constructs the userCharacters based on selections in settings and roles screens
    startButton = new QPushButton("Start Game");
    startButton->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *startScreenLayout = new QVBoxLayout;
    startScreenLayout->addLayout(infoLayout);
    startScreenLayout->addWidget(titleLabel);
    //startScreenLayout->addStretch();
    startScreenLayout->addLayout(settingsBtnLayout);
    startScreenLayout->addStretch();
    startScreenLayout->addWidget(startButton);

    setLayout(startScreenLayout);


}




void StartScreen::resizeEvent(QResizeEvent *)
{
    infoButton->move(width() - infoButton->width() - 10, 10);
}

#include "gameinfoscreen.h"

#include <QVBoxLayout>

GameInfoScreen::GameInfoScreen(QScrollArea *parent) : QScrollArea(parent)
{
    gameInfoLabel = new QLabel("Someone else write this please. :3");
    gameInfoLabel->setWordWrap(true);

    QVBoxLayout *gameInfoLayout = new QVBoxLayout;
    gameInfoLayout->addWidget(gameInfoLabel);
    setLayout(gameInfoLayout);
}


#include "nightscreen.h"
#include "characters.h"
#include "gamevariables.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

NightScreen::NightScreen(QFrame *parent) : QFrame(parent)
{
    // Label showing night number with button to restart (send to character screen) in same row
    nightLabel = new QLabel;

    restartButton = new QPushButton("Restart");
    restartButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *nightLayout = new QHBoxLayout;
    nightLayout->addWidget(nightLabel);
    nightLayout->addStretch();
    nightLayout->addWidget(restartButton);

    // Label displaying the name of the current character and label showing the information for that character
    charNameLabel = new QLabel("Character name");
    charInfoLabel = new QLabel("Character info\ninfo\n\nmore info");
    charInfoLabel->setWordWrap(true);

    // Buttons to navigate to previous page or next page
    prevButton = new QPushButton("Previous");
    prevButton->setFocusPolicy(Qt::NoFocus);
    nextButton = new QPushButton("Next");
    nextButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *navigBtnLayout = new QHBoxLayout;
    navigBtnLayout->addWidget(prevButton);
    navigBtnLayout->addStretch();
    navigBtnLayout->addWidget(nextButton);

    QVBoxLayout *nightScreenLayout = new QVBoxLayout;

    nightScreenLayout->addLayout(nightLayout);
    //nightScreenLayout->addWidget(charNameLabel);
    nightScreenLayout->addStretch();
    nightScreenLayout->addWidget(charInfoLabel);
    nightScreenLayout->addStretch();
    nightScreenLayout->addLayout(navigBtnLayout);

    setLayout(nightScreenLayout);

}

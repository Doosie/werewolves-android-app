#include "infoscreen.h"

#include <QVBoxLayout>
#include <QStyle>

InfoScreen::InfoScreen(QWidget *parent) : QFrame(parent)
{


    charInfoScreen = new CharInfoScreen;
    gameInfoScreen = new GameInfoScreen;

    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(charInfoScreen, "Characters");
    tabWidget->addTab(gameInfoScreen, "Gameplay");
    //tabWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    returnButton = new QPushButton("Return");
    returnButton->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *infoScreenLayout = new QVBoxLayout;
    infoScreenLayout->addWidget(tabWidget);
    infoScreenLayout->addWidget(returnButton);

    setLayout(infoScreenLayout);

}


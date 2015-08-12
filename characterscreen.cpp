#include "characterscreen.h"
#include "characters.h"

#include <QPushButton>

#include <QHBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
#include <QDebug>
#include <QScroller>

CharacterScreen::CharacterScreen(QFrame *parent) : QFrame(parent)
{

    //setStyleSheet(StyleSheets::charScreenStyle);

    vanillaChars = {
        {"Thief", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Cupido", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Fortune Teller", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Witch", ":/charactericons/characterIcons/sistersIcon.png"}
    };

    expansChars = {
        {"Two Sisters", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Three Brothers", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Stuttering Judge", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Wild Child", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Wolf Hound", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Big Bad Wolf", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Cursed Wolf-Father", ":/charactericons/characterIcons/sistersIcon.png"},
        {"White Werewolf", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Fox", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Actor", ":/charactericons/characterIcons/sistersIcon.png"},
        {"Bear Tamer", ":/charactericons/characterIcons/sistersIcon.png"}
    };

    // Title of the window
    QLabel *titleLabel = new QLabel("<h2>Choose Roles</h2>");
    infoButton = new InfoButton;

    QHBoxLayout *titleLayout = new QHBoxLayout;

    titleLayout->addWidget(titleLabel);
    titleLayout->addStretch();
    titleLayout->addWidget(infoButton);

    charButtonsLayout = new QVBoxLayout;

    createCharButtons(vanillaChars);
    QLabel *expansionLabel = new QLabel("Characters Expansion");
    charButtonsLayout->addWidget(expansionLabel);
    createCharButtons(expansChars);


    charButtons = new QWidget;
    charButtons->setLayout(charButtonsLayout);
    //charButtons->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored);
    //charButtonsLayout->setSpacing(5);
    scrollArea = new QScrollArea;
    //scrollArea->setLayout(charButtonsLayout);
    scrollArea->setWidget(charButtons);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QScroller::grabGesture(scrollArea, QScroller::LeftMouseButtonGesture);

    doneButton = new QPushButton("Done");
    doneButton->setFocusPolicy(Qt::NoFocus);


    // Full layout of the character Screen
    QVBoxLayout *charScreenLayout = new QVBoxLayout;
    charScreenLayout->addLayout(titleLayout);
    charScreenLayout->addWidget(scrollArea);
    charScreenLayout->addWidget(doneButton);

    setLayout(charScreenLayout);

    // Sends user to info screen




}


std::set<QString> CharacterScreen::checkedButtons()
{
    std::set<QString> checkedBtns;

    QList<CharacterButton *> allCharButtons = charButtons->findChildren<CharacterButton *>();

    for (int i = 0; i < allCharButtons.count(); ++i) {
        if (allCharButtons.at(i)->isChecked())
            checkedBtns.insert(allCharButtons.at(i)->text());
        //qDebug() << allCharButtons.at(i)->text();
    }

    return checkedBtns;
}

void CharacterScreen::createCharButtons(std::vector<std::pair<QString, QString>> &characters)
{
    for (auto charsIter = characters.begin();
         charsIter != characters.end(); ++charsIter) {
        //qDebug() << charsIter->first;
        CharacterButton *charButton = new CharacterButton(QIcon(charsIter->second), charsIter->first);
        charButtonsLayout->addWidget(charButton);

    }

}


void CharacterScreen::resizeEvent(QResizeEvent *)
{
    //infoButton->move(width() - infoButton->width() - 10, 10);
    charButtons->setFixedWidth(scrollArea->width() - 3);

}

bool CharacterScreen::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this->scrollArea->viewport()) {
        if (event->type() == QEvent::Wheel) {
            return true;
        } else {
            return false;
        }
    } else {
        return QWidget::eventFilter(obj, event);
    }
}

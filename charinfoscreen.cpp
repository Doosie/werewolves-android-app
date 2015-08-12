#include "charinfoscreen.h"
#include "characters.h"

#include <QScroller>


CharInfoScreen::CharInfoScreen(QScrollArea *parent) : QScrollArea(parent)
{

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    charInfoLayout = new QVBoxLayout;
    charInfoLayout->setSizeConstraint(QLayout::SetMinimumSize);


    startCharInfoConstruct();


    charInfo = new QWidget;

    charInfo->setLayout(charInfoLayout);

    setWidget(charInfo);

    QScroller::grabGesture(this, QScroller::LeftMouseButtonGesture);

}

bool CharInfoScreen::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this->viewport()) {
        if (event->type() == QEvent::Wheel) {
            return true;
        } else {
            return false;
        }
    } else {
        return QWidget::eventFilter(obj, event);
    }
}


void CharInfoScreen::startCharInfoConstruct()
{
    for (auto iter = Characters::helpVanillaCharInfo.begin();
         iter != Characters::helpVanillaCharInfo.end(); ++iter) {
        charInfoConstructHelper(iter->first, iter->second);
    }

    expansLabel = new QLabel("Characters Expansion");
    expansLabel->setAlignment(Qt::AlignHCenter);
    expansLabel->setObjectName("expansLabel");

    //expansLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    /*
    QFrame *seperator2 = new QFrame;
    seperator2->setFrameShape(QFrame::HLine);
    seperator2->setFrameShadow(QFrame::Raised);
    seperator2->setLineWidth(3);
    seperator2->setMidLineWidth(3);
    */
    charInfoLayout->addWidget(expansLabel);
    //charInfoLayout->addWidget(seperator2);

    for (auto iter = Characters::helpExpansCharInfo.begin();
         iter != Characters::helpExpansCharInfo.end(); ++iter) {
        charInfoConstructHelper(iter->first, iter->second);
    }
    charInfoLayout->addStretch();
}

void CharInfoScreen::dayCharInfoConstruct()
{

    for (auto iter = UserCharacters::userChars.begin();
         iter != UserCharacters::userChars.end(); ++iter) {
        charInfoConstructHelper(*iter, Characters::helpVanillaCharInfo[*iter]);
    }
    charInfoLayout->addStretch();

    QLabel *expansLabel = new QLabel("Characters expansion");

    QFrame *seperator2 = new QFrame;
    seperator2->setFrameShape(QFrame::HLine);
    seperator2->setFrameShadow(QFrame::Raised);
    seperator2->setLineWidth(3);
    seperator2->setMidLineWidth(3);

    charInfoLayout->addWidget(expansLabel);
    charInfoLayout->addWidget(seperator2);

    for (auto iter = UserCharacters::userChars.begin();
         iter != UserCharacters::userChars.end(); ++iter) {
        charInfoConstructHelper(*iter, Characters::helpExpansCharInfo[*iter]);
    }
    charInfoLayout->addStretch();

}


void CharInfoScreen::charInfoConstructHelper(const QString &name, const QString &info)
{
    QLabel *charNameLabel = new QLabel(name);
    //charNameLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    charNameLabel->setAlignment(Qt::AlignCenter);
    QLabel *charInfoLabel = new QLabel(info);
    charInfoLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    charInfoLabel->setWordWrap(true);
    //charInfoLabel->setMinimumWidth(230);
    charInfoLabel->setAlignment(Qt::AlignCenter);
    QFrame *seperator = new QFrame;
    seperator->setFrameShape(QFrame::HLine);
    charInfoLayout->addWidget(charNameLabel);
    charInfoLayout->addWidget(charInfoLabel);
    charInfoLayout->addWidget(seperator);
}

void CharInfoScreen::clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                delete widget;
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}

void CharInfoScreen::clearCharInfoLayout()
{
    clearLayout(charInfoLayout);
}


void CharInfoScreen::resizeEvent(QResizeEvent *)
{
    charInfo->setFixedWidth(width());

}


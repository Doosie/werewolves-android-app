#include "characterbutton.h"

#include <QStyleOption>
#include <QPainter>
#include <QString>

CharacterButton::CharacterButton(QIcon icon, QString text)
{
    setText(text);
    setIcon(icon);
    setCheckable(true);
    setMinimumHeight(45);
    setMinimumWidth(240);
    setMaximumWidth(620);
    //setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    setFocusPolicy(Qt::NoFocus);

}

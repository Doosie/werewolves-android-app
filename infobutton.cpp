#include "infobutton.h"



InfoButton::InfoButton(QWidget *parent) : QPushButton(parent)
{
    setParent(parent);
    setText("?");
    setFixedSize(80, 80);
    setFocusPolicy(Qt::NoFocus);

    //setStyleSheet("border-radius: 30px");
}


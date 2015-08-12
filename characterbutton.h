#ifndef CHARACTERBUTTON_H
#define CHARACTERBUTTON_H

#include <QString>
#include <QPushButton>

class CharacterButton : public QPushButton
{
    Q_OBJECT
public:
    CharacterButton(QIcon, QString);

private:
    //void paintEvent(QPaintEvent *);
};

#endif // CHARACTERBUTTON_H


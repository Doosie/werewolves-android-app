#ifndef INFOSCREEN_H
#define INFOSCREEN_H

#include "charinfoscreen.h"
#include "gameinfoscreen.h"

#include <QFrame>
#include <QTabWidget>
#include <QPushButton>

class InfoScreen : public QFrame
{
    Q_OBJECT
public:
    explicit InfoScreen(QWidget *parent = 0);

    CharInfoScreen *charInfoScreen;
    GameInfoScreen *gameInfoScreen;

    QPushButton *returnButton;

signals:

public slots:

private:

};

#endif // INFOSCREEN_H

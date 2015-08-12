#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "infobutton.h"

#include <QFrame>
#include <QPushButton>

class StartScreen : public QFrame
{
    Q_OBJECT
public:
    explicit StartScreen(QFrame *parent = 0);

    QPushButton *settingsButton;
    QPushButton *rolesButton;
    QPushButton *startButton;
    InfoButton *infoButton;
signals:

public slots:

private:


    void resizeEvent(QResizeEvent *);

    //void paintEvent(QPaintEvent *);

};

#endif // STARTSCREEN_H

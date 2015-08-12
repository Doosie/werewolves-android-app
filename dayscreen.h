#ifndef DAYSCREEN_H
#define DAYSCREEN_H

#include "infobutton.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMediaPlayer>
#include <QSoundEffect>

class DayScreen : public QFrame
{
    Q_OBJECT
public:
    explicit DayScreen(QWidget *parent = 0);

    QLabel *dayLabel;
    QPushButton *restartButton;
    InfoButton *infoButton;

    QPushButton *dayTimerButton;
    QLabel *dayTimerLabel;
    QTimer *dayTimer;

    QPushButton *formalTimerButton;
    QLabel *formalTimerLabel;
    QTimer *formalTimer;

    QPushButton *prevButton;
    QPushButton *nightButton;

    void resetTimers();
    void startDayTimer();


signals:

public slots:

private:

    uint daySeconds;
    uint dayMinutes;

    uint formalSeconds;
    uint formalMinutes;

    void updateDayTimer();


    void updateFormalTimer();
    void startFormalTimer();

    //QMediaPlayer *dayBell;
    QSoundEffect dayBellEffect;
    QSoundEffect formalBellEffect;

};

#endif // DAYSCREEN_H

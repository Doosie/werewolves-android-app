#ifndef GAMEVARIABLES_H
#define GAMEVARIABLES_H

#include <QTimer>

class GameVariables
{
public:
    GameVariables();

    static unsigned nightNumber;
    static unsigned dayNumber;

    static unsigned dayTimerMinutes;
    static unsigned formalTimerMinutes;
    static unsigned formalTimerSeconds;

    static bool pauseDay;
    //QTimer *timer = new QTimer;

};

#endif // GAMEVARIABLES_H

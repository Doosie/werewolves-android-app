#include "gamevariables.h"

GameVariables::GameVariables()
{

}

unsigned GameVariables::nightNumber = 0;
unsigned GameVariables::dayNumber = 0;

unsigned GameVariables::dayTimerMinutes = 10;
unsigned GameVariables::formalTimerMinutes = 1;
unsigned GameVariables::formalTimerSeconds = 0;

bool GameVariables::pauseDay = false;

#ifndef WEREWOLVES_H
#define WEREWOLVES_H

#include "characterscreen.h"
#include "nightscreen.h"
#include "dayscreen.h"
#include "startscreen.h"
#include "morningscreen.h"
#include "settingsscreen.h"
#include "infoscreen.h"
#include "resetdialog.h"

#include <QWidget>
#include <QStackedWidget>
#include <QMessageBox>
#include <QString>

#include <vector>

namespace Ui {
class Werewolves;
}

class Werewolves : public QWidget
{
    Q_OBJECT

public:
    explicit Werewolves(QWidget *parent = 0);
    ~Werewolves();


private:
    Ui::Werewolves *ui;

    QStackedWidget *stackedWidget;

    StartScreen *startScreen;
    SettingsScreen *settingsScreen;
    CharacterScreen *charScreen;
    NightScreen *nightScreen;
    MorningScreen *morningScreen;
    DayScreen *dayScreen;
    InfoScreen *infoScreen;

    ResetDialog *resetDialog;


    int prevScreen_infoScreen = 0;

    std::vector<QString>::iterator userCharsFirstNightIter;
    std::vector<QString>::iterator userCharsEveryNightIter;




    void on_startButton_clicked();          // StartScreen
    void on_settingsButton_clicked();       // StartScreen
    void on_rolesButton_clicked();          // StartScreen
    void on_infoButton_clicked();           // StartScreen, CharacterScreen, DayScreen, MorningScreen
    void on_charDoneButton_clicked();       // CharacterScreen
    void on_settDoneButton_clicked();       // SettingsScreen
    void on_restartButton_clicked();        // NightScreen, DayScreen
    void on_restartYesButton_clicked();     // ResetDialog
    void on_nextButton_clicked();           // NightScreen
    void on_nightPrevButton_clicked();      // NightScreen
    void on_morningPrevButton_clicked();    // MorningScreen
    void on_startDayButton_clicked();       // MorningScreen
    void on_dayPrevButton_clicked();        // DayScreen
    void on_nightButton_clicked();          // DayScreen
    void on_returnButton_clicked();         // InfoScreen

    void nightNextButtonHelper(std::vector<QString>::iterator&, const std::vector<QString>&);
    bool nightPrevButtonHelper(std::vector<QString>::iterator&, const std::vector<QString>&);

    void resetAll();
public slots:


};

#endif // WEREWOLVES_H

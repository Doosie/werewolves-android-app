#include "werewolves.h"
#include "ui_werewolves.h"
#include "characters.h"
#include "gamevariables.h"

#include <QVBoxLayout>
#include <QStackedWidget>
#include <QDebug>
#include <QFile>


Werewolves::Werewolves(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Werewolves)
{
    ui->setupUi(this);
    //setFixedSize(480, 320);
    //setMinimumSize(480, 320);
    //setMaximumSize(640, 400);




    //if (dpi < 220.) {



    /*
    } else {
        QFile styleFile(":/qss/highdpistyle.qss");
        styleFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleFile.readAll());
        a.setStyleSheet(styleSheet);
    }
    */


    setFixedSize(480, 800);
    setMinimumSize(480, 800);
    setMaximumSize(720, 1280);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setContentsMargins(0, 0, 0, 0);
    //showFullScreen();

    // define all the screens
    startScreen = new StartScreen;
    settingsScreen = new SettingsScreen;
    charScreen = new CharacterScreen;
    nightScreen = new NightScreen;
    morningScreen = new MorningScreen;
    dayScreen = new DayScreen;
    infoScreen = new InfoScreen;

    startScreen->setObjectName(QString("startScreen"));

    resetDialog = new ResetDialog(this);



    // stackedWidget holds all the pages that can be displayed
    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(startScreen);
    stackedWidget->addWidget(settingsScreen);
    stackedWidget->addWidget(charScreen);
    stackedWidget->addWidget(nightScreen);
    stackedWidget->addWidget(morningScreen);
    stackedWidget->addWidget(dayScreen);
    stackedWidget->addWidget(infoScreen);



    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(stackedWidget);
    setLayout(layout);


    // Connections for buttons on every screen

    // StartScreen
    connect(startScreen->startButton, &QPushButton::clicked,
            this, &Werewolves::on_startButton_clicked);
    connect(startScreen->rolesButton, &QPushButton::clicked,
            this, &Werewolves::on_rolesButton_clicked);
    connect(startScreen->settingsButton, &QPushButton::clicked,
            this, &Werewolves::on_settingsButton_clicked);
    connect(startScreen->infoButton, &QPushButton::clicked,
            this, &Werewolves::on_infoButton_clicked);

    // SettingsScreen
    connect(settingsScreen->doneButton, &QPushButton::clicked,
            this, &Werewolves::on_settDoneButton_clicked);

    // CharacterScreen
    connect(charScreen->doneButton, &QPushButton::clicked,
            this, &Werewolves::on_charDoneButton_clicked);
    connect(charScreen->infoButton, &QPushButton::clicked,
            this, &Werewolves::on_infoButton_clicked);

    // NightScreen
    connect(nightScreen->restartButton, &QPushButton::clicked,
            this, &Werewolves::on_restartButton_clicked);
    connect(nightScreen->nextButton, &QPushButton::clicked,
            this, &Werewolves::on_nextButton_clicked);
    connect(nightScreen->prevButton, &QPushButton::clicked,
            this, &Werewolves::on_nightPrevButton_clicked);

    // MorningScreen
    connect(morningScreen->prevButton, &QPushButton::clicked,
            this, &Werewolves::on_morningPrevButton_clicked);
    connect(morningScreen->startDayButton, &QPushButton::clicked,
            this, &Werewolves::on_startDayButton_clicked);
    connect(morningScreen->restartButton, &QPushButton::clicked,
            this, &Werewolves::on_restartButton_clicked);
    connect(morningScreen->infoButton, &QPushButton::clicked,
            this, &Werewolves::on_infoButton_clicked);

    // DayScreen
    connect(dayScreen->restartButton, &QPushButton::clicked,
            this, &Werewolves::on_restartButton_clicked);
    connect(dayScreen->prevButton, &QPushButton::clicked,
            this, &Werewolves::on_dayPrevButton_clicked);
    connect(dayScreen->nightButton, &QPushButton::clicked,
            this, &Werewolves::on_nightButton_clicked);
    connect(dayScreen->infoButton, &QPushButton::clicked,
            this, &Werewolves::on_infoButton_clicked);

    // InfoScreen
    connect(infoScreen->returnButton, &QPushButton::clicked,
            this, &Werewolves::on_returnButton_clicked);

    // ResetDialog
    connect(resetDialog->yesButton, &QPushButton::clicked,
            this, &Werewolves::on_restartYesButton_clicked);


}

Werewolves::~Werewolves()
{
    delete ui;
}

// StartScreen
void Werewolves::on_startButton_clicked()
{
    // initialize night and day numbers to 1
    GameVariables::nightNumber = 1;
    GameVariables::dayNumber = 1;

    dayScreen->resetTimers();

    // change the night number label on the night screen
    nightScreen->nightLabel->setText(QString("<h1>Night %1").arg(GameVariables::nightNumber));

    // construct the vectors of user chars from the checked buttons in the character screen
    Characters::constructUserChars(charScreen->checkedButtons());

    // set the iterators for the vectors
    userCharsFirstNightIter = UserCharacters::userCharsFirstNight.begin();
    //userCharsEveryNightIter = UserCharacters::userCharsEveryNight.begin();

    // if the Bear Tamer is in the game, change the morning character info.
    if (*userCharsFirstNightIter == "Bear Tamer") {
        morningScreen->morningCharInfoLabel->setText(Characters::nightCharInfo[*userCharsFirstNightIter]);
        userCharsFirstNightIter = UserCharacters::userCharsFirstNight.erase(userCharsFirstNightIter);
    }
    else {
        morningScreen->morningCharInfoLabel->setText("");
    }


    nightScreen->charNameLabel->setText(*userCharsFirstNightIter);
    nightScreen->charInfoLabel->setText(Characters::nightCharInfo[*userCharsFirstNightIter]);

    // when startButton is pressed, changes the displayed page in stackedWidget to the nightScreen
    stackedWidget->setCurrentIndex(3);
}

// StartScreen
void Werewolves::on_settingsButton_clicked()
{
    // when settingsButton is clicked, changes the displayed page in stackedWidget to the settingsScreen
    stackedWidget->setCurrentIndex(1);
}

// StartScreen
void Werewolves::on_rolesButton_clicked()
{
    // when rolesButton is clicked, change the displayed page in stackedWidget to the charScreen
    stackedWidget->setCurrentIndex(2);
}

// StartScreen, CharacterScreen, DayScreen(todo)
void Werewolves::on_infoButton_clicked()
{




    // if currentWidget is StartScreen or CharacterScreen and charInfoScreen last updated from DayScreen or MorningScreen
    /*
    if (prevScreen_infoScreen > 3 && stackedWidget->currentIndex() < 3) {
        // change charInfoScreen to display all the characters
        infoScreen->charInfoScreen->clearCharInfoLayout();
        infoScreen->charInfoScreen->startCharInfoConstruct();
    }

    // if currentWidget is DayScreen or MorningScreen and charInfoScreen last updated from StartScreen or CharacterSCreen
    if (prevScreen_infoScreen < 3 && stackedWidget->currentIndex() > 3) {
        // change charInfoScreen to display the user selected characters or all if on startScreen or charScreen
        infoScreen->charInfoScreen->clearCharInfoLayout();
        infoScreen->charInfoScreen->dayCharInfoConstruct();

    }
    */
    prevScreen_infoScreen = stackedWidget->currentIndex();

    // change displayed page to infoScreen
    stackedWidget->setCurrentIndex(6);
}

// SettingsScreen
void Werewolves::on_settDoneButton_clicked()
{
    // when doneButton is clicked, change displayed page to startScreen
    GameVariables::pauseDay = settingsScreen->pauseDayCheckBox->isChecked();
    stackedWidget->setCurrentIndex(0);
}

// CharacterScreen
void Werewolves::on_charDoneButton_clicked()
{
    // when doneButton is clicked, change displayed page to startScreen

    stackedWidget->setCurrentIndex(0);
}

// NightScreen, DayScreen
void Werewolves::on_restartButton_clicked()
{
    // when restartButton is clicked, change the displayed page in stackedWidget to the startScreen

    resetDialog->show();

    QPoint pos = mapToGlobal(QPoint( width()/2  - resetDialog->width()/2,
                                     height()/2 - resetDialog->height()/2 ));
    resetDialog->move( pos );
    
}

void Werewolves::on_restartYesButton_clicked()
{
    resetDialog->close();
    stackedWidget->setCurrentIndex(0);

    resetAll();
}

// NightScreen
void Werewolves::on_nextButton_clicked()
{
    // if the first night
    if (GameVariables::nightNumber == 1)
        nightNextButtonHelper(userCharsFirstNightIter, UserCharacters::userCharsFirstNight);
    else
        nightNextButtonHelper(userCharsEveryNightIter, UserCharacters::userCharsEveryNight);
}

void Werewolves::nightNextButtonHelper(std::vector<QString>::iterator &userCharsNightIter,
                                  const std::vector<QString> &userCharsNight)
{
    // if there are still characters that need to do their action
    ++userCharsNightIter;
    if (userCharsNightIter != userCharsNight.end())
    {
        // white werewolf only wakes up every second night
        if (*userCharsNightIter == "White Werewolf" && GameVariables::nightNumber % 2)
            ++userCharsNightIter;
        // change the labels of the character name and info to the next character
        nightScreen->charNameLabel->setText(*userCharsNightIter);
        nightScreen->charInfoLabel->setText(Characters::nightCharInfo[*userCharsNightIter]);
    }
    else
    {
        // change displayed page to MorningScreen
        morningScreen->dayLabel->setText(QString("<h1>Day %1</h1>").arg(GameVariables::nightNumber));

        stackedWidget->setCurrentIndex(4);
    }
}

// NightScreen
void Werewolves::on_nightPrevButton_clicked()
{
    // if the first night
    if (GameVariables::nightNumber == 1)
    {
        // if at the first character
        if (nightPrevButtonHelper(userCharsFirstNightIter, UserCharacters::userCharsFirstNight)) {
            // change the displayed page to StartScreen then reset variables
            stackedWidget->setCurrentIndex(0);
            resetAll();
        }
    }
    else
    {
        // if at the first character
        if (nightPrevButtonHelper(userCharsEveryNightIter, UserCharacters::userCharsEveryNight))
        {
            // change the displayed page to DayScreen and change the GameVariables to the previous night

            --GameVariables::nightNumber;
            --GameVariables::dayNumber;
            morningScreen->dayLabel->setText(QString("<h1>Day %1</h1>").arg(GameVariables::nightNumber));
            dayScreen->dayLabel->setText(QString("<h1>Day %1</h1>").arg(GameVariables::nightNumber));

            // change displayed page to dayScreen then start the day timer
            stackedWidget->setCurrentIndex(5);
            dayScreen->startDayTimer();
        }
    }
}

bool Werewolves::nightPrevButtonHelper(std::vector<QString>::iterator &userCharsNightIter,
                                       const std::vector<QString> &userCharsNight)
{

    bool ret = true;
    // if not already at the first character
    if (userCharsNightIter != userCharsNight.begin())
    {
        ret = false;

        // change the labels of the character name and info to the previous character
        --userCharsNightIter;

        if (*userCharsNightIter == "White Werewolf" && GameVariables::nightNumber % 2)
            --userCharsNightIter;

        nightScreen->charNameLabel->setText(*userCharsNightIter);
        nightScreen->charInfoLabel->setText(Characters::nightCharInfo[*userCharsNightIter]);
    }

    return ret;
}

// MorningScreen
void Werewolves::on_morningPrevButton_clicked()
{
    if (GameVariables::nightNumber == 1)
    {
        --userCharsFirstNightIter;
        nightScreen->nightLabel->setText(QString("<h1>First Night</h1>"));
    }
    else
    {
        userCharsEveryNightIter = UserCharacters::userCharsEveryNight.end() -1;
        nightScreen->nightLabel->setText(QString("<h1>Night %1").arg(GameVariables::nightNumber));
    }
    // change displayed page to nightScreen
    stackedWidget->setCurrentIndex(3);
}

// MorningScreen
void Werewolves::on_startDayButton_clicked()
{
    dayScreen->dayLabel->setText(QString("<h1>Day %1</h1>").arg(GameVariables::nightNumber));
    //dayScreen->resetTimers();

    // change displayed page to DayScreen
    stackedWidget->setCurrentIndex(5);
    dayScreen->startDayTimer();
}

// DayScreen
void Werewolves::on_dayPrevButton_clicked()
{
    dayScreen->resetTimers();
    stackedWidget->setCurrentIndex(4);
}

// DayScreen
void Werewolves::on_nightButton_clicked()
{
    // stop and reset timers if they're still running
    dayScreen->resetTimers();

    // go to the new day and night
    ++GameVariables::nightNumber;
    ++GameVariables::dayNumber;

    // update nightLabel to show new night number
    nightScreen->nightLabel->setText(QString("<h1>Night %1").arg(GameVariables::nightNumber));

    // reset the iterator for the user characters
    userCharsEveryNightIter = UserCharacters::userCharsEveryNight.begin();

    // update the text for the character name and info
    nightScreen->charNameLabel->setText(*userCharsEveryNightIter);
    nightScreen->charInfoLabel->setText(Characters::nightCharInfo[*userCharsEveryNightIter]);

    // change displayed page to NightScreen
    stackedWidget->setCurrentIndex(3);
}

void Werewolves::on_returnButton_clicked()
{
    // change displayed page to the page viewed before changing to infoScreen
    stackedWidget->setCurrentIndex(prevScreen_infoScreen);
}



// resets all values to their initial values
void Werewolves::resetAll()
{
    dayScreen->resetTimers();
    UserCharacters::userCharsFirstNight.clear();
    UserCharacters::userCharsEveryNight.clear();
    GameVariables::nightNumber = 1;
    GameVariables::dayNumber = 1;
    prevScreen_infoScreen = 0;
}


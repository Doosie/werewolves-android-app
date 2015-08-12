#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include "settimerbutton.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

class SettingsScreen : public QFrame
{
    Q_OBJECT
public:
    explicit SettingsScreen(QFrame *parent = 0);

    QPushButton *doneButton;

    QCheckBox *pauseDayCheckBox;

signals:

public slots:

private:



    QLabel *titleLabel;


    SetTimerButton *dayTimerButton;
    SetTimerButton *formalTimerButton;

    QLabel *pauseDayLabel;

    void showDayDialog();
    void showFormalDialog();
};

#endif // SETTINGSSCREEN_H

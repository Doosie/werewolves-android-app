#ifndef SETTIMERBUTTON_H
#define SETTIMERBUTTON_H


#include <QPushButton>
#include <QDialog>
#include <QLabel>

class SetTimerButton : public QPushButton
{
public:
    explicit SetTimerButton(QString, QWidget *parent = 0);

    QDialog *timerDialog;

private:
    QString buttonName;



    QLabel *timeLabel;
    QPushButton *plusButton;
    QPushButton *minusButton;

    QPushButton *okButton;

    unsigned *timerMinutes;

    void on_minusButton_clicked();
    void on_plusButton_clicked();
    void on_okButton_clicked();
};

#endif // SETTIMERBUTTON_H

#ifndef RESETDIALOG_H
#define RESETDIALOG_H

#include <QDialog>
#include <QPushButton>

class ResetDialog : public QDialog
{
public:
    explicit ResetDialog(QWidget *parent = 0);

    QPushButton *yesButton;

protected:
    //void resizeEvent(QResizeEvent *);

private:

    QPushButton *noButton;


};

#endif // RESETDIALOG_H

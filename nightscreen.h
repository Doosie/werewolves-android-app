#ifndef NIGHTSCREEN_H
#define NIGHTSCREEN_H

#include <QFrame>
#include <QPushButton>
#include <QLabel>

class NightScreen : public QFrame
{
    Q_OBJECT
public:
    explicit NightScreen(QFrame *parent = 0);

    QPushButton *restartButton;
    QPushButton *nextButton;
    QPushButton *prevButton;

    QLabel *nightLabel;

    QLabel *charNameLabel;
    QLabel *charInfoLabel;

signals:

public slots:

private:

};

#endif // NIGHTSCREEN_H

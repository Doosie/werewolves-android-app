#ifndef MORNINGSCREEN_H
#define MORNINGSCREEN_H

#include "infobutton.h"

#include <QFrame>
#include <QPushButton>
#include <QLabel>

class MorningScreen : public QFrame
{
    Q_OBJECT
public:
    explicit MorningScreen(QFrame *parent = 0);

    QLabel *dayLabel;
    QPushButton *restartButton;
    InfoButton *infoButton;

    QLabel *morningInfoLabel;
    QLabel *morningCharInfoLabel;

    QPushButton *prevButton;
    QPushButton *startDayButton;
signals:

public slots:
};

#endif // MORNINGSCREEN_H

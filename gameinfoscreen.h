#ifndef GAMEINFOSCREEN_H
#define GAMEINFOSCREEN_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>

class GameInfoScreen : public QScrollArea
{
    Q_OBJECT
public:
    explicit GameInfoScreen(QScrollArea *parent = 0);

signals:

public slots:

private:
    QLabel *gameInfoLabel;

};

#endif // GAMEINFOSCREEN_H

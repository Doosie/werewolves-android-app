#ifndef CHARACTERSCREEN_H
#define CHARACTERSCREEN_H

#include "characterbutton.h"
#include "infobutton.h"

#include <vector>
#include <QFrame>
#include <QPushButton>
#include <QString>
#include <set>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QEvent>
//#include <QIcon>

class CharacterScreen : public QFrame
{
    Q_OBJECT
public:
    explicit CharacterScreen(QFrame *parent = 0);
    QPushButton *doneButton;
    InfoButton *infoButton;

    std::set<QString> checkedButtons();

protected:
    void resizeEvent(QResizeEvent *);
    bool eventFilter(QObject *, QEvent *);

signals:

public slots:

private:

    void createCharButtons(std::vector<std::pair<QString, QString>> &);

    QVBoxLayout *charButtonsLayout;

    QWidget *charButtons;
    QScrollArea *scrollArea;



    std::vector<std::pair<QString, QString>> vanillaChars;

    std::vector<std::pair<QString, QString>> expansChars;




};

#endif // CHARACTERSCREEN_H

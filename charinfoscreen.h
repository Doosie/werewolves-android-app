#ifndef CHARINFOSCREEN_H
#define CHARINFOSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QEvent>

class CharInfoScreen : public QScrollArea
{
    Q_OBJECT
public:
    explicit CharInfoScreen(QScrollArea *parent = 0);

    void dayCharInfoConstruct();
    void startCharInfoConstruct();

    void clearCharInfoLayout();

protected:
    bool eventFilter(QObject *, QEvent *);
signals:

public slots:

private:

    QVBoxLayout *charInfoLayout;

    QWidget *charInfo;
    QLabel *expansLabel;

    void charInfoConstructHelper(const QString &name, const QString &info);
    void clearLayout(QLayout*, bool);

    void resizeEvent(QResizeEvent *);


    //QLabel *character;
};

#endif // CHARINFOSCREEN_H

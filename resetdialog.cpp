#include "resetdialog.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

ResetDialog::ResetDialog(QWidget *parent) : QDialog(parent)
{
    setModal(true);

    QLabel *questionLabel = new QLabel("Are you sure you want to restart?");
    questionLabel->setWordWrap(true);

    yesButton = new QPushButton("Yes");
    yesButton->setFocusPolicy(Qt::NoFocus);
    noButton = new QPushButton("No");
    noButton->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(yesButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(noButton);

    QVBoxLayout *dialogLayout = new QVBoxLayout;
    dialogLayout->addWidget(questionLabel);
    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);

    connect(noButton, &QPushButton::clicked, this, &QDialog::close);
}


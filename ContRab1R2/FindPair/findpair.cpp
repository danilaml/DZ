#include <QLayout>
#include <QtTest/QTest>
#include <QMessageBox>
#include <cstdlib>

#include "findpair.h"
#include "ui_findpair.h"
#include "sizedialog.h"

FindPair::FindPair(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPair),
    qsm(new QSignalMapper(this)),
    lastButton(-1),
    done(0),
    isCompleted(true)
{
    ui->setupUi(this);

    SizeDialog *sd = new SizeDialog(this);
    boardSize = sd->exec();
    state = QVector<QVector<int> >(boardSize, QVector<int>(boardSize));
    buttons = QVector<QPushButton*>(boardSize * boardSize);

    int zeros = 0;

    QGridLayout *mainLayout = new QGridLayout();
    for (int i = 0; i < boardSize * boardSize; i++)
    {
        state[i % boardSize][i / boardSize] = (i == boardSize * boardSize - 1) ? ((zeros + 1) % 2) : (std::rand() % 2);
        if (state[i % boardSize][i / boardSize] == 0)
            zeros++;
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;

        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % boardSize, i / boardSize);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(stateChanged(int)));

    setLayout(mainLayout);

}

FindPair::~FindPair()
{
    delete ui;
}

void FindPair::stateChanged(int buttonPressed)
{
    if (!isCompleted)
        return;
    isCompleted = false;
    int buttonPressedNum = state[buttonPressed % boardSize][buttonPressed / boardSize];
    buttons[buttonPressed]->setText(QString::number(buttonPressedNum));
    buttons[buttonPressed]->setEnabled(false);
    if (lastButton == -1)
    {
        lastButton = buttonPressed;
    }
    else
    {
        int lastPressedNum = state[lastButton % boardSize][lastButton / boardSize];
        if (lastPressedNum == buttonPressedNum)
        {
            disconnect(buttons[buttonPressed], SIGNAL(clicked()), qsm, SLOT(map()));
            disconnect(buttons[lastButton], SIGNAL(clicked()), qsm, SLOT(map()));
            done += 2;
            if(done == boardSize * boardSize)
            {
                showMsgBox("Congratulations!", "You are the winner!");
                close();
            }
        }
        else
        {
            QTest::qWait(1000);

            buttons[buttonPressed]->setText(" ");
            buttons[buttonPressed]->setEnabled(true);
            buttons[lastButton]->setText(" ");
            buttons[lastButton]->setEnabled(true);
        }
        lastButton = -1;
    }
    isCompleted = true;
}

void FindPair::showMsgBox(const QString &title, const QString &text)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

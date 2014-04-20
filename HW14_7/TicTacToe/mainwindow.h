#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void boardSizeChanged(int sz);

private slots:
    void turnChanged(int turn);
    void changeBoardSize();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

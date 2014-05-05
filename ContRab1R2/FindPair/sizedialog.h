#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>

namespace Ui {
class SizeDialog;
}

/// Dialog for changing size of the board
class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QWidget *parent = 0);
    ~SizeDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SizeDialog *ui;
};

#endif // SIZEDIALOG_H

#include "sizedialog.h"
#include "ui_sizedialog.h"

SizeDialog::SizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeDialog)
{
    ui->setupUi(this);
}

SizeDialog::~SizeDialog()
{
    delete ui;
}

void SizeDialog::on_buttonBox_accepted()
{
    setResult(ui->spinBox->value());
}

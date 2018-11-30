#include "contractdetailsdialog.h"
#include "ui_contractdetailsdialog.h"

ContractDetailsDialog::ContractDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContractDetailsDialog)
{
    ui->setupUi(this);
}

ContractDetailsDialog::~ContractDetailsDialog()
{
    delete ui;
}

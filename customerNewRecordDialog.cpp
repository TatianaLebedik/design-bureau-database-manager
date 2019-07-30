#include "customerNewRecordDialog.h"
#include "ui_customernewrecorddialog.h"

CustomerNewRecordDialog::CustomerNewRecordDialog(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerNewRecordDialog)
{
    ui->setupUi(this);
    this->db = db;
}

CustomerNewRecordDialog::~CustomerNewRecordDialog()
{
    delete ui;
}

void CustomerNewRecordDialog::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("insert into customers(head_name, adress, checking_account, telephone) values (:head_name, :adress, :checking_account, :telephone)");
    query->bindValue(":head_name", ui->customer_head_name_lineEdit->text());
    query->bindValue(":adress", ui->customer_address_lineEdit->text());
    query->bindValue(":checking_account",  ui->customer_checking_account_lineEdit->text());
    query->bindValue(":telephone", ui->customer_telephone_ineEdit->text());
    query->exec();
}

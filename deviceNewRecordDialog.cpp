#include "deviceNewRecordDialog.h"
#include "ui_devicenewrecorddialog.h"

DeviceNewRecordDialog::DeviceNewRecordDialog(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceNewRecordDialog)
{
    ui->setupUi(this);
    this->db = db;
}

DeviceNewRecordDialog::~DeviceNewRecordDialog()
{
    delete ui;
}

void DeviceNewRecordDialog::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("insert into devices(code, name, price) values (:code, :name, :price)");
    query->bindValue(":code", ui->device_code_lineEdit->text());
    query->bindValue(":name", ui->device_name_lineEdit->text());
    query->bindValue(":price",  ui->device_price_spinBox->value());
    query->exec();
}

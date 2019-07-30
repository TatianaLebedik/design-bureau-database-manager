#include "employeeNewRecordDialog.h"
#include "ui_employeenewrecorddialog.h"

EmployeeNewRecordDialog::EmployeeNewRecordDialog(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeNewRecordDialog)
{
    ui->setupUi(this);
    this->db = db;
}

EmployeeNewRecordDialog::~EmployeeNewRecordDialog()
{
    delete ui;
}

void EmployeeNewRecordDialog::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("insert into employees(code, name) values (:code, :name)");
    query->bindValue(":code", ui->employee_code_lineEdit->text());
    query->bindValue(":name", ui->employee_name_lineEdit->text());
    query->exec();

}

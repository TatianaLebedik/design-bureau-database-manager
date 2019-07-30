#include "positionNewRecordDialog.h"
#include "ui_positionnewrecorddialog.h"

PositionNewRecordDialog::PositionNewRecordDialog(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositionNewRecordDialog)
{
    ui->setupUi(this);
    this->db = db;
}

PositionNewRecordDialog::~PositionNewRecordDialog()
{
    delete ui;
}

void PositionNewRecordDialog::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("insert into positions(code, pos_name) values (:code, :pos_name)");
    query->bindValue(":code", ui->position_code_lineEdit->text());
    query->bindValue(":pos_name", ui->position_name_lineEdit->text());
    query->exec();

}

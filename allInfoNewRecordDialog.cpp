#include "allinfonewrecorddialog.h"
#include "ui_allinfonewrecorddialog.h"

AllInfoNewRecordDialog::AllInfoNewRecordDialog(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllInfoNewRecordDialog)
{
    ui->setupUi(this);
    this->db = db;
    QSqlQueryModel *customer_head_name_combo_box_model = new QSqlQueryModel();
    QSqlQuery *customer_head_name_combo_box_query = new QSqlQuery(db);
    customer_head_name_combo_box_query->prepare("select head_name from customers;");
    customer_head_name_combo_box_query->exec();
    customer_head_name_combo_box_model->setQuery(*customer_head_name_combo_box_query);
    ui->customer_head_name_comboBox->setModel(customer_head_name_combo_box_model);

    QSqlQueryModel *device_name_combo_box_model = new QSqlQueryModel();
    QSqlQuery *device_name_combo_box_query = new QSqlQuery(db);
    device_name_combo_box_query->prepare("select name from devices;");
    device_name_combo_box_query->exec();
    device_name_combo_box_model->setQuery(*device_name_combo_box_query);
    ui->device_name_comboBox->setModel(device_name_combo_box_model);
}

AllInfoNewRecordDialog::~AllInfoNewRecordDialog()
{
    delete ui;
}

void AllInfoNewRecordDialog::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT code FROM devices WHERE name = :name;");
    query->bindValue(":name", ui->device_name_comboBox->currentText());
    query->exec();
    query->first();
    QString device_code = query->value(0).toString();
    query->clear();
    query->prepare("SELECT checking_account FROM customers WHERE head_name = :head_name;");
    query->bindValue(":head_name", ui->customer_head_name_comboBox->currentText());
    query->exec();
    query->first();
    QString customer_checking_account = query->value(0).toString();
    query->clear();

    query->prepare("insert into contracts(contract_number, device_code, amount, customer_id, start_day, deadline_day) values (:contract_number, :device_code, :amount, :customer_id, :start_day, :deadline_day)");

    query->bindValue(":contract_number", ui->contracts_number_spinBox->value());
    query->bindValue(":device_code", device_code);
    query->bindValue(":amount",  ui->device_amount_spinBox->value());
    query->bindValue(":customer_id", customer_checking_account);
    query->bindValue(":start_day",  ui->date_of_the_agreement_dateEdit->text());
    query->bindValue(":deadline_day", ui->deadline_dateEdit->text());
    query->exec();

}

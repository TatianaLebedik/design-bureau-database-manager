#include "contractDetailsDialog.h"
#include "ui_contractdetailsdialog.h"

ContractDetailsDialog::ContractDetailsDialog(QSqlDatabase db, int current_contract_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContractDetailsDialog)
{
    ui->setupUi(this);
    QSqlQuery *query = new QSqlQuery(db);

    query->prepare("select device_code from contracts where contract_number = :contract_number;");
    query->bindValue(":contract_number", current_contract_number);
    query->exec();
    query->first();
    QString device_code = query->value(0).toString();
    query->clear();

    query->prepare("select name from devices where code = :code;");
    query->bindValue(":code", device_code);
    query->exec();
    query->first();
    QString device_name = query->value(0).toString();

    ui->device_name_label->setText(device_name);

    query->prepare("select price from devices where code = :device_code;");
    query->bindValue(":device_code", device_code);
    query->exec();
    query->first();
    int price = query->value(0).toInt();
    ui->price_for_one_label->setText(QString::number(price));
    query->clear();

    query->prepare("select amount from contracts where contract_number = :contract_number;");
    query->bindValue(":contract_number", current_contract_number);
    query->exec();
    query->first();
    int amount = query->value(0).toInt();
    ui->amount_label->setText(QString::number(amount));

    ui->total_price_label->setText(QString::number(amount*price));

    QString contract_number;
    contract_number.append("Contract ");
    contract_number.append(QString::number(current_contract_number));
    ui->contract_label->setText(contract_number);
    query->clear();

    query->prepare("select customer_id from contracts where contract_number = :contract_number;");
    query->bindValue(":contract_number", current_contract_number);
    query->exec();
    query->first();
    QString checking_account = query->value(0).toString();
    ui->checking_account_label->setText(checking_account);

    query->prepare("select head_name from customers where checking_account = :checking_account;");
    query->bindValue(":checking_account", checking_account);
    query->exec();
    query->first();
    QString head_name = query->value(0).toString();
    ui->customers_head_neme_label->setText(head_name);

    query->prepare("select telephone from customers where checking_account = :checking_account;");
    query->bindValue(":checking_account", checking_account);
    query->exec();
    query->first();
    QString telephone = query->value(0).toString();
    ui->telephone_label->setText(telephone);

    query->prepare("select deadline_day from contracts where contract_number = :contract_number;");
    query->bindValue(":contract_number", current_contract_number);
    query->exec();
    query->first();
    QString deadline = query->value(0).toString();
    ui->deadline_day_label->setText(deadline);

    QSqlQueryModel *team_combo_box_model = new QSqlQueryModel();
    QSqlQuery *team_combo_box_query = new QSqlQuery(db);
    team_combo_box_query->prepare("select name from team_members where team_id = :team_id;");
    team_combo_box_query->bindValue(":team_id", current_contract_number);
    team_combo_box_query->exec();
    team_combo_box_model->setQuery(*team_combo_box_query);
    ui->team_comboBox->setModel(team_combo_box_model);

}

ContractDetailsDialog::~ContractDetailsDialog()
{
    delete ui;
}

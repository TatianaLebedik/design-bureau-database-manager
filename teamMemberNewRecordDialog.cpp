#include "teammembernewrecorddialog.h"
#include "ui_teammembernewrecorddialog.h"

TeamMemberNewRecordDialog::TeamMemberNewRecordDialog(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamMemberNewRecordDialog)
{
    ui->setupUi(this);
    this->db = db;
    QSqlQueryModel *employee_combo_box_model = new QSqlQueryModel();
    QSqlQuery *employee_combo_box_query = new QSqlQuery(db);
    employee_combo_box_query ->prepare("select name from employees;");
    employee_combo_box_query ->exec();
    employee_combo_box_model->setQuery(*employee_combo_box_query);
    ui->team_employee_comboBox->setModel(employee_combo_box_model);

    QSqlQueryModel *positions_combo_box_model = new QSqlQueryModel();
    QSqlQuery *positions_combo_box_query = new QSqlQuery(db);
    positions_combo_box_query->prepare("select pos_name from positions;");
    positions_combo_box_query->exec();
    positions_combo_box_model->setQuery(*positions_combo_box_query);
    ui->team_position_comboBox->setModel(positions_combo_box_model);

    QSqlQueryModel *project_number_combo_box_model = new QSqlQueryModel();
    QSqlQuery *project_number_combo_box_query = new QSqlQuery(db);
    project_number_combo_box_query->prepare("select contract_number from contracts;");
    project_number_combo_box_query->exec();
    project_number_combo_box_model->setQuery(*project_number_combo_box_query);
    ui->team_project_number_comboBox->setModel(project_number_combo_box_model);
}

TeamMemberNewRecordDialog::~TeamMemberNewRecordDialog()
{
    delete ui;
}

void TeamMemberNewRecordDialog::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("SELECT code FROM employees WHERE name = :name;");
    query->bindValue(":name", ui->team_employee_comboBox->currentText());
    query->exec();
    query->first();
    QString employee_code = query->value(0).toString();
    query->clear();

    query->prepare("SELECT code FROM positions WHERE pos_name = :pos_name;");
    query->bindValue(":pos_name", ui->team_position_comboBox->currentText());
    query->exec();
    query->first();
    QString position_code = query->value(0).toString();
    query->clear();

    query->prepare("insert into creative_teams(employee_id, position_id, team_id) values (:employee_id, :position_id, :team_id);");

    query->bindValue(":employee_id", employee_code);
    query->bindValue(":position_id", position_code);
    query->bindValue(":team_id", ui->team_project_number_comboBox->currentText().toInt());
    qDebug() << employee_code;
    qDebug() << position_code;
    qDebug() << ui->team_project_number_comboBox->currentText().toInt();

    query->exec();
}

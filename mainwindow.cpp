#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QSqlDatabase db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->db = db;
    ui->setupUi(this);
        //default table is contracts
    on_actionContracts_triggered();

    connect(this, &MainWindow::signal_from_navigation_button,this, &MainWindow::set_navigation_mapper);
}


MainWindow::~MainWindow()
{
    delete ui;
}


//menu
void MainWindow::on_actionContracts_triggered()
{
       ui->tableView->setModel(contract_model());
       ui->tableView->selectRow(0);
       mapper->toFirst();
       ui->tableView->resizeColumnsToContents();
       ui->tableView->show();
}
void MainWindow::on_actionCustomers_triggered()
{
    ui->tableView->setModel(customer_model());
    ui->tableView->selectRow(0);
    mapper->toFirst();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
void MainWindow::on_actionDevices_triggered()
{
    ui->tableView->setModel(device_model());
    ui->tableView->selectRow(0);
    mapper->toFirst();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
void MainWindow::on_actionTeam_members_triggered()
{
    ui->tableView->setModel(team_model());
    ui->tableView->selectRow(0);
    mapper->toFirst();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
void MainWindow::on_actionEmployees_triggered()
{
    ui->tableView->setModel(employee_model());
    ui->tableView->selectRow(0);
    mapper->toFirst();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
void MainWindow::on_actionPositions_triggered()
{
    ui->tableView->setModel(position_model());
    ui->tableView->selectRow(0);
    mapper->toFirst();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

//navigation
void MainWindow::on_first_pushButton_clicked()
{
    emit signal_from_navigation_button(-1);
}
void MainWindow::on_last_pushButton_clicked()
{
     emit signal_from_navigation_button(-2);
}
void MainWindow::on_previous_pushButton_clicked()
{
    emit signal_from_navigation_button(-3);
}
void MainWindow::on_next_pushButton_clicked()
{
    emit signal_from_navigation_button(-4);
}
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    emit signal_from_navigation_button(index.row());
}
int MainWindow::set_navigation_mapper(int buttonID)
{
    if(buttonID == -1){
        mapper->toFirst();
    }
    else
    if(buttonID == -2){
        mapper->toLast();
    }
    if(buttonID == -3){
         mapper->toPrevious();
    }
    if(buttonID == -4){
        mapper->toNext();
    }
    if(buttonID >= 0){
        mapper->setCurrentIndex(buttonID);
    }

    ui->tableView->selectRow(mapper->currentIndex());
}

//create and delete records
void MainWindow::on_create_contract_PushButton_clicked()
{
    on_last_pushButton_clicked();
    AllInfoNewRecordDialog *dialog = new AllInfoNewRecordDialog(db);
    if(dialog->exec()){
    ui->tableView->setModel(contract_model());
    }
}
void MainWindow::on_delete_contract_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("delete from contracts where contract_number = :contract_number;");
    query->bindValue(":contract_number",  ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0),0));
    query->exec();
    ui->tableView->setModel(contract_model());
    mapper->toFirst();
}

void MainWindow::on_create_customer_pushButton_clicked()
{
    CustomerNewRecordDialog *dialog = new CustomerNewRecordDialog(db);

    if(dialog->exec()){
        ui->tableView->setModel(customer_model());
    }
}
void MainWindow::on_delete_customer_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("delete from customers where checking_account = :checking_account;");
    query->bindValue(":checking_account", ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2),0));
    query->exec();
    ui->tableView->setModel(customer_model());
    mapper->toFirst();
}

void MainWindow::on_create_device_pushButton_clicked()
{
    DeviceNewRecordDialog *dialog = new DeviceNewRecordDialog(db);
     if(dialog->exec()){
         ui->tableView->setModel(device_model());
     }

}
void MainWindow::on_delete_device_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("delete from devices where code = :code;");
    query->bindValue(":code", ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0),0));
    query->exec();
    ui->tableView->setModel(device_model());
    mapper->toFirst();
}

void MainWindow::on_create_team_member_pushButton_clicked()
{
     TeamMemberNewRecordDialog *dialog = new TeamMemberNewRecordDialog(db);
     if(dialog->exec()){
         ui->tableView->setModel(team_model());
     }
}
void MainWindow::on_delete_team_member_pushButton_clicked()
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

    query->prepare("delete from creative_teams where employee_id = :employee_id and position_id = :position_id and team_id = :team_id;");
    query->bindValue(":employee_id", employee_code);
    query->bindValue(":position_id", position_code);
    query->bindValue(":team_id", ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2),0));
    query->exec();
    ui->tableView->setModel(team_model());
    mapper->toFirst();
}


void MainWindow::on_create_employee_pushButton_clicked()
{
     EmployeeNewRecordDialog *dialog = new EmployeeNewRecordDialog(db);
     if(dialog->exec()){
         ui->tableView->setModel(employee_model());
     }
}
void MainWindow::on_delete_employee_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("delete from employees where code = :code;");
    query->bindValue(":code", ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0),0));
    query->exec();
    ui->tableView->setModel(employee_model());
    mapper->toFirst();
}

void MainWindow::on_create_position_pushButton_clicked()
{
    PositionNewRecordDialog *dialog = new PositionNewRecordDialog(db);
     if(dialog->exec()){
         ui->tableView->setModel(position_model());
     }
}
void MainWindow::on_delete_position_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery(db);
    query->prepare("delete from positions where code = :code;");
    query->bindValue(":code", ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0),0));
    query->exec();
    ui->tableView->setModel(position_model());
    mapper->toFirst();
}

//models
QSqlTableModel* MainWindow::contract_model()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("contracts_all_information");
    model->setSort(0,Qt::AscendingOrder);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("number"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("device"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("amount"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("customer"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date of the agreement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("deadline date"));

    mapper->setModel(model);
    mapper->addMapping(ui->contracts_number_spinBox, 0);
    mapper->addMapping(ui->device_name_comboBox, 1);
    mapper->addMapping(ui->device_amount_spinBox, 2);
    mapper->addMapping(ui->customer_head_name_comboBox, 3);
    mapper->addMapping(ui->date_of_the_agreement_dateEdit, 4);
    mapper->addMapping(ui->deadline_dateEdit, 5);

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

    ui->string_view_stackedWidget->setCurrentIndex(0);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->resizeColumnsToContents();

    return model;
}
QSqlTableModel* MainWindow::customer_model()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("customers");
    model->setSort(0,Qt::AscendingOrder);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("head name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("address"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("checking account"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));

    mapper->setModel(model);
    mapper->addMapping(ui->customer_head_name_lineEdit, 0);
    mapper->addMapping(ui->customer_address_lineEdit, 1);
    mapper->addMapping(ui->customer_checking_account_lineEdit, 2);
    mapper->addMapping(ui->customer_telephone_ineEdit, 3);

    ui->string_view_stackedWidget->setCurrentIndex(1);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->resizeColumnsToContents();

    return model;
}
QSqlTableModel* MainWindow::device_model()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("devices");
    model->setSort(0,Qt::AscendingOrder);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("price"));

    mapper->setModel(model);
    mapper->addMapping(ui->device_code_lineEdit, 0);
    mapper->addMapping(ui->device_name_lineEdit, 1);
    mapper->addMapping(ui->device_price_spinBox, 2);

    ui->string_view_stackedWidget->setCurrentIndex(2);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->resizeColumnsToContents();

    return model;
}
QSqlTableModel* MainWindow::team_model()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("team_members");
    model->setSort(2,Qt::AscendingOrder);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("employee"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("position"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("project"));

    mapper->setModel(model);
    mapper->addMapping(ui->team_employee_comboBox, 0);
    mapper->addMapping(ui->team_position_comboBox, 1);
    mapper->addMapping(ui->team_project_number_comboBox, 2);

    QSqlQueryModel *employee_combo_box_model = new QSqlQueryModel();
    QSqlQuery *employee_combo_box_query = new QSqlQuery(db);
    employee_combo_box_query->prepare("select name from employees;");
    employee_combo_box_query->exec();
    employee_combo_box_model->setQuery(*employee_combo_box_query);
    ui->team_employee_comboBox->setModel(employee_combo_box_model);

    QSqlQueryModel *position_combo_box_model = new QSqlQueryModel();
    QSqlQuery *position_combo_box_query = new QSqlQuery(db);
    position_combo_box_query->prepare("select pos_name from positions;");
    position_combo_box_query->exec();
    position_combo_box_model->setQuery(*position_combo_box_query);
    ui->team_position_comboBox->setModel(position_combo_box_model);

    QSqlQueryModel *project_number_combo_box_model = new QSqlQueryModel();
    QSqlQuery *project_number_combo_box_query = new QSqlQuery(db);
    project_number_combo_box_query->prepare("select contract_number from contracts;");
    project_number_combo_box_query->exec();
    project_number_combo_box_model->setQuery(*project_number_combo_box_query);
    ui->team_project_number_comboBox->setModel(project_number_combo_box_model);

    ui->string_view_stackedWidget->setCurrentIndex(3);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->resizeColumnsToContents();

    return model;
}
QSqlTableModel* MainWindow::employee_model()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("employees");
    model->setSort(1,Qt::AscendingOrder);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));

    mapper->setModel(model);
    mapper->addMapping(ui->employee_code_lineEdit, 0);
    mapper->addMapping(ui->employee_name_lineEdit, 1);

    ui->string_view_stackedWidget->setCurrentIndex(4);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->resizeColumnsToContents();

    return model;
}
QSqlTableModel* MainWindow::position_model()
{
    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("positions");
    model->setSort(1,Qt::AscendingOrder);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));

    mapper->setModel(model);
    mapper->addMapping(ui->position_code_lineEdit, 0);
    mapper->addMapping(ui->position_name_lineEdit, 1);

    ui->string_view_stackedWidget->setCurrentIndex(5);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->resizeColumnsToContents();

    return model;
}

void MainWindow::on_contract_details_pushButton_clicked()
{
    ContractDetailsDialog *dialog = new ContractDetailsDialog(db, ui->tableView->currentIndex().row() + 1);
    if(dialog->exec()){
    }

}

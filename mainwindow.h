#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

#include "QMessageBox"
#include "QDebug"
#include "QDataWidgetMapper"
#include "QTableWidget"
#include "QSignalMapper"
#include "QObject"

#include "allInfoNewRecordDialog.h"
#include "customerNewRecordDialog.h"
#include "deviceNewRecordDialog.h"
#include "teamMemberNewRecordDialog.h"
#include "employeeNewRecordDialog.h"
#include "positionNewRecordDialog.h"
#include "contractDetailsDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QSqlDatabase db ,QWidget *parent = 0);
    ~MainWindow();

private slots:
    //menu
    void on_actionContracts_triggered();
    void on_actionCustomers_triggered();
    void on_actionTeam_members_triggered();
    void on_actionDevices_triggered();
    void on_actionEmployees_triggered();

    //navigation
    void on_first_pushButton_clicked();
    void on_last_pushButton_clicked();
    void on_previous_pushButton_clicked();
    void on_next_pushButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    int set_navigation_mapper(int buttonID);

    //create and delete records
    void on_create_contract_PushButton_clicked();
    void on_delete_contract_pushButton_clicked();

    void on_create_customer_pushButton_clicked();
    void on_delete_customer_pushButton_clicked();

    void on_create_device_pushButton_clicked();
    void on_delete_device_pushButton_clicked();

    void on_create_team_member_pushButton_clicked();
    void on_delete_team_member_pushButton_clicked();

    void on_create_employee_pushButton_clicked();
    void on_delete_employee_pushButton_clicked();

    void on_delete_position_pushButton_clicked();
    void on_create_position_pushButton_clicked();

    void on_actionPositions_triggered();

    void on_contract_details_pushButton_clicked();


private:
    QSqlDatabase db;
    Ui::MainWindow *ui;
    QDataWidgetMapper *mapper = new QDataWidgetMapper;

    QSqlTableModel* contract_model();
    QSqlTableModel* customer_model();
    QSqlTableModel* device_model();
    QSqlTableModel* team_model();
    QSqlTableModel* employee_model();
    QSqlTableModel* position_model();

signals:
    void signal_from_navigation_button(int buttonID);

};

#endif // MAINWINDOW_H

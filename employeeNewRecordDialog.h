#ifndef EMPLOYEENEWRECORDDIALOG_H
#define EMPLOYEENEWRECORDDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class EmployeeNewRecordDialog;
}

class EmployeeNewRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeNewRecordDialog(QSqlDatabase db, QWidget *parent = 0);
    ~EmployeeNewRecordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EmployeeNewRecordDialog *ui;
    QSqlDatabase db;
};

#endif // EMPLOYEENEWRECORDDIALOG_H

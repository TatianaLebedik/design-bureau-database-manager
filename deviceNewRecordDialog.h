#ifndef DEVICENEWRECORDDIALOG_H
#define DEVICENEWRECORDDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class DeviceNewRecordDialog;
}

class DeviceNewRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceNewRecordDialog(QSqlDatabase db, QWidget *parent = 0);
    ~DeviceNewRecordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeviceNewRecordDialog *ui;
    QSqlDatabase db;
};

#endif // DEVICENEWRECORDDIALOG_H

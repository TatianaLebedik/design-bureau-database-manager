#ifndef CUSTOMERNEWRECORDDIALOG_H
#define CUSTOMERNEWRECORDDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class CustomerNewRecordDialog;
}

class CustomerNewRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerNewRecordDialog(QSqlDatabase db, QWidget *parent = 0);
    ~CustomerNewRecordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    QSqlDatabase db;
    Ui::CustomerNewRecordDialog *ui;
};

#endif // CUSTOMERNEWRECORDDIALOG_H

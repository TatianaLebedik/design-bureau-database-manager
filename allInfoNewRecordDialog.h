#ifndef ALLINFONEWRECORDDIALOG_H
#define ALLINFONEWRECORDDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class AllInfoNewRecordDialog;
}

class AllInfoNewRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AllInfoNewRecordDialog(QSqlDatabase db, QWidget *parent = 0);
    ~AllInfoNewRecordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    QSqlDatabase db;
    Ui::AllInfoNewRecordDialog *ui;
};

#endif // ALLINFONEWRECORDDIALOG_H

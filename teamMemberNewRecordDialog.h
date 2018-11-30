#ifndef TEAMMEMBERNEWRECORDDIALOG_H
#define TEAMMEMBERNEWRECORDDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class TeamMemberNewRecordDialog;
}

class TeamMemberNewRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeamMemberNewRecordDialog(QSqlDatabase db, QWidget *parent = 0);
    ~TeamMemberNewRecordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TeamMemberNewRecordDialog *ui;
    QSqlDatabase db;
};

#endif // TEAMMEMBERNEWRECORDDIALOG_H

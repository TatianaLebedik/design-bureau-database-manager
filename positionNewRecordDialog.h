#ifndef POSITIONNEWRECORDDIALOG_H
#define POSITIONNEWRECORDDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class PositionNewRecordDialog;
}

class PositionNewRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PositionNewRecordDialog(QSqlDatabase db, QWidget *parent = 0);
    ~PositionNewRecordDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PositionNewRecordDialog *ui;
    QSqlDatabase db;
};

#endif // POSITIONNEWRECORDDIALOG_H

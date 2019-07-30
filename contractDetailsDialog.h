#ifndef CONTRACTDETAILSDIALOG_H
#define CONTRACTDETAILSDIALOG_H

#include <QDialog>
#include "QDebug"

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlTableModel"

namespace Ui {
class ContractDetailsDialog;
}

class ContractDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContractDetailsDialog(QSqlDatabase db, int current_contract_number, QWidget *parent = 0);
    ~ContractDetailsDialog();

private:
    Ui::ContractDetailsDialog *ui;
};

#endif // CONTRACTDETAILSDIALOG_H

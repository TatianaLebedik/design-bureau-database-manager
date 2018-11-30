#ifndef CONTRACTDETAILSDIALOG_H
#define CONTRACTDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class ContractDetailsDialog;
}

class ContractDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContractDetailsDialog(QWidget *parent = 0);
    ~ContractDetailsDialog();

private:
    Ui::ContractDetailsDialog *ui;
};

#endif // CONTRACTDETAILSDIALOG_H

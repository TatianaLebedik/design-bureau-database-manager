#ifndef AUTHENTICATIONFORM_H
#define AUTHENTICATIONFORM_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class AuthenticationForm;
}

class AuthenticationForm : public QDialog
{
    Q_OBJECT

public:
    //TO DO:set what private, what public
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","main_connection");
    explicit AuthenticationForm(QWidget *parent = 0);
    ~AuthenticationForm();

private slots:
    void on_authentication_pushButton_clicked();

private:
    Ui::AuthenticationForm *ui;
    MainWindow *main_act_window;
    QSqlTableModel *model = new QSqlTableModel(0, db);
};

#endif // AUTHENTICATIONFORM_H

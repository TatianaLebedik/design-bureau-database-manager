#include "authenticationForm.h"
#include "ui_authenticationform.h"

AuthenticationForm::AuthenticationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthenticationForm)
{
    ui->setupUi(this);
}

AuthenticationForm::~AuthenticationForm()
{
    delete ui;
}

void AuthenticationForm::on_authentication_pushButton_clicked()
{
    db.setHostName("localhost");
    db.setDatabaseName("DesignBureau");
    db.setUserName(ui->username_lineEdit->text());
    db.setPassword(ui->password_lineEdit->text());
    if(!db.open()){
        QMessageBox::warning(this,"Error","Unable to connect to the database");
    }
    else {

           this->setVisible(0);

        main_act_window = new MainWindow(db);
        main_act_window->show();
    }


}

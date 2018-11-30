#include "mainactivewindow.h"
#include "ui_mainactivewindow.h"

MainActiveWindow::MainActiveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainActiveWindow)
{
    ui->setupUi(this);
}

MainActiveWindow::~MainActiveWindow()
{
    delete ui;
}

#ifndef TABLE_NAVIGATION_H
#define TABLE_NAVIGATION_H
#include"ui_mainwindow.h"
#include "mainwindow.h"

class TABLE_NAVIGATION
{
private:
public:
    TABLE_NAVIGATION();
    TABLE_NAVIGATION( QTableView *table_view);
   // void current_table_records_output( Ui::MainWindow *ui);

    int next_record( QTableView *table_view);
    int previous_record(QTableView *table_view);
};

#endif // TABLE_NAVIGATION_H

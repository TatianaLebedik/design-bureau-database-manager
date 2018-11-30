#include "table_navigation.h"

TABLE_NAVIGATION::TABLE_NAVIGATION()
{

}

TABLE_NAVIGATION::TABLE_NAVIGATION( QTableView *table_view)
{
    table_view->selectRow(0);
}

int TABLE_NAVIGATION::next_record(QTableView *table_view)
{

    //table_view->selectRaw(table_view->);

}

int TABLE_NAVIGATION::previous_record(QTableView *table_view)
{


}


/*
 void TABLE_NAVIGATION::current_table_records_output( Ui::MainWindow *ui){
    ui->contract_number_lineEdit->setText(ui->tableView->currentIndex().data().toString());

 }
*/

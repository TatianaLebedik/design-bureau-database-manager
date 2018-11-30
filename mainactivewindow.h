#ifndef MAINACTIVEWINDOW_H
#define MAINACTIVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainActiveWindow;
}

class MainActiveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainActiveWindow(QWidget *parent = 0);
    ~MainActiveWindow();

private:
    Ui::MainActiveWindow *ui;
};

#endif // MAINACTIVEWINDOW_H

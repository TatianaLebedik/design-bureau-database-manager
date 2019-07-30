#include "authenticationForm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthenticationForm w;
    w.show();

    return a.exec();
}

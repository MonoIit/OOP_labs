#include "smirnovmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmirnovMain w;
    w.show();
    return a.exec();
}

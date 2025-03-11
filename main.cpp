#include "functiontest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FunctionTest w;
    w.show();
    return a.exec();
}

#include "transformer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    transformer w;
    w.show();
    return a.exec();
}

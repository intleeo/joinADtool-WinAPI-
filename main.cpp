#include "joinADtoolstest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    joinADtoolstest w;


    w.setFixedSize(181, 200);//275,140
    w.show();
    return a.exec();
}

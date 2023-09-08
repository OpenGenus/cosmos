#include "dialog.h"
#include <QApplication>
#include "nodo.h"


int main(int argc, char *argv[])
{

    QApplication z(argc, argv);
    Dialog w;
    w.show();

    return z.exec();
}

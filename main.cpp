#include "smartalarm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmartAlarm w;
    w.show();
    return a.exec();
}

#include <QApplication>
#include <QPushButton>
#include "test.h"
#include"gui.h"
int main(int argc, char *argv[]) {
    testAll();
    QApplication a(argc, argv);
    Repository r("C:/eu/ubb/2nd_Semester/oop/practicoop/date.txt","C:/eu/ubb/2nd_Semester/oop/practicoop/ateliere.txt");
    Service srv{r};
    guiElev gui{srv};
    gui.show();
    return QApplication::exec();
}

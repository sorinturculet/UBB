#include <QApplication>
#include <QPushButton>
#include "tests.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    test_all();

    QApplication a(argc, argv);
    Repository r{"C:\\Users\\sorn\\Desktop\\practicoop\\data.txt"};
    Service s{r};
    GUI* g=new GUI{s};
    g->show();
    return QApplication::exec();
}

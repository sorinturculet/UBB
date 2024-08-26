#include <QApplication>
#include <QPushButton>
#include "ProductGUI.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    DisciplinaRepoFile repo("C:/eu/ubb/2nd_Semester/oop/lab10-11/date.txt");
    //RepoMap repo(100);
    DisciplinaValidator val;
    DisciplinaService srv{repo,val};
    ProductGUI gui{srv};
    gui.show();

    return QApplication::exec();
}

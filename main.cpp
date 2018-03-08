#include "board.h"
#include <QApplication>

#include "src_Tests/testsunitaires.h"

int main(int argc, char *argv[])
{
#ifdef MODE_TESTS_UNITAIRE
    TestsUnitaires test;
    return 0;
#else
    QApplication a(argc, argv);
    Board w;
    w.show();

    return a.exec();
#endif
}

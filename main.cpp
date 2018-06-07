#include <iostream>
//#include <QtWidgets/QApplication>
//#include "ui.hpp"
#include "gui.hpp"
#include "test.cpp"

int main(int argc, char* argv[])
{
    //Tests t;
    //t.TestCtrl();

    QApplication app{argc, argv};

    auto* repo = new Repository<Event>;
    auto* ctrl = new Controller(*repo);
    GUIQt ui(*ctrl);

    ui.show();

    delete repo;
    delete ctrl;

    return QApplication::exec();
}
#include <iostream>
#include "ui.hpp"
#include "test.cpp"

int main()
{
    Tests t;
    t.TestCtrl();

    auto* repo = new Repository<Event>;
    auto* ctrl = new Controller(*repo);
    auto* ui = new UI(*ctrl);

    ui->StartUI();

    delete repo;
    delete ctrl;
    delete ui;

    return 0;
}
#include <iostream>
//#include <QtWidgets/QApplication>
//#include "ui.hpp"
#include "gui.hpp"
#include "test.cpp"

/*int ChooseModeGUI(int argc, char *argv[]);
int AdminMenuGUI(int argc, char *argv[]);
int AdminAddGUI(int argc, char *argv[]);
int GUI(int argc, char *argv[]);
int UserMenuGUI(int argc, char *argv[]);*/

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

    //return ChooseModeGUI(argc, argv);
    //return AdminMenuGUI(argc, argv);
    //return AdminAddGUI(argc, argv);
    return QApplication::exec();
}

/*int ChooseModeGUI(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *main = new QWidget{};
    auto *hl = new QHBoxLayout;
    QLabel *label = new QLabel("Choose: ");
    QPushButton *adm_btn = new QPushButton("Admin");
    QPushButton *usr_btn = new QPushButton("User");

    QSplashScreen spl;

    hl->addWidget(label);
    hl->addWidget(adm_btn);
    hl->addWidget(usr_btn);

    main->setLayout(hl);
    main->show();
    main->setWindowTitle("Choose mode");
    main->setFixedHeight(main->sizeHint().height());

    return a.exec();
}

int AdminMenuGUI(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *main = new QWidget{};
    auto *options_layout = new QVBoxLayout;
    auto *layout = new QHBoxLayout;
    QPushButton *add_btn = new QPushButton("Add");
    QPushButton *delete_btn = new QPushButton("Delete");
    QPushButton *update_btn = new QPushButton("Update");
    auto *list = new QListWidget;
    new QListWidgetItem("First", list);
    new QListWidgetItem("Second", list);

    QListWidgetItem *item3 = new QListWidgetItem("Third");
    list->insertItem(0, item3);

    options_layout->addWidget(add_btn);
    options_layout->addWidget(delete_btn);
    options_layout->addWidget(update_btn);

    layout->addLayout(options_layout);
    layout->addWidget(list);

    main->setLayout(layout);
    main->show();
    main->setWindowTitle("Admin menu");
    main->setFixedHeight(main->sizeHint().height());

    return a.exec();
}

int AdminAddGUI(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget *main = new QWidget{};
    QLabel *test = new QLabel{};

    int reply;
    reply = QMessageBox::question(main, "Test", "Quit", QMessageBox::Yes|QMessageBox::No);

    QString reply_str = QString::number(reply);

    test->setText(reply_str);

    test->show();
    //main->show();

    return a.exec();
}

int UserMenuGUI(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *main = new QWidget{};


    return a.exec();
}*/
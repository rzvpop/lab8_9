#ifndef LAB8_9_GUI_H
#define LAB8_9_GUI_H

#include "controller.hpp"
#include <QtCore>
#include <QApplication>
#include <QWidget>
#include <utility>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>

class GUIQt : public QWidget
{
Q_OBJECT

public:
    explicit GUIQt(const Controller &_ctrl);
    ~GUIQt() override = default;

    void InitAdminGUI();

public slots:
    void AddWindowAdmin();
    void Add();

private:
    void InitList();

    Controller ctrl;
    QHBoxLayout *layout;
    QLabel *l;
    QVBoxLayout *adm_options;
    QPushButton *add_btn;
    QPushButton *delete_btn;
    QPushButton *update_btn;
    QListWidget *list;

    QDialog *add_window;
    QVBoxLayout *add_layout;
    QPushButton *fin_add;
    QLineEdit *title_edit;
    QLineEdit *descr_edit;
    QLineEdit *date_time_edit;
    QLineEdit *source_edit;
    QLineEdit *nr_people_edit;
    QLineEdit *duration_edit;
};

#endif //LAB8_9_GUI_H

#ifndef LAB8_9_GUI_H
#define LAB8_9_GUI_H

#include "controller.hpp"
#include <QtCore>
#include <QApplication>
#include <QWidget>
#include <QtWidgets/QMainWindow>
#include <utility>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class GUIQt : public QWidget
{
    Q_OBJECT

public:
    explicit GUIQt(const Controller &_ctrl);
    ~GUIQt() override = default;

private:
    Controller ctrl;
    QHBoxLayout *layout;
    QLabel *l;
};

#include "GUI.h"

GUIQt::GUIQt(const Controller &_ctrl) : ctrl(_ctrl)
{
    layout = new QHBoxLayout{};
    l = new QLabel{"Hello world!"};

    layout->addWidget(l);

    QWidget::setLayout(layout);
}
#endif //LAB8_9_GUI_H

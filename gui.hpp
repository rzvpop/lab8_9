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
#include <QMessageBox>
#include <fstream>
#include <QtWidgets/QRadioButton>

class GUIQt : public QWidget
{
Q_OBJECT

public:
    explicit GUIQt(const Controller &_ctrl);
    ~GUIQt() override = default;

    void ChooseModeGUI();
    void InitAdminGUI();
    void InitUserGUI();
    void ReadFromFile(std::string);

public slots:
    void ChooseMode();

    void AddWindowAdmin();
    void UpdateWindowAdmin();
    void Add();
    void Delete();
    void Update();
    void Filter();

    void AddToPlaylist();
    void Play();

private:
    void InitList();

    int mode;
    Controller ctrl;

    QDialog *choice_window;
    QHBoxLayout *choice_layout;
    QPushButton *choose;
    QRadioButton *adm_radio;
    QRadioButton *usr_radio;

    QHBoxLayout *layout;
    QLabel *l;
    QVBoxLayout *adm_options;
    QPushButton *add_btn;
    QPushButton *delete_btn;
    QPushButton *update_btn;
    QListWidget *list;
    QVBoxLayout *filter_layout;
    QLineEdit *filter_edit;

    QDialog *add_window;
    QVBoxLayout *add_layout;
    QPushButton *fin_add;
    QLineEdit *title_edit;
    QLineEdit *descr_edit;
    QLineEdit *date_time_edit;
    QLineEdit *source_edit;
    QLineEdit *nr_people_edit;
    QLineEdit *duration_edit;

    QPushButton *add_to_playlist_btn;
    QListWidget *playlist;
    QPushButton *play;
    QVBoxLayout *playlist_layout;

    QHBoxLayout *undo_layout;
    QPushButton *undo_button;
    QPushButton *redo_button;
};

#endif //LAB8_9_GUI_H

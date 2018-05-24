#include "gui.hpp"

GUIQt::GUIQt(const Controller &_ctrl) : ctrl(_ctrl)
{
    mode = 1;

    ChooseModeGUI();

    if(mode == 1)
    {
        InitAdminGUI();
        InitList();

        connect(add_btn, SIGNAL(clicked()), this, SLOT(AddWindowAdmin()));
        connect(delete_btn, SIGNAL(clicked()), this, SLOT(Delete()));
        connect(update_btn, SIGNAL(clicked()), this, SLOT(UpdateWindowAdmin()));
        connect(filter_edit, SIGNAL(textChanged(const QString&)), this, SLOT(Filter()));
    }
    else if(mode == 2)
    {
        EventList *el = new EventListCSV;
        el->SetFilename("EventList.csv");
        ctrl.SetEventList(el);

        InitUserGUI();
        InitList();

        connect(add_to_playlist_btn, SIGNAL(clicked()), this, SLOT(AddToPlaylist()));
        connect(play, SIGNAL(clicked()), this, SLOT(Play()));
    }
    else
    {
        QWidget::close();
    }
}

void GUIQt::InitAdminGUI()
{
    QWidget::setWindowTitle("Admin mode");

    layout = new QHBoxLayout{this};
    adm_options = new QVBoxLayout;
    add_btn = new QPushButton("Add");
    delete_btn = new QPushButton("Delete");
    update_btn = new QPushButton("Update");
    list = new QListWidget;
    l = new QLabel("Options:");
    filter_layout = new QVBoxLayout;
    filter_edit = new QLineEdit;
    //filter_btn = new QPushButton("Filter");

    filter_edit->setPlaceholderText("Text to match..");

    adm_options->addWidget(l);
    adm_options->addWidget(add_btn);
    adm_options->addWidget(delete_btn);
    adm_options->addWidget(update_btn);

    filter_layout->addWidget(filter_edit);
    //filter_layout->addWidget(filter_btn);

    layout->addLayout(adm_options);
    layout->addWidget(list);
    layout->addLayout(filter_layout);

    QWidget::setLayout(layout);

    this->setFixedHeight(this->sizeHint().height());
}

void GUIQt::AddWindowAdmin()
{
    add_window = new QDialog(this);
    add_layout = new QVBoxLayout;

    fin_add = new QPushButton;
    title_edit = new QLineEdit;
    descr_edit = new QLineEdit;
    date_time_edit = new QLineEdit;
    nr_people_edit = new QLineEdit;
    source_edit = new QLineEdit;
    duration_edit = new QLineEdit;

    fin_add->setText("Finish add");
    title_edit->setPlaceholderText(QString("Title.."));
    descr_edit->setPlaceholderText(QString("Description.."));
    date_time_edit->setPlaceholderText(QString("Date and time.."));
    nr_people_edit->setPlaceholderText(QString("Number of people going.."));
    source_edit->setPlaceholderText(QString("Source.."));
    duration_edit->setPlaceholderText(QString("Duration.."));

    add_layout->addWidget(title_edit);
    add_layout->addWidget(descr_edit);
    add_layout->addWidget(date_time_edit);
    add_layout->addWidget(nr_people_edit);
    add_layout->addWidget(source_edit);
    add_layout->addWidget(duration_edit);
    add_layout->addWidget(fin_add);

    add_window->setLayout(add_layout);

    connect(fin_add, SIGNAL(clicked()), this, SLOT(Add()));

    int ex = add_window->exec();
}

void GUIQt::Add()
{
    std::string title(title_edit->text().toStdString());
    std::string descr(descr_edit->text().toStdString());
    std::string date_time(date_time_edit->text().toStdString());
    std::string nr_people(nr_people_edit->text().toStdString());
    std::string source(source_edit->text().toStdString());
    std::string duration(duration_edit->text().toStdString());

    ctrl.AddToRepo(title, descr, date_time, atoi(nr_people.c_str()), source, atoi(duration.c_str()));

    Event e(title, descr, date_time, atoi(nr_people.c_str()), source, atoi(duration.c_str()));
    new QListWidgetItem(QString(e.GetStr().c_str()), list);
    ctrl.WriteInFile("events.txt");
    add_window->close();
}

void GUIQt::InitList()
{
    ReadFromFile("events.txt");

    std::vector<Event> v = ctrl.GetRepo()->GetVector();

    for(auto &it : v)
    {
        std::string e_str = it.GetStr();
        new QListWidgetItem(QString(e_str.c_str()), list);
    }
}

void GUIQt::ReadFromFile(std::string str)
{
    std::ifstream fin(str);
    Event e;

    if (fin.is_open())
    {
        while(fin >> e)
        {
            try
            {
                ctrl.AddToRepo(e.GetTitle(), e.GetDesc(), e.GetDate(), e.GetNrPeople(), e.GetSource(), e.GetDuration());
            }
            catch(RepoException &ex)
            {
                std::cout << ex.GetMsg() << '\n';
            }
        }
    }

    fin.close();
}

void GUIQt::Delete()
{

    QListWidgetItem *item = list->currentItem();
    if(item != nullptr)
    {
        QStringList str_list = item->text().split(',');

        int reply = QMessageBox::question(this, "Are you sure you want to delete this item?", "Quit",
                                          QMessageBox::Yes | QMessageBox::No);

        if (reply == 0x4000) {
            list->removeItemWidget(item);
            delete item;

            ctrl.RemoveFromRepo(str_list[0].toStdString());
            ctrl.WriteInFile("events.txt");
        }
    }
}

void GUIQt::UpdateWindowAdmin()
{
    if(list->currentItem() != nullptr)
    {
        QStringList str_list = list->currentItem()->text().split(", ");

        add_window = new QDialog(this);
        add_layout = new QVBoxLayout;

        fin_add = new QPushButton("Finish update");
        title_edit = new QLineEdit(str_list[0]);
        descr_edit = new QLineEdit(str_list[1]);
        date_time_edit = new QLineEdit(str_list[2]);
        nr_people_edit = new QLineEdit(str_list[3]);
        source_edit = new QLineEdit(str_list[4]);
        duration_edit = new QLineEdit(str_list[5]);

        add_layout->addWidget(title_edit);
        add_layout->addWidget(descr_edit);
        add_layout->addWidget(date_time_edit);
        add_layout->addWidget(nr_people_edit);
        add_layout->addWidget(source_edit);
        add_layout->addWidget(duration_edit);
        add_layout->addWidget(fin_add);

        add_window->setLayout(add_layout);

        connect(fin_add, SIGNAL(clicked()), this, SLOT(Update()));

        int ex = add_window->exec();
    }
}

void GUIQt::Update()
{
    std::string title(title_edit->text().toStdString());
    std::string descr(descr_edit->text().toStdString());
    std::string date_time(date_time_edit->text().toStdString());
    std::string nr_people(nr_people_edit->text().toStdString());
    std::string source(source_edit->text().toStdString());
    std::string duration(duration_edit->text().toStdString());

    ctrl.UpdateInRepo(title, descr, date_time, atoi(nr_people.c_str()), source, atoi(duration.c_str()));

    Event e(title, descr, date_time, atoi(nr_people.c_str()), source, atoi(duration.c_str()));

    list->currentItem()->setText(QString(e.GetStr().c_str()));

    ctrl.WriteInFile("events.txt");
    add_window->close();
}

void GUIQt::InitUserGUI()
{
    QWidget::setWindowTitle("User mode");

    layout = new QHBoxLayout{this};
    list = new QListWidget;
    playlist_layout = new QVBoxLayout;
    add_to_playlist_btn = new QPushButton(">");
    play = new QPushButton("Go to source");
    playlist = new QListWidget;

    playlist_layout->addWidget(playlist);
    playlist_layout->addWidget(play);

    layout->addWidget(list);
    layout->addWidget(add_to_playlist_btn);
    layout->addLayout(playlist_layout);

    QWidget::setLayout(layout);

    this->setFixedHeight(this->sizeHint().height());
}

void GUIQt::ChooseModeGUI()
{
    choice_window = new QDialog(this);
    choice_layout = new QHBoxLayout;
    adm_radio = new QRadioButton("Admin");
    usr_radio = new QRadioButton("User");
    choose = new QPushButton("Choose");

    adm_radio->setChecked(true);

    choice_layout->addWidget(adm_radio);
    choice_layout->addWidget(usr_radio);
    choice_layout->addWidget(choose);

    choice_window->setLayout(choice_layout);

    connect(choose, SIGNAL(clicked()), this, SLOT(ChooseMode()));

    int ex = choice_window->exec();
}

void GUIQt::ChooseMode()
{
    if(adm_radio->isChecked())
        mode = 1;
    else
        mode = 2;

    choice_window->close();
}

void GUIQt::AddToPlaylist()
{
    QListWidgetItem *item = list->currentItem();
    if(list->currentItem() != nullptr)
    {
        QStringList str_list = item->text().split(", ");
        std::string title(str_list[0].toStdString());
        Repository<Event> *repo = ctrl.GetRepo();
        int pos = repo->Find(Event(title, "", "", 0, "", 0));
        auto e = ctrl.GetElemOnPosRepo(pos);

        ctrl.AddInUserList(*e);
        ctrl.SaveListToFile();
        e->SetNrPeople(e->GetNrPeople() + 1);

        new QListWidgetItem(QString(e->GetStr().c_str()), playlist);
        list->removeItemWidget(item);
        delete item;
    }
}

void GUIQt::Play()
{
    QListWidgetItem *item = playlist->currentItem();
    if(playlist->currentItem() != nullptr)
    {
        QStringList str_list = item->text().split(", ");
        std::string title(str_list[0].toStdString());
        Repository<Event> *repo = ctrl.GetRepo();
        int pos = repo->Find(Event(title, "", "", 0, "", 0));

        ctrl.AccesEventPage(pos);
        int row = playlist->row(item);

        if(row == playlist->count() - 1)
            playlist->setCurrentRow(0);
        else
            playlist->setCurrentRow(row + 1);
    }
}

void GUIQt::Filter()
{
    list->clear();

    std::vector<Event> v = ctrl.GetRepo()->GetVector();
    std::string filter_text = filter_edit->text().toStdString();

    for(auto &it : v)
    {
        std::string e_str = it.GetStr();
        std::string e_str_copy = e_str;

        std::transform(e_str_copy.begin(), e_str_copy.end(), e_str_copy.begin(), ::tolower);
        std::transform(filter_text.begin(), filter_text.end(), filter_text.begin(), ::tolower);
        //don't use ::tolower on multi-byte-characters!

        if(e_str_copy.find(filter_text) != -1)
            new QListWidgetItem(QString(e_str.c_str()), list);
    }
}

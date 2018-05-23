#include "ui.hpp"

void UI::AddUIAdm()
{
    //auto * str = new char[255];
    auto v = new Valid;
    int nr, duration;

    std::cout << "Give title: ";
    //std::cin.getline(str, 255, '\n');
    std::string title;
    std::cin >> title;

    std::cout << "Give description: ";
    //std::cin.getline(str, 255, '\n');
    std::string desc;
    std::cin >> desc;

    std::cout << "Give date and time: ";
    //std::cin.getline(str, 255, '\n');
    std::string time;
    std::cin >> time;

    std::cout << "Give number of people who are going: ";
    std::cin >> nr;

    std::cout << "Give source link: ";
    //std::cin.getline(str, 255, '\n');
    std::string link;
    std::cin >> link;

    std::cout << "Give duration: ";
    std::cin >> duration;

    ctrl.AddToRepo(title, desc, time, nr, link, duration);

    delete v;
    //delete[] str;
}

void UI::DeleteUIAdm()
{
    //auto* str = new char[255];

    std::cout << "Give title: ";
    //std::cin.getline(str, 255, '\n');
    std::string title;
    std::cin >> title;

    ctrl.RemoveFromRepo(title);

    //delete[] str;
}

void UI::UpdateUIAdm()
{
    //auto * str = new char[255];
    int new_nr;

    std::cout << "Give old title: ";
    //std::cin.getline(str, 255, '\n');
    std::string title;
    std::cin >> title;

    std::cout << "Give description: ";
    //std::cin.getline(str, 255, '\n');
    std::string new_desc;
    std::cin >> new_desc;

    std::cout << "Give date and time: ";
    //std::cin.getline(str, 255, '\n');
    std::string new_time;
    std::cin >> new_time;

    std::cout << "Give number of people who are going: ";
    std::cin >> new_nr;

    std::cout << "Give source link: ";
    //std::cin.getline(str, 255, '\n');
    std::string new_link;
    std::cin >> new_link;

    ctrl.UpdateInRepo(title, new_desc, new_time, new_nr, new_link, 0);

    //delete[] str;
}

void UI::PrintUIAdm()
{
    //Repository<Event> repo = ctrl.GetRepo();

    for(int i = 0; i < ctrl.GetRepoSize(); ++i)
        std::cout << '-' << ctrl.GetRepoElemOnPosStr(i) << '\n';
}

void UI::PrintByMonthUser()
{
    int month;

    std::cout << "Month: ";
    std::cin >> month;

    for(int i = 0; i < ctrl.GetRepoSize(); ++i)
    {
        int cont = 0;

        if(month == ctrl.GetMonthOnPos(i))
        {
            std::cout << '-' << ctrl.GetRepoElemOnPosStr(i) << '\n';
            ctrl.AccesEventPage(i);

            std::cout << "\nContinue(1), add to your list(2) or stop(0)? ";
            std::cin >> cont;
            if (cont == 0)
                break;
            else if (cont == 1)
            {
                if(i == ctrl.GetRepoSize() - 1)
                    i = -1;
            }
            else if(cont == 2)
            {
                const auto e = ctrl.GetElemOnPosRepo(i);
                ctrl.AddInUserList(*e);
                if(i == ctrl.GetRepoSize() - 1)
                    i = -1;
            }
            else
                --i;
        }
    }
}

void UI::DeleteFromUserList()
{
    std::string title;
    std::cin >> title;

    ctrl.RemoveFromUserList(Event(title, "", "", 0, ""));
}

void UI::SeeUserList()
{
    for(int i = 0; i < ctrl.GetUserListSize(); ++i)
        std::cout << '-' << ctrl.GetUserListElemOnPosStr(i) << '\n';
}

void UI::StartUI()
{
    ReadFromFile("events.txt");

    int mode = 1;
    std::cout << "Admin or user?(1 or 2)\n";
    std::cin >> mode;

    while(mode != 1 && mode != 2)
        std::cin >> mode;

    if(mode == 1)
        UiAdmin();
    else if(mode == 2)
        UIUser();
}

void UI::HelpAdm()
{
    std::cout << "----------------------\n"
            "0.Exit\n" <<
              "1.Add\n" <<
              "2.Delete\n" <<
              "3.Update\n" <<
              "4.Print all\n" <<
              "----------------------\n";
}

void UI::HelpUser()
{
    std::cout << "----------------------\n"
            "0.Exit\n" <<
              "1.See by month\n" <<
              "2.Delete from my list\n" <<
              "3.See my list\n" <<
              "4.Add to file\n" <<
              "5.Display lsit\n" <<
              "----------------------\n";
}


void UI::UiAdmin()
{
    HelpAdm();
    std::cout << '\n';

    while(1)
    {
        int comm = 0;
        std::cout << ">>";
        std::cin >> comm;

        try
        {
            if(comm == 0)
                break;
            else if(comm == 1)
                AddUIAdm();
            else if(comm == 2)
                DeleteUIAdm();
            else if(comm == 3)
                UpdateUIAdm();
            else if(comm == 4)
                PrintUIAdm();
            else
                std::cout << "Invalid command!\n";

            if(comm >=1 && comm <= 3)
                ctrl.WriteInFile("events.txt");
        }
        catch(const RepoException &ex)
        {
            std::cout << ex.GetMsg() << '\n';
        }
        catch(const ValidatorException &ex)
        {
            std::cout << ex.GetMsg() << '\n';
        }
    }
}

void UI::UIUser()
{
    HelpUser();
    std::cout << '\n';

    int format = 0;

    while(format != 1 && format != 2)
    {
        std::cout << "Choose format: csv(1) or html(2)?\n";
        std::cin >> format;
    }

    EventList *el = nullptr;
    if(format == 1)
    {
        el = new EventListCSV;
        el->SetFilename("EventList.csv");
    }
    else if(format == 2)
    {
        el = new EventListHTML;
        el->SetFilename("EventList.html");
    }

    ctrl.SetEventList(el);

    while(1)
    {
        int comm = 0;
        std::cout << ">>";
        std::cin >> comm;

        try
        {
            if (comm == 0)
                break;
            else if(comm == 1)
                PrintByMonthUser();
            else if(comm == 2)
                DeleteFromUserList();
            else if(comm == 3)
                SeeUserList();
            else if(comm == 4)
                SaveListToFile();
            else if(comm == 5)
                DisplayList();
            else
                std::cout << "Invalid command!";
        }
        catch(const RepoException &ex)
        {
            std::cout << ex.GetMsg() << '\n';
        }
    }

    delete el;
}

void UI::ReadFromFile(std::string str)
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

void UI::SaveListToFile()
{
    ctrl.SaveListToFile();
}

void UI::DisplayList()
{
    ctrl.DisplayList();
}

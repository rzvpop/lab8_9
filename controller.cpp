#include "controller.hpp"

#include <utility>

Repository<Event> Controller::GetRepo()
{
    return repo;
}

void Controller::AddToRepo(std::string _title, std::string _desc, std::string _dt, int _nrp, std::string _source, int _duration)
{

    Event e(std::move(_title), std::move(_desc), std::move(_dt), _nrp, std::move(_source), _duration);

    repo.Add(e);
    repo.Sort();
}

void Controller::RemoveFromRepo(std::string title)
{
    repo.Remove(Event(std::move(title), "", "", 0, ""));
}

void Controller::UpdateInRepo(std::string title, std::string new_desc, std::string new_dt, int new_nrp,std::string new_source)
{
    repo.Replace(Event(std::move(title), std::move(new_desc), std::move(new_dt), new_nrp, std::move(new_source)));
}

std::string Controller::GetRepoElemOnPosStr(int i)
{
    auto e = repo.GetEventOnPos(i);
    return e->GetStr();
}

int Controller::GetRepoSize()
{
    return repo.GetNrElems();
}

void Controller::AccesEventPage(int i)
{
    const auto e = repo.GetEventOnPos(i);

    e->AccesPage();
}

int Controller::GetMonthOnPos(int i)
{
    const auto e = repo.GetEventOnPos(i);

    return e->GetMonth();
}

void Controller::AddInUserList(Event e)
{
    user_list.Add(e);
    int pos = user_list.Find(e);
    auto aux = user_list.GetEventOnPos(pos);
    aux->SetNrPeople(e.GetNrPeople() + 1);
    user_list.Sort();
}

void Controller::RemoveFromUserList(Event e)
{
    user_list.Remove(e);
    int pos = user_list.Find(e);
    auto aux = user_list.GetEventOnPos(pos);
    aux->SetNrPeople(e.GetNrPeople() - 1);
}

std::vector<Event>::iterator Controller::GetElemOnPosRepo(int i)
{
    return repo.GetEventOnPos(i);
}

int Controller::GetUserListSize()
{
    return user_list.GetNrElems();
}

std::string Controller::GetUserListElemOnPosStr(int i)
{
    auto e = user_list.GetEventOnPos(i);
    return e->GetStr();
}
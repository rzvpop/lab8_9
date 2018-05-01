#ifndef LAB5_6_CONTROLLER_HPP
#define LAB5_6_CONTROLLER_HPP

#include "repository.hpp"
#include "event.hpp"

class Controller
{
public:
    explicit Controller(Repository<Event>& _repo) : repo(_repo){}

    Repository<Event> GetRepo();
    int GetRepoSize();
    void AddToRepo(std::string, std::string, std::string, int, std::string, int); //adds in repo an Event initialized with thse parameters
    void RemoveFromRepo(std::string);
    void UpdateInRepo(std::string, std::string, std::string, int, std::string);
    std::string GetRepoElemOnPosStr(int);
    void AccesEventPage(int);
    int GetMonthOnPos(int);
    void AddInUserList(Event e);
    void RemoveFromUserList(Event e);
    std::vector<Event>::iterator GetElemOnPosRepo(int);
    int GetUserListSize();
    std::string GetUserListElemOnPosStr(int);

private:
    Repository<Event> repo;
    Repository<Event> user_list;
};

#endif //LAB5_6_CONTROLLER_HPP

#ifndef LAB5_6_CONTROLLER_HPP
#define LAB5_6_CONTROLLER_HPP

#include "eventlistCSV.hpp"
#include "eventlistHTML.hpp"
#include "undo.hpp"
#include <memory>

class Controller
{
public:
    explicit Controller(Repository<Event>& _repo) : repo(_repo){}

    Repository<Event> * GetRepo();
    int GetRepoSize();
    void AddToRepo(std::string, std::string, std::string, int, std::string, int); //adds in repo an Event initialized with thse parameters
    void RemoveFromRepo(std::string);
    void UpdateInRepo(std::string, std::string, std::string, int, std::string, int);
    std::string GetRepoElemOnPosStr(int);
    void AccesEventPage(int);
    int GetMonthOnPos(int);
    void AddInUserList(Event e);
    void RemoveFromUserList(Event e);
    std::vector<Event>::iterator GetElemOnPosRepo(int);
    int GetUserListSize();
    std::string GetUserListElemOnPosStr(int);
    void WriteInFile(std::string str);
    void SetEventList(EventList*);
    void SaveListToFile();
    void DisplayList();
    void undo();
    void redo();

private:
    Repository<Event> repo;
    Repository<Event> user_list;
    EventList* el{};
    std::vector<std::shared_ptr<UndoAction>> undos; //ca mai copiez constructoru once in a while(referinta in ui/gui)
    std::vector<std::shared_ptr<UndoAction>> redos;
};

#endif //LAB5_6_CONTROLLER_HPP

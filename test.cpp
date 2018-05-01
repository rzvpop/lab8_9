#include "event.hpp"
#include "controller.hpp"
#include <cassert>

class Tests
{
public:
    void TestCtrl()
    {
        Repository<Event> repo;
        Controller ctrl(repo);

        ctrl.AddToRepo("1", "", "", 0, "", 0);
        ctrl.AddToRepo("Concert Parazitii Euphoria", "", "", 0, "", 0);
        ctrl.AddToRepo("2", "", "", 0, "", 0);
        ctrl.UpdateInRepo("Concert Parazitii Euphoria", "", "", 777, "https://www.facebook.com/events/164052010849321/");
        ctrl.RemoveFromRepo("2");

        assert(ctrl.GetRepoSize() == 2);

        ctrl.GetRepoElemOnPosStr(1);
        assert(ctrl.GetRepoElemOnPosStr(1) == "Concert Parazitii Euphoria; ; ; 777; https://www.facebook.com/events/164052010849321/; 0");
    }
};
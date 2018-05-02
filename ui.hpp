#ifndef LAB5_6_UI_HPP
#define LAB5_6_UI_HPP

#include "controller.hpp"
#include <cstring>
#include "valid.hpp"
#include <fstream>

class UI
{
public:
    explicit UI(Controller& _ctrl) : ctrl(_ctrl) {}

    void ReadFromFile(std::string);

    void AddUIAdm();
    void DeleteUIAdm();
    void UpdateUIAdm();
    void PrintUIAdm();

    void PrintByMonthUser();
    void DeleteFromUserList();
    void SeeUserList();
    void SaveListToFile();
    void DisplayList();

    void UiAdmin();
    void UIUser();

    void StartUI();

private:
    Controller ctrl;

    void HelpAdm();
    void HelpUser();
};


#endif //LAB5_6_UI_HPP

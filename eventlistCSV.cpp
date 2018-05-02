#include "eventlistCSV.hpp"

#include <fstream>
#include <Windows.h>

void EventListCSV::WriteToFile()
{
    std::ofstream fout(filename);

    if(!fout.is_open())
        throw FileException("File couldn't be opened!");

    for(auto &s : usr_events)
        fout << s << '\n';

    fout.close();
}

void EventListCSV::Display()
{
    std::string aux = "\"" + filename + "\"";

    //ShellExecute(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\Office14\\excel.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
    ShellExecute(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::string FileException::GetMsg() const
{
    return message;
}

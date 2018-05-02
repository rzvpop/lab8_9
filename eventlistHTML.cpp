#include "eventlistHTML.hpp"
#include <fstream>
#include <Windows.h>

void EventListHTML::WriteToFile()
{
    std::ofstream fout(filename);

    fout << "<!DOCTYPE html>";
    fout << "";
        fout << "<head>";
            fout << "<title></title>";
        fout << "</head>";

    fout << "<body>";
        fout << "<table border=1>";

            fout << "<th>";
                fout << "<td>Title</td>";
                fout << "<td>Description</td>";
                fout << "<td>Date</td>";
                fout << "<td>Number of people</td>";
                fout << "<td>Source</td>";
                fout << "<td>Duration</td>";
            fout << "</th>";



        fout << "</table>";
    fout << "</body>";

    fout << "</html>";

    fout.close();
}

void EventListHTML::Display()
{
    std::string aux = "\"" + filename + "\"";

    ShellExecute(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
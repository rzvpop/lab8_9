#include "eventlistHTML.hpp"
#include <fstream>

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

            for (auto &usr_event : usr_events)
            {
                fout << "<tr>";
                    fout << "<td>" << usr_event.GetTitle() << "</td>";
                    fout << "<td>" << usr_event.GetDesc() <<"</td>";
                    fout << "<td>" << usr_event.GetDate() <<"</td>";
                    fout << "<td>" << usr_event.GetNrPeople() <<"</td>";
                    fout << "<td><a href='"<< usr_event.GetSource() << "' target='_blank'>link</a></td>";
                    fout << "<td>" << usr_event.GetDuration() <<"</td>";
                fout << "</tr>";
            }

        fout << "</table>";
    fout << "</body>";

    fout << "</html>";

    fout.close();
}

void EventListHTML::Display()
{
    std::string run_str = "firefox ";
    run_str += "./" + filename;
    const char *cmd = run_str.c_str();
    FILE * fd = popen(cmd, "w");
    fclose(fd);

    //ShellExecute(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
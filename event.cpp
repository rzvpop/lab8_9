//#include <cstdlib>
#include <unistd.h>
#include "event.hpp"

Event::Event() : title(""), description(""), date_time(""), nr_people(0), source("")
{
}

Event::Event(std::string _title, std::string _desc, std::string _dt, int _nrp, std::string _source, int _duration)
{
    title = std::move(_title);
    description = std::move(_desc);
    date_time = std::move(_dt);
    nr_people = _nrp;
    source = std::move(_source);
    duration = _duration;
}

std::string Event::GetTitle() const
{
    return title;
}

void Event::SetTitle(std::string _title)
{
    title = std::move(_title);
}

std::string Event::GetDesc() const
{
    return description;
}

void Event::SetDesc(std::string _desc)
{
    description = std::move(_desc);
}

std::string Event::GetDate() const
{
    return date_time;
}

void Event::SetDate(std::string _dt)
{
    date_time = std::move(_dt);
}

int Event::GetNrPeople()
{
    return nr_people;
}

void Event::SetNrPeople(int _nrp)
{
    nr_people = _nrp;
}

std::string Event::GetSource() const
{
    return source;
}

void Event::SetSource(std::string _source)
{
    source = std::move(_source);
}

std::string Event::GetStr() const
{
    std::string str_nr_people = std::to_string(nr_people);
    std::string str_duration = std::to_string(duration);

    std::string str_event = title + ", " + description + ", " + date_time + ", " + str_nr_people + ", " + source + ", " + str_duration;
    return str_event;
}

int Event::operator ==(const Event &e) const
{
    return title == e.title;
}

void Event::AccesPage() const
{
    //std::system("./chrome.sh");
    //execl("/usr/bin/firefox", "google.com", (char *) NULL);

    std::string run_str = "firefox ";
    run_str += source;
    const char * cmd = run_str.c_str();
    FILE * fd = popen(cmd, "w");
    fclose(fd);
}

int Event::GetMonth() const
{
    int month = 0;
    size_t dash = 0;
    dash = date_time.find('-');

    for(int i = (int)dash + 1; date_time[i] >= '0' && date_time[i] <= '9'; i++)
        month = month * 10 + (date_time[i] - '0');

    return month;
}

int Event::operator <(const Event& e) const
{
    return this->duration < e.GetDuration();
}

int Event::GetDuration() const
{
    return duration;
}

void Event::SetDuration(int _duration)
{
    duration = _duration;
}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while(getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::ostream &operator<<(std::ostream &os, const Event& e)
{
    os << e.title << ", " << e.description << ", " << e.date_time << ", " << e.nr_people << ", " << e.source << ", " << e.duration;
    return os;
}

std::istream &operator>>(std::istream &is, Event &e)
{
    std::string line;
    std::getline(is, line);

    std::vector<std::string> tokens = tokenize(line, ',');

    if( tokens.size() == 6)
    {
        e.SetTitle(tokens[0]);
        e.description = tokens[1];
        e.date_time = tokens[2];
        e.nr_people = atoi(tokens[3].c_str());
        e.source = tokens[4];
        e.duration = atoi(tokens[5].c_str());
    }

    return is;
}

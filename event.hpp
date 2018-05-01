#ifndef LAB5_6_EVENT_HPP
#define LAB5_6_EVENT_HPP

#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <sstream>
#include <string>
#include <vector>

class Event
{
public:
    Event();
    Event(std::string, std::string, std::string, int, std::string, int duration = 0);

    std::string GetTitle() const;
    void SetTitle(std::string);

    int GetDuration() const;
    void SetDuration(int);

    std::string GetDesc() const;
    void SetDesc(std::string);

    std::string GetDate() const;
    void SetDate(std::string);

    int GetNrPeople();
    void SetNrPeople(int);

    std::string GetSource() const;
    void SetSource(std::string);

    int GetMonth() const;

    int operator ==(const Event&) const;
    int operator <(const Event&) const;
    //Event& operator =(const Event&);

    void AccesPage() const;
    std::string GetStr() const;

    friend std::istream& operator >>(std::istream&, Event&);
    friend std::ostream& operator <<(std::ostream&, const Event&);

private:
    std::string title, description, date_time, source;
    int nr_people, duration; //duration in minutes
};

#endif //LAB5_6_EVENT_HPP

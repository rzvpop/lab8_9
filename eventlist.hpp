#ifndef LAB8_9_EVENTLIST_HPP
#define LAB8_9_EVENTLIST_HPP

#include "event.hpp"

class EventList
{
public:
    EventList() : filename("") {};
    virtual ~EventList() {};

    void SetFilename(std::string);
    void SetVector(std::vector<Event>&);
    virtual void WriteToFile() = 0;
    virtual void Display() = 0;

protected:
    std::string filename;
    std::vector<Event> usr_events;
};


#endif //LAB8_9_EVENTLIST_HPP

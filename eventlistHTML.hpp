#ifndef LAB8_9_EVENTLISTHTML_HPP
#define LAB8_9_EVENTLISTHTML_HPP

#include "eventlist.hpp"

class EventListHTML : public EventList
{
public:
    void WriteToFile() override;
    void Display() override;
};


#endif //LAB8_9_EVENTLISTHTML_HPP

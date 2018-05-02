#include "eventlist.hpp"

#include <utility>

void EventList::SetVector(std::vector<Event> &v)
{
    usr_events = v;
}

void EventList::SetFilename(std::string fn)
{
    filename = std::move(fn);
}

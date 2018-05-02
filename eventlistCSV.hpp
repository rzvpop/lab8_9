#ifndef LAB8_9_EVENTLISTCSV_HPP
#define LAB8_9_EVENTLISTCSV_HPP

#include "eventlist.hpp"

class EventListCSV : public EventList
{
public:
    void WriteToFile() override;
    void Display() override;
};

class FileException
{
public:
    explicit FileException(std::string _msg) : message(std::move(_msg)) {}
    std::string GetMsg() const;

private:
    std::string message;
};

#endif //LAB8_9_EVENTLISTCSV_HPP

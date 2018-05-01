#ifndef LAB5_6_COMPARATOR_HPP
#define LAB5_6_COMPARATOR_HPP

#include "event.hpp"

class Comparator
{
public:
    virtual const bool compare(const Event&, const Event&) const = 0;
};

class ComparatorAscendingByTitle : public Comparator
{
public:
    const bool compare(const Event&, const Event&) const;
};

class ComparatorDescendingByMonth : public Comparator
{
public:
    const bool compare(const Event&, const Event&) const;
};

#endif //LAB5_6_COMPARATOR_HPP

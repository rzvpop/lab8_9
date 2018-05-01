#include "comparator.hpp"

const bool ComparatorAscendingByTitle::compare(const Event &e1, const Event &e2) const
{
    return e1.GetTitle() < e2.GetTitle();
}

const bool ComparatorDescendingByMonth::compare(const Event &e1, const Event &e2) const
{
    return e1.GetMonth() > e2.GetMonth();
}

#include "repository.hpp"

template<typename T>
void Repository<T>::Add(const T& e)
{
    typename std::vector<T>::iterator it = std::find(elems.begin(), elems.end(), e);

    if(it == elems.end())
        elems.push_back(e);
    else
        throw RepoException{ "Element already exists!" };
}

template<typename T>
void Repository<T>::Remove(const T& e)
{
    typename std::vector<T>::iterator it = std::find(elems.begin(), elems.end(), e);

    if(it != elems.end())
        elems.erase(it);
    else
        throw RepoException{ "Element doesn't exist!" };
}

template<typename T>
int Repository<T>::Find(const T& e) const
{
    typename std::vector<T>::const_iterator it = std::find(elems.begin(), elems.end(), e);

    if(it != elems.end())
        return static_cast<int>(it - elems.begin());

    return -1;
}

template<typename T>
int Repository<T>::GetNrElems() const
{
    return static_cast<int>(elems.size());
}

template<typename T>
std::vector<T>& Repository<T>::GetVector()
{
    return elems;
}

template<typename T>
void Repository<T>::Replace(const T& e)
{
    typename std::vector<T>::iterator it = std::find(elems.begin(), elems.end(), e);

    if(it!= elems.end())
    {
        *it= e;
    }
    else
        throw RepoException{ "Element doesn't exist!" };
}

template<typename T>
std::string Repository<T>::GetStrOnPos(int pos) const
{
    if(pos < elems.size())
    {
        return elems[pos].GetStr();
    }
    else
        throw RepoException{ "Element doesn't exist!" };

    return "";
}

template<typename T>
typename std::vector<T>::iterator Repository<T>::GetEventOnPos(int i)
{
    if(elems.begin() + i != elems.end())
        return elems.begin() + i;
    else
        throw RepoException{ "Element doesn't exist!" };
}

template<typename T>
void Repository<T>::Sort()
{
    //std::sort(elems.begin(), elems.end(), [](Event a, Event b){return a.GetDate() < b.GetDate();});

    Comparator *cmp = new ComparatorDescendingByMonth;
    sort(elems, cmp);
    delete cmp;
}

template<typename T>
void Repository<T>::SortByDur()
{
    std::sort(elems.begin(), elems.end());
}

template class Repository<Event>;

std::string RepoException::GetMsg() const
{
    return message;
}

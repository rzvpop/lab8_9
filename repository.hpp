#ifndef LAB5_6_REPOSITORY_HPP
#define LAB5_6_REPOSITORY_HPP

#include <utility>
#include <vector>
#include <algorithm>
#include "comparator.hpp"
#include <algorithm>

template<typename T>
class Repository
{
public:
    Repository() {};

    typedef typename std::vector<T>::iterator iterator;

    void Add(const T&); //adds element in repo
    void Remove(const T&); // deletes element from repo, if it exists
    void Replace(const T&);
    int Find(const T&) const; //searches for element in repo(returns position or -1, if not found)
    int GetNrElems() const; //returns number of registrations
    std::vector<T>& GetVector(); //returns the dynamic array
    std::string GetStrOnPos(int) const;
    typename std::vector<T>::iterator GetEventOnPos(int);
    void Sort();
    void SortByDur();

private:
    std::vector<T> elems;
};

#endif //LAB5_6_REPOSITORY_HPP

template<typename T>
void sort(std::vector<T>& dv, Comparator* cmp)
{
    //std::sort(dv.begin(), dv.end(), cmp->compare);

    for(int i = 0; i < dv.size() - 1; i++)
        for(int j = i + 1; j < dv.size(); j++)
        {
            if(cmp->compare(dv[i], dv[j]) == 0)
            {
                Event aux = dv[i];
                dv[i] = dv[j];
                dv[j] = aux;
            }
        }
}

class RepoException
{
public:
    explicit RepoException(std::string _msg) : message(std::move(_msg)) {}
    std::string GetMsg() const;

private:
    std::string message;
};
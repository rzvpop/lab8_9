#ifndef LAB5_6_VALID_HPP
#define LAB5_6_VALID_HPP

#include <iostream>
#include <sstream>
#include <utility>

class Valid
{
public:
    int ValidateDate(std::string);
    int ValidateDate(std::string, int&, int&, int&, int&, int&);
};

class ValidatorException
{
public:
    explicit ValidatorException(std::string _msg) : message(std::move(_msg)) {}
    std::string GetMsg() const;

private:
    std::string message;
};

#endif //LAB5_6_VALID_HPP

#include "valid.hpp"

int Valid::ValidateDate(std::string str)
{
    size_t dash_1 = 0, dash_2 = 0, space = 0, colon = 0;
    int day = 0, month = 0, year = 0, hour = 0, minute = 0;

    dash_1 = str.find('-');

    if(dash_1 != std::string::npos)
        dash_2 = str.find('-', dash_1 + 1);
    else
        return 0;

    if(dash_2 != std::string::npos)
        space = str.find(' ', dash_2 + 1);
    else
        return 0;

    if(space != std::string::npos)
        colon = str.find(':', space + 1);
    else
        return  0;

    if(colon != std::string::npos)
    {
        //mai bag if-uri pt caracterele terminale
        for(int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
            day = day * 10 + (str[i] - '0');

        for(auto i = (int)(dash_1 + 1); str[i] >= '0' && str[i] <= '9'; i++)
            month = month * 10 + (str[i] - '0');

        for(auto i = (int)(dash_2 + 1); str[i] >= '0' && str[i] <= '9'; i++)
            year = year * 10 + (str[i] - '0');

        for(auto i = (int)(space + 1); str[i] >= '0' && str[i] <= '9'; i++)
            hour = hour * 10 + (str[i] - '0');

        for(auto i = (int)(colon + 1); str[i] >= '0' && str[i] <= '9'; i++)
            minute = minute * 10 + (str[i] - '0');
    }
    else
        return 0;

    if(day == 0 || month == 0 || year == 0 || hour == 0 || minute == 0)
        return 0;

    return 1;
}

int Valid::ValidateDate(std::string str, int &_day, int &_month, int &_year, int &_hour, int &_minute)
{
    size_t dash_1 = 0, dash_2 = 0, space = 0, colon = 0;

    dash_1 = str.find('-');

    if(dash_1 != std::string::npos)
        dash_2 = str.find('-', dash_1 + 1);
    else
        return 0;

    if(dash_1 != std::string::npos)
        dash_2 = str.find('-', dash_1 + 1);
    else
        return 0;

    if(dash_2 != std::string::npos)
        space = str.find(' ', dash_2 + 1);
    else
        return 0;

    if(space != std::string::npos)
        colon = str.find(':', space + 1);
    else
        return  0;

    if(colon != std::string::npos)
    {
        for(int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
            _day = _day * 10 + (str[i] - '0');

        for(auto i = (int)(dash_1 + 1); str[i] >= '0' && str[i] <= '9'; i++)
            _month = _month * 10 + (str[i] - '0');

        for(auto i = (int)(dash_2 + 1); str[i] >= '0' && str[i] <= '9'; i++)
            _year = _year * 10 + (str[i] - '0');

        for(auto i = (int)(space + 1); str[i] >= '0' && str[i] <= '9'; i++)
            _hour = _hour * 10 + (str[i] - '0');

        for(auto i = (int)(colon + 1); str[i] >= '0' && str[i] <= '9'; i++)
            _minute = _minute * 10 + (str[i] - '0');
    }
    else
        return 0;

    if(_day == 0 || _month == 0 || _year == 0 || _hour ==0 || _minute == 0)
        return 0;

    return 1;
}

std::string ValidatorException::GetMsg() const
{
    return message;
}

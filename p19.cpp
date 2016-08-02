#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

bool isleapyear(int year)
{
    return (year % 4 == 0) && 
          ((year % 100 != 0) || (year % 400 == 0));
}

int main(int argc, const char* argv[])
{
    int month = 1;
    int year = 1900;
    int weekday = 2;
    
    int acc = 0;
    while ((year * 100 + month) < 200012)
    {
        if (year > 1900)
            if (weekday == 1)
                acc++;
            
        switch(month)
        {
            case 2: 
                if (isleapyear(year))                  
                    weekday = (weekday + 1) % 7;
                break;
            case 4:
            case 6:
            case 9:
            case 11: 
                weekday = (weekday + 2) % 7;
                break;
            default: 
                weekday = (weekday + 3) % 7;
                break;
        }

        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    
    std::cout << acc << std::endl;
    
    return 0;
}

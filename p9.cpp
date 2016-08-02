#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
    for (int a = 1; a < 1000; ++a)
        for (int b = a; b < 1000; ++b)
        {
            int c = 1000 - a - b;
            if (a*a + b*b == c*c)
            {
                std::cout << a * b * c << std::endl;
                return 0;
            }
        }
    
    return 0;
}
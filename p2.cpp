#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
    const int LIMIT = 4000000;
    
    uint64_t sum = 0;
    int a = 1, b = 1;
    int c = b;
    while (c < LIMIT)
    {
        if (!(c % 2))
            sum += c;
        a = b;
        b = c;
        c = a + b;
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
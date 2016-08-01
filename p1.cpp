#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    uint64_t sum = 0;
    for (int i = 1; i < 1000; ++i)
    {
        if (!(i % 3) || !(i % 5))
            sum += i;
    }

    std::cout << sum << std::endl;
    
    return 0;
}
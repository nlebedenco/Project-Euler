#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
    uint64_t a = 0, b = 0;
    
    for (int i = 1; i <= 100; ++i)
    {
        a += i;
        b += i * i;
    }
    a *= a;
    std::cout << a - b << std::endl;
    return 0;
}
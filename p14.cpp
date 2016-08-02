#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

uint64_t fun(uint64_t n)
{
    return (n % 2 == 0) ? n / 2 : 3 * n + 1;
}

uint64_t count(int n)
{
    uint64_t r = 2;    
    uint64_t k = fun(n);
    while (k != 1)
    {
        r++;
        k = fun(k);
    }
    return r;
}

int main(int argc, const char* argv[])
{
    int n = 0;
    uint64_t acc = 0;
    for (int i = 1; i < 1000000; ++i)
    {
        uint64_t k = count(i);
        if (acc < k)
        {
            n = i;
            acc = k;
        }
    }
    
    std::cout << n << std::endl;
    
    return 0;    
}

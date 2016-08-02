#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

bool isprime(int n)
{
    if (n < 2)
        return false;
        
    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0)
        return false;

    int k = (int)sqrt(n);
    for (int i = 3; i <= k; i += 2)
        if (n % i == 0)
            return false;
        
    return true;
}


int main(int argc, char* argv[])
{
    uint64_t acc = 0;
    for (int i = 0; i < 2000000; ++i)
    {
        if (isprime(i))
            acc += i;
    }
    
    std::cout << acc << std::endl;
    return 0;
}
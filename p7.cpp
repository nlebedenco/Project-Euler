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
    int n = 10000;
    int i = 1;
    while(n > 0)
    {
        i += 2;    
        if (isprime(i))
            n--;
    }

    std::cout << i << std::endl;
    
    return 0;
}
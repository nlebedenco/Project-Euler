#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>

int triangle(int n)
{       
    int i = 0;
    for (; n > 0; --n)
        i += n;
    
    return i;
}

int divisors(int n)
{
    int k = 2;
    int limit = (int)sqrt(n);
    for (int i = 2; i < limit; ++i)
        if (n % i == 0)
        {
            k += 2;
            limit = std::min(limit, n / i);
        }
    return k;
}

int main(int argc, const char* argv[])
{
    int n = 1;
    while (n < INT_MAX)
    {
        int t = triangle(n);
        if (divisors(t) > 500)    
        {
            std::cout << t << std::endl;
            return 0;
        }
        n++;
    }
    
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

int dsum(int n)
{
    if (n == 1) return 1;
    else if (n == 2) return 1+2;
    else if (n == 3) return 1+3;
    
    int acc = 1;
    int limit = (int)sqrt(n);
    for (int i = 2; i < limit; ++i)
        if (n % i == 0)
        {
            int k = n / i;
            limit = std::min(limit, k);
            acc += (i + k);
        }
    return acc;
}

int main(int argc, const char* argv[])
{
    int acc = 0;
    for (int a = 1; a < 10000; ++a)
    {
        int b = dsum(a);
        if (dsum(b) == a && a != b)
            acc += a;
    }
    
    std::cout << acc << std::endl;
  
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int N = 50000;

bool abundant[N] = {0};
bool issum[N] = {0};

int dsum(int n)
{
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else if (n == 3) return 1;
    
    int acc = 1;
    int limit = (int)sqrt(n);
    for (int i = 2; i <= limit; ++i)
        if (n % i == 0)
        {
            int k = n / i;
            limit = std::min(limit, k);
            acc += i;
            if (i != k) acc += k;
        }
    return acc;
}


int main(int argc, const char* argv[])
{
    for (int i = 1; i < N; ++i)
        if (dsum(i) > i)
        {
            abundant[i] = true;
            for (int j = 1; j <=i; ++j)
                if (abundant[j] && ((i+j) < N))
                    issum[i+j] = true;
        }

    uint64_t acc = 0;
    for (int i = 1; i < N; ++i)
        if (!issum[i])
            acc += i;

    std::cout << acc << std::endl;
    return 0;
}

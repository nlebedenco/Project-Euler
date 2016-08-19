#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int P = 5;

int main(int argc, const char* argv[])
{
    uint64_t sum = 0;
    int n = 2;
    while (n < 1000000)
    {
        int k = n;
        int acc = 0;
        while (k > 0 && acc < n)
        {
            int i = k % 10;
            acc += (int)pow(i, P);
            k /= 10;
        }

        if (k == 0 && acc == n)
        {
            sum += acc;
            printf("%d\n", n);
        }
        
        n++;
    }
    
    printf("SUM: %lld\n", sum);
    
    return 0;
}
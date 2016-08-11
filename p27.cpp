#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int N = 1001;

const int P = 2*N*N + N + 1;

bool prime[P] = {0};

int consecutiveNprimes(int a, int b)
{
    int acc = 0;
    for (int n = 0; n <= N; n++)
    {
        int64_t k = n * n + a * n + b;
        if (k >= P)
        {
            printf("k > P == %lld > %d", k, P);
            exit(EXIT_FAILURE);
        }
        
        if (prime[k])
            acc++;
        else 
            break;
    }
    
    return acc;
}

int main(int argc, const char* argv[])
{
    // build our table of primes
    prime[2] = true;
    for (int i = 3; i < P; ++i)
    {
        int limit = sqrt(i);
        if (i % 2 == 0)
            goto NotPrime;
        for (int j = 3; j <= limit; j += 2)
            if (prime[j] && (i % j == 0))
                goto NotPrime;
                
        prime[i] = true;
        continue;
        
        NotPrime:;
    }
    
    // Search
    int n = 0;
    int vA = 0;
    int vB = 0;
    for (int64_t a = -N+1; a < N; ++a)
        if (prime[abs(a)])
            for (int64_t b = -N; b <= N; ++b)
                if (prime[abs(b)])
                {
                    int k = consecutiveNprimes(a, b);
                    if (k > n)
                    {
                        n = k;
                        vA = a;
                        vB = b;
                    }
                }

    printf("n: %d | a: %d | b: %d | product: %d\n", n, vA, vB, vA * vB);
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int P = 1000;
const int n = 1000;
uint8_t v[n] = {0};

int main(int argc, const char* argv[])
{
    v[n-1] = 2;
    
    for (int i = 1; i < P; ++i) 
    {
        uint8_t carry = 0;
        for (int j = n-1; j >= 0; --j)
        {
            v[j] *= 2;
            v[j] += carry;
            carry = v[j] / 10;
            v[j] %= 10;
        }
    }

    uint64_t acc = 0;
    for (int i = 0; i < n; ++i) 
      acc += v[i];
      
    printf("%lld\n", acc);
    
    return 0;
}



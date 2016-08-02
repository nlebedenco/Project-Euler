#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int n = 10000;
int v[n] = {0};

int main(int argc, const char* argv[])
{
    v[n-1] = 1;
    for (int k = 1; k <= 100; ++k)
    {
        int carry = 0;
        for (int i = n-1; i >= 0; --i)
        {
            v[i] *= k;
            v[i] += carry;
            carry = v[i] / 10;
            v[i] %= 10;
        }
    }

    int acc = 0;
    for (int i = 0; i < n; ++i)
        acc += v[i];
    
    std::cout << acc << std::endl;
    
    return 0;
}

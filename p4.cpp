#include <iostream>
#include <cstdio>
#include <cstdlib>

bool ispalindrome6(int k)
{
    if (k < 100000 || k > 999999)
        return false;

    int h1 = k / 1000;
    int h2 = k % 1000;
    int h3 = 0;
    while (h2 > 0)
    {
        h3 *= 10;
        h3 += (h2 % 10);
        h2 /= 10;
    }  
    
    return h1 == h3;
}

int main(int argc, char* argv[])
{
    int r = 0;
    for (int i = 999; i > 99; --i)
        for (int j = i; j > 99; --j)
        {    
            int k = i * j;
            if (ispalindrome6(k) && k > r)
                r = k;
        }

    std::cout << r << std::endl;
    return 0;
}
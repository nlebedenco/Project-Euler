#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
    uint64_t n = 600851475143;
    
    uint64_t i = 2;
    while (i < n)
    {
        if (n % i == 0)
            n = n / i;
        else 
            i++;
    }
    
    std::cout << i << std::endl;
    
    return 0;
}
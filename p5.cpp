#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

int main(int argc, char* argv[])
{   
    int terms[20];
    for (int i = 0; i < 20; ++i)
        terms[i] = i+1;
        
    uint64_t acc = 1;
    
    for (int i = 2; i <= 20; ++i)
    {
        int k = terms[i-1];
        if (k > 1)
        {
            acc *= k;
            for (int j = i-1; j < 20; ++j)
            {
                if (terms[j] % k == 0)
                    terms[j] /= k; 
            }
        }
    }
    
    std::cout << acc << std::endl;
   
    return 0;
}


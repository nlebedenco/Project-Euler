#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

int length(int d)
{
    int remainder[1000] = {0};
    
    int n = 0;
    int num = 1;
    while (true)
    {       
        int r = num % d;
        
        if (r == 0)
            return 0;
        
        switch (remainder[r])
        {
            case 1:
                n++;
            case 0:
                remainder[r]++;  
                break;
            default:
                return n;
        }      
        
        num = r * 10;
    }   
}

int main(int argc, const char* argv[])
{   
    int k = 0;
    int n = 0;
      
    for (int d = 1; d < 1000; ++d)
    {
        int l = length(d);
        std::cout << d << ": " << l << std::endl;
        
        if (l > n)
        {
            n = l;
            k = d;
        }
    }
    
    std::cout << k << std::endl;
    
    return 0;
}
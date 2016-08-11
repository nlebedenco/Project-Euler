#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

// 43 44 45 46 47 48 49
// 42 21 22 23 24 25 26
// 41 20  7  8  9 10 27
// 40 19  6  1  2 11 28
// 39 18  5  4  3 12 29
// 38 17 16 15 14 13 30
// 37 36 35 34 33 32 31

const int D = 1001;

int main(int argc, const char* argv[])
{

// i d k         a[0] a[1] a[2] a[3]
// ---------------------------------
// 0 1            1 
// 1 3 +2         3    5    7    9
// 2 5 +2+2      13   17   21   25
// 3 7 +2+2+2    31   37   43   49

    uint64_t acc = 1;
    int a = 1;
    for (int k = 2; (k + 1) <= D; k += 2)
    {      
        acc += ((a + 1 * k)
              + (a + 2 * k)
              + (a + 3 * k)
              + (a + 4 * k));
        
        a += 4 * k;
    }
    
    std::cout << acc << std::endl;
    return 0;
}

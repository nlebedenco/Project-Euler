#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int n = 101;
uint64_t M[n][n] = {0};

int main(int argc, const char* argv[])
{
    std::ifstream input;
    input.open("p67.input.txt");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
        {
            input >> M[i][j];
        }
            
    input.close();
             
    for (int i = 1; i < n; ++i)
        M[i][0] += M[i-1][0];
    
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= i; ++j)
            M[i][j] += std::max(M[i-1][j], M[i-1][j-1]);
    
    uint64_t acc = 0;
    for (int j = 0; j < n; ++j)
    {   
        uint64_t k = M[n-1][j];
        if (acc < k)
            acc = k;
    }
    
    std::cout << acc << std::endl;
    
    return 0;
}
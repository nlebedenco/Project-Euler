#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

// The grid can be imagined as a weighted directed graph. All outgoing edges
// of a vertex have a weight that is equal to the number of ways we can get 
// that vertex. And this number is the sum of weights of all incoming edges of the
// same vertex. As a consequence all top and left border edges have a weight of 1
// and the remaining can be calculated.

const int L = 20;
const int N = L + 1;

uint64_t M[N][N] = {0};

int main(int argc, const char* argv[])
{
    for (int i = 0; i < N; ++i)
        M[i][0] = M[0][i] = 1;
        
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            M[i][j] = M[i-1][j] + M[i][j-1];
    
    std::cout << M[N-1][N-1] << std::endl;
    
    return 0;
}
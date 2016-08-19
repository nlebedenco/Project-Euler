#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

const int BUDGET = 200;
const int N = 8;
const int V[N] = {200, 100, 50, 20, 10, 5, 2, 1};

int use[N] = {0};
int count = 0;

void P(int k, int choices, int budget)
{
    if (choices > 0 && budget > 0)
    {
        for (int i = k; i < N; ++i)
        {
            int STATES = budget / V[i];
            for (int state = 1; state <= STATES; ++state)
            {
                use[i] = state;
                P(i+1, choices-1, budget - (V[i] * state));
                use[i] = 0;
            }
        }
    }
    else if (choices == 0 && budget == 0)
    {
        count++;
        for (int i = 0; i < N; ++i)
            printf("%3d ", use[i]);
        printf("\n");
    }
}

int main(int argc, const char* argv[])
{   
    for (int i = 0; i < N; ++i)
        printf("%3d ", V[i]);
    printf("\n---------------------------------\n");
        
    for (int i = 0; i < N; ++i)
    {
        P(0, i+1, BUDGET);
        printf("\n");
    }
        
    printf("Total: %d\n", count);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>

const int N = 10;
const int PERMUTATION = 1000000;

bool used[N] = {0};
int d[N] = {0};
int n = 0;

void print()
{
    for (int i = 0; i < N; ++i)
        printf("%d", d[i]);
    printf("\n");
}

void next(int i)
{
    if (i < N)
    {
        for (int k = 0; k < N; ++k)
        {
            if (!used[k])
            {
                d[i] = k;
                used[k] = true;
                next(i+1);
                used[k] = false;
            }
        }
    }
    else 
    {
        n++;
        // print();
        if (n == PERMUTATION)
        {
            print();
            exit(0);
        }
    }
}

int main(int argc, const char* argv[])
{
    next(0);
    return 0;
}
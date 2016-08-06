#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <vector>
#include <algorithm>

typedef std::vector<uint8_t> bigint;


void print(const bigint& v)
{
    for (bigint::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        int k = *it;
        if (k < 0 || k > 9)
        {
            fprintf(stderr, "Invalid number");
            exit(EXIT_FAILURE);
        }
        printf("%d", k);        
    }
    printf("\n");  
}

bigint add(const bigint& a, const bigint& b)
{
    bigint c;
    int na = a.size();
    int nb = b.size();
    int carry = 0;
    for (int i = 0; i < std::max(na, nb); ++i)
    {
        int va = (i < na) ? a[i] : 0;
        int vb = (i < nb) ? b[i] : 0;
        int vc = va + vb + carry;
        c.push_back(vc % 10);
        carry = vc / 10;
    }
    
    if (carry)
        c.push_back(1);
        
    return c;
}


int main(int argc, const char* argv[])
{
    const int DIGITS = 1000;
    
    bigint a({1});
    bigint b({1});
    bigint c;
    
    int n = 2;
    while(c.size() < DIGITS)
    {   
        n++;
        c = add(a, b);
        b = a;
        a = c;                   
    }
    
    print(c);
    printf("N: %d\n", n);
    
    return 0;
}


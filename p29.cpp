#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>

struct Exponentiation
{
    int base;
    int power;
    
    Exponentiation(int a, int b)
    : base(a), power(b)
    {}
 };

Exponentiation Simplify(const Exponentiation& e)
{
    int minBase = 1;   
    int powerMultiplier = 0;
    
    int factor = 0;
    int factorCount = 0;
        
    int v = e.base;
    int k = 2;
    while (v > 1)
    {
        if (v % k == 0)
        {
            if (k > factor)
            {
             
                if (powerMultiplier == 0)
                    powerMultiplier = factorCount;
        
                if (powerMultiplier != factorCount)
                    return e;             
                    
                factor = k;
                minBase *= factor;
                factorCount = 1;
            }
            else 
            {
                factorCount++;
            }
            
            v /= k;
        }
        else
        {   
            k++;
        }
    }       
    
    if (powerMultiplier == 0)
        powerMultiplier = factorCount;
        
    if (powerMultiplier != factorCount)
        return e;
    
    return Exponentiation(minBase, e.power * powerMultiplier);
}

int main(int argc, const char* argv[])
{
    std::map<int, std::set<int>> exps;
    for (int a = 2; a <= 100; ++a)
        for (int b = 2; b <= 100; ++b)
        {
            Exponentiation e = Simplify(Exponentiation(a, b));
            exps[e.base].insert(e.power);
        }
    
    int n  = 0;
    for (auto it = exps.begin(); it != exps.end(); ++it)
        n += it->second.size();
    
    printf("%d\n", n);
    
    return 0;
}

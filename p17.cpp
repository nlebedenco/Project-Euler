#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>

uint8_t v[1001] = {0};

int main(int argc, const char* argv[])
{
    v[0] = 4; // zero
    v[1] = 3; // one
    v[2] = 3; // two
    v[3] = 5; // three
    v[4] = 4; // four
    v[5] = 4; // five
    v[6] = 3; // six 
    v[7] = 5; // seven
    v[8] = 5; // eight
    v[9] = 4; // nine
    v[10] = 3; // ten
    v[11] = 6; // eleven
    v[12] = 6; // twelve
    v[13] = 8; // thirteen
    v[14] = 8; // fourteen
    v[15] = 7; // fifteen
    v[16] = 7; // sixteen
    v[17] = 9; // seventeen
    v[18] = 8; // eighteen
    v[19] = 8; // nineteen
    v[20] = 6; // twenty
    v[30] = 6; // thirty
    v[40] = 5; // forty
    v[50] = 5; // fifty
    v[60] = 5; // sixty
    v[70] = 7; // seventy
    v[80] = 6; // eighty
    v[90] = 6; // ninety

    uint8_t thousand = 8;
    uint8_t hundred = 7;
    uint8_t conjunction = 3;
    
    for (int i = 0; i < 1000; ++i)
        if (v[i] == 0)
        {
            if (i < 100)
                v[i] = v[(i / 10) * 10] + (i % 10 > 0 ? v[i % 10] : 0);
            else
            {
                v[i] = v[i / 100] + hundred + ((i % 100) > 0 ? conjunction + v[(i % 100)] : 0);
            }
        }
    
    v[1000] = v[1] + thousand;
        
    uint64_t acc = 0;
    for (int i = 1; i < 1001; ++i)
        acc += v[i];
        
    std::cout << acc << std::endl;
    
    return 0;
}


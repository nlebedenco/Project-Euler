#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

int calc(const std::string& s)
{
    int acc = 0;
    for (int i = 0; i < s.size(); ++i)
        acc += s[i] - 'A' + 1;

    return acc;
}

int main(int argc, const char* argv[])
{
    std::vector<std::string> names;
    
    std::ifstream input;
    input.open("p22.input.txt");
    std::string s;
    while(!input.eof() && !input.fail())
    {
        std::getline(input, s, ',');
        if (s.size() >= 2)
            if (s.front() == '"' && s.back() == '"')
                s = s.substr(1, s.size()-2);
        names.push_back(s);
    }
    input.close();

    std::sort(names.begin(), names.end());
    
    uint64_t acc = 0;
    
    for (int i = 0; i < names.size(); ++i)
    {
        std::string& name = names[i];
        uint64_t score = calc(name) * (i+1);
        acc += score;
    }
       
    std::cout << acc << std::endl;
    
    return 0;
}
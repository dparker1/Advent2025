#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include "advent.h"

int day_1_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_1_1.txt");
    
    int pos = 50;
    int final_count = 0;
    std::string content;
    while(std::getline(ifile, content))
    {
        size_t content_len = content.length();
        int diff = std::stoi(content.substr(1, content_len - 1));
        if(content[0] == 'L')
        {
            diff *= -1;
        }
        pos += diff;
        while(pos < 0)
        {
            pos += 100;
        }
        while(pos > 99)
        {
            pos -= 100;
        }
        if(pos == 0)
        {
            final_count++;
        }
    }

    return final_count;
}

int day_1_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_1_1.txt");
    
    int pos = 50;
    int final_count = 0;
    std::string content;
    while(std::getline(ifile, content))
    {
        size_t content_len = content.length();
        int diff = std::stoi(content.substr(1, content_len - 1));
        if(content[0] == 'L')
        {
            diff *= -1;
        }
        if((pos == 0) & (diff < 0))
        {
            final_count--;
        }
        pos += diff;
        while(pos < 0)
        {
            final_count++;
            pos += 100;
        }
        while(pos > 99)
        {
            final_count++;
            pos -= 100;
        }
        if((pos == 0) & (diff < 0))
        {
            final_count++;
        }
    }
    return final_count;
}

int64_t check_numbers_2_1(int64_t begi, int64_t endi)
{
    int64_t s = 0L;
    for(int64_t i = begi; i <= endi; i++)
    {
        int b = (int)std::log10((long double) i);
        if (b % 2 == 0)
        {
            continue;
        }
        int64_t m = (int64_t) std::pow(10, (long double) (b/2+1));
        int64_t m1 = i / m;
        int64_t m2 = i % m;
        if(m1 == m2)
        {
            s += i;
        }
    }
    return s;
}

int64_t check_numbers_2_2(int64_t begi, int64_t endi)
{
    int64_t s = 0L;
    for (int64_t i = begi; i <= endi; i++)
    {
        std::string m = std::to_string(i);
        for (int j = 1; j <= m.length() / 2; j++)
        {
            std::string m1 = m.substr(0, j);
            bool matches = true;
            for (int k = j; k < m.length(); k += j)
            {
                if (m1 != m.substr(k, j))
                {
                    matches = false;
                    break;
                }
            }
            if (matches)
            {
                s += i;
                break;
            }
        }
    }
    return s;
}

int64_t day_2_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_2_1.txt");
    
    int64_t sum = 0;
    std::string content;
    std::getline(ifile, content);
    size_t comma_pos = -1;
    size_t dash_pos, begi, endi;
    while((comma_pos = content.find(",")) != std::string::npos)
    {
        dash_pos = content.find("-");
        begi = std::stoll(content.substr(0, dash_pos));
        endi = std::stoll(content.substr(dash_pos+1, comma_pos));
        sum += check_numbers_2_1(begi, endi);
        content.erase(0, comma_pos+1);
    }
    dash_pos = content.find("-");
    begi = std::stoll(content.substr(0, dash_pos));
    endi = std::stoll(content.substr(dash_pos+1, comma_pos));
    sum += check_numbers_2_1(begi, endi);
    
    return sum;
}

int64_t day_2_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_2_1.txt");

    int64_t sum = 0;
    std::string content;
    std::getline(ifile, content);
    size_t comma_pos = -1;
    size_t dash_pos, begi, endi;
    while ((comma_pos = content.find(",")) != std::string::npos)
    {
        dash_pos = content.find("-");
        begi = std::stoll(content.substr(0, dash_pos));
        endi = std::stoll(content.substr(dash_pos + 1, comma_pos));
        sum += check_numbers_2_2(begi, endi);
        content.erase(0, comma_pos + 1);
    }
    dash_pos = content.find("-");
    begi = std::stoll(content.substr(0, dash_pos));
    endi = std::stoll(content.substr(dash_pos + 1, comma_pos));
    sum += check_numbers_2_2(begi, endi);

    return sum;
}
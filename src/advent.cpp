#include <iostream>
#include <fstream>
#include <string>

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
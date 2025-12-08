#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

#include "advent.h"

int64_t day_1_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_1_1.txt");
    
    int pos = 50;
    int64_t final_count = 0;
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
    ifile.close();
    return final_count;
}

int64_t day_1_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_1_1.txt");
    
    int pos = 50;
    int64_t final_count = 0;
    std::string content;
    while(std::getline(ifile, content))
    {
        size_t content_len = content.length();
        int diff = std::stoi(content.substr(1, content_len - 1));
        if(content[0] == 'L')
        {
            diff *= -1;
        }
        if((pos == 0) && (diff < 0))
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
        if((pos == 0) && (diff < 0))
        {
            final_count++;
        }
    }
    ifile.close();
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
    ifile.close();
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
    ifile.close();
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

int64_t day_3_1()
{
    std::ifstream ifile;
    ifile.open("./data/test.txt");

    int64_t sum = 0;
    std::string content;
    while (std::getline(ifile, content))
    {
        
        size_t content_len = content.length();
        int max_num = 0;
        size_t max_num_i = 0;
        int x = 0;
        for (size_t i = 0; i < content_len - 1; i++)
        {
            x = content[i] - 48;
            if (x > max_num)
            {
                max_num = x;
                max_num_i = i;
            }
        }
        int curr_val = 10 * max_num;
        max_num = 0;
        for (size_t i = max_num_i + 1; i < content_len; i++)
        {
            x = content[i] - 48;
            if (x > max_num)
            {
                max_num = x;
            }
        }
        curr_val += max_num;
        sum += curr_val;
    }
    ifile.close();

    return sum;
}

int64_t day_3_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_3_1.txt");

    int64_t sum = 0;
    int digits = 12;
    std::string content;
    while (std::getline(ifile, content))
    {
        size_t content_len = content.length();
        int max_num = 0;
        int max_num_i = 0;
        int last_max_num_i = -1;
        int64_t curr_val = 0;
        int x = 0;
        for (int d = 0; d < digits; d++)
        {
            for (size_t i = last_max_num_i + 1; i < content_len - digits + d + 1; i++)
            {
                x = content[i] - 48;
                if (x > max_num)
                {
                    max_num = x;
                    max_num_i = i;
                }
            }
            curr_val = 10 * curr_val + max_num;
            max_num = 0;
            last_max_num_i = max_num_i;
        }
        sum += curr_val;
    }
    ifile.close();

    return sum;
}

int64_t day_4_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_4_1.txt");

    int64_t count = 0;
    std::vector<std::string> chars;

    std::string content;
    while (std::getline(ifile, content))
    {
        chars.push_back(content);
    }
    ifile.close();

    size_t size = chars.size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            int s = 0;
            int ilow = std::max<int>(0, i - 1);
            int ihigh = std::min<int>(size - 1, i + 1);
            int jlow = std::max<int>(0, j - 1);
            int jhigh = std::min<int>(size - 1, j + 1);
            for (int ii = ilow; ii <= ihigh; ii++)
            {
                for (int jj = jlow; jj <= jhigh; jj++)
                {
                    if ((ii == i) && (jj == j))
                    {
                        continue;
                    }
                    s += chars[ii][jj] == '@';
                }
            }
            if (chars[i][j] == '@')
            {
                count += s < 4;
            }
        }
    }
    return count;
}

int64_t day_4_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_4_1.txt");

    int64_t count = 0;
    std::vector<std::vector<int>> indicators;

    std::string content;
    while (std::getline(ifile, content))
    {
        std::vector<int> ind;
        for(std::string::iterator it = content.begin(); it != content.end(); it++)
        {
            ind.push_back(*it == '@'); // Dereference iterator to access character
        }
        indicators.push_back(ind);
    }
    ifile.close();

    size_t size = indicators.size();
    bool has_remain = true;
    while (has_remain)
    {
        has_remain = false;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (indicators[i][j] == -1)
                {
                    count++;
                    indicators[i][j] = 0;
                }
            }
        }
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                int s = 0;
                int ilow = std::max<int>(0, i - 1);
                int ihigh = std::min<int>(size - 1, i + 1);
                int jlow = std::max<int>(0, j - 1);
                int jhigh = std::min<int>(size - 1, j + 1);
                for (int ii = ilow; ii <= ihigh; ii++)
                {
                    for (int jj = jlow; jj <= jhigh; jj++)
                    {
                        if ((ii == i) && (jj == j))
                        {
                            continue;
                        }
                        s += indicators[ii][jj] != 0;
                    }
                }
                if ((indicators[i][j] != 0) && (s < 4))
                {
                    indicators[i][j] = -1;
                    has_remain = true;
                }
            }
        }
    }
    
    return count;
}

int64_t day_5_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_5_1.txt");

    int64_t count = 0;
    std::vector<std::vector<int64_t>> ranges;

    std::string content;
    while (std::getline(ifile, content))
    {
        size_t dash_pos = content.find('-');
        if (dash_pos != std::string::npos)
        {
            std::vector<int64_t> range;
            range.push_back(std::stoll(content.substr(0, dash_pos)));
            content.erase(0, dash_pos+1);
            range.push_back(std::stoll(content));
            ranges.push_back(range);
        }
        else
        {
            if (content.size() > 0)
            {
                int64_t val = std::stoll(content);
                for (std::vector<int64_t>& v : ranges)
                {
                    if ((val >= v[0]) && (val <= v[1]))
                    {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    ifile.close();
    return count;
}

int64_t day_5_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_5_1.txt");

    int64_t count = 0;
    std::vector<std::vector<int64_t>> ranges;

    std::string content;
    while (std::getline(ifile, content))
    {
        size_t dash_pos = content.find('-');
        if (dash_pos != std::string::npos)
        {
            std::vector<int64_t> range;
            range.push_back(std::stoll(content.substr(0, dash_pos)));
            content.erase(0, dash_pos + 1);
            range.push_back(std::stoll(content));
            ranges.push_back(range);
        }
    }
    ifile.close();

    std::sort(ranges.begin(), ranges.end(), [](std::vector<int64_t> a, std::vector<int64_t> b)
    {
        return a[0] < b[0];
    });

    int64_t curr_lower = ranges[0][0];
    int64_t curr_upper = ranges[0][1];
    for (size_t i = 1; i < ranges.size(); i++)
    {
        if (curr_upper >= ranges[i][0])
        {
            curr_upper = std::max<int64_t>(ranges[i][1], curr_upper);
        }
        else
        {
            count += curr_upper - curr_lower + 1;
            curr_lower = ranges[i][0];
            curr_upper = ranges[i][1];
        }
    }
    count += curr_upper - curr_lower + 1;
    
    return count;
}

int64_t add(int64_t x, int64_t y)
{
    return x + y;
}

int64_t mult(int64_t x, int64_t y)
{
    return x * y;
}

int64_t day_6_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_6_1.txt");

    int64_t sum = 0;
    std::vector<std::string> rows;
    std::vector<std::vector<std::int64_t>> numeric_rows;

    std::string content;
    while (std::getline(ifile, content))
    {
        rows.push_back(content);
    }
    ifile.close();

    size_t i;
    for(i = 0; i < rows.size() - 1; i++)
    {
        std::vector<int64_t> numeric_row;
        std::istringstream content_stream(rows[i]);
        std::string tok;
        while (content_stream >> tok)
        {
            numeric_row.push_back(std::stoll(tok));
        }
        numeric_rows.push_back(numeric_row);
    }

    std::istringstream content_stream(rows.back());
    std::string tok;
    size_t j = 0;
    while (content_stream >> tok)
    {
        int64_t(*agg_func)(int64_t, int64_t);
        int64_t val;
        if (tok.at(0) == '*')
        {
            agg_func = mult;
            val = 1;
        }
        else
        {
            agg_func = add;
            val = 0;
        }
        
        for (i = 0; i < numeric_rows.size(); i++)
        {
            val = agg_func(val, numeric_rows[i][j]);
        }
        j++;
        sum += val;
    }

    return sum;
}

int64_t day_6_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_6_1.txt");

    int64_t sum = 0;
    std::vector<std::string> rows;
    std::vector<std::string> numeric_rows;

    std::string content;
    while (std::getline(ifile, content))
    {
        rows.push_back(content);
    }
    ifile.close();

    for (size_t i = 0; i < rows.size() - 1; i++)
    {
        numeric_rows.push_back(rows[i]);
    }

    std::vector<std::string> pivoted_rows;
    for (size_t i = 0; i < numeric_rows[0].size(); i++)
    {
        std::string r;
        for (size_t j = 0; j < numeric_rows.size(); j++)
        {
            r.push_back(rows[j][i]);
        }   
        pivoted_rows.push_back(r);
    }

    std::istringstream content_stream(rows.back());
    char tok;
    std::vector<char> ops;
    size_t j = 0;
    while (content_stream >> tok)
    {
        ops.push_back(tok);
    }

    int64_t(*agg_func)(int64_t, int64_t);
    int64_t agg_val;
    j = 0;
    if (ops[j] == '*')
    {
        agg_val = 1;
        agg_func = mult;
    }
    else
    {
        agg_val = 0;
        agg_func = add;
    }
    for (size_t i = 0; i < pivoted_rows.size(); i++)
    {
        if (pivoted_rows[i].find_first_not_of(' ') != std::string::npos)
        {
            int64_t val = std::stoll(pivoted_rows[i]);
            agg_val = agg_func(agg_val, val);
        }
        else
        {
            sum += agg_val;
            j++;
            if (ops[j] == '*')
            {
                agg_val = 1;
                agg_func = mult;
            }
            else
            {
                agg_val = 0;
                agg_func = add;
            }
        }
    }
    sum += agg_val;

    return sum;
}

int64_t day_7_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_7_1.txt");

    int64_t count = 0;
    std::vector<std::string> rows;
    std::string content;
    while (std::getline(ifile, content))
    {
        rows.push_back(content);
    }
    ifile.close();

    size_t i, j;
    for (i = 1; i < rows.size(); i++)
    {
        for (j = 0; j < rows[i].size(); j++)
        {
            switch (rows[i][j])
            {
            case '.':
                if ((rows[i - 1][j] == '|') || (rows[i - 1][j] == 'S'))
                {
                    rows[i][j] = '|';
                }
                break;
            case '^':
                if (rows[i - 1][j] == '|')
                {
                    count++;
                    if ((j < rows[i].size() - 1) && (rows[i][j + 1] != '^'))
                    {
                        rows[i][j + 1] = '|';
                    }
                    if ((j > 0) && (rows[i][j - 1] != '^'))
                    {
                        rows[i][j - 1] = '|';
                    }
                }
                
            }
            
        }
    }

    return count;
}

int64_t day_7_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_7_1.txt");

    int64_t count = 0;
    std::vector<std::string> rows;
    std::string content;
    while (std::getline(ifile, content))
    {
        rows.push_back(content);
    }
    ifile.close();

    size_t i, j;
    std::vector<uint64_t> curr_path_counts;
    std::vector<std::vector<uint64_t>> path_counts;
    for (j = 0; j < rows[0].size(); j++)
    {
        uint64_t count = rows[0][j] == 'S';
        curr_path_counts.push_back(count);
    }
    path_counts.push_back(curr_path_counts);

    for (i = 1; i < rows.size(); i++)
    {
        for (j = 0; j < rows[i].size(); j++)
        {
            curr_path_counts[j] = 0;
        }
        std::vector<uint64_t> prev_path_counts = path_counts.back();
        for (j = 0; j < rows[i].size(); j++)
        {
            switch (rows[i][j])
            {
            case '.':
                if ((rows[i - 1][j] == '|') || (rows[i - 1][j] == 'S'))
                {
                    rows[i][j] = '|';
                    curr_path_counts[j] += prev_path_counts[j];
                }
                break;
            case '|':
                if ((rows[i - 1][j] == '|') || (rows[i - 1][j] == 'S'))
                {
                    curr_path_counts[j] += prev_path_counts[j];
                }
                break;
            case '^':
                if (rows[i - 1][j] == '|')
                {
                    if (j < rows[i].size() - 1)
                    {
                        rows[i][j + 1] = '|';
                        curr_path_counts[j + 1] += prev_path_counts[j];
                    }
                    if (j > 0)
                    {
                        rows[i][j - 1] = '|';
                        curr_path_counts[j - 1] += prev_path_counts[j];
                    }
                }
            }
        }
        path_counts.push_back(curr_path_counts);
    }
    for(uint64_t v : curr_path_counts)
    {
        count += v;
    }
    return count;
}

struct Vec3 
{
    int64_t x, y, z;
};

struct Vec2
{
    int64_t x, y;
};

struct CompVec
{
    Vec2 v;
    long double dist;
};

struct MinHeapComparator {
    bool operator()(CompVec a, CompVec b) {
        return a.dist > b.dist;
    }
};

long double vector_dist(Vec3 v1, Vec3 v2)
{
    return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2) + std::pow(v1.z - v2.z, 2));
}

int64_t day_8_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_8_1.txt");

    uint16_t n_connections = 1000;

    std::vector<Vec3> vectors;
    std::vector<size_t> positions;
    std::priority_queue<CompVec, std::vector<CompVec>, MinHeapComparator> comparisons;

    std::string content;
    size_t pos = 0;
    while (std::getline(ifile, content))
    {
        Vec3 v;

        size_t comma_pos = content.find(',');
        v.x = std::stoll(content.substr(0, comma_pos));
        content.erase(0, comma_pos + 1);
        comma_pos = content.find(',');
        v.y = std::stoll(content.substr(0, comma_pos));
        content.erase(0, comma_pos + 1);
        v.z = std::stoll(content);

        positions.push_back(pos++);
        vectors.push_back(v);
    }
    ifile.close();

    for (size_t i = 0; i < vectors.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vectors.size(); j++)
        {
            long double dist = vector_dist(vectors[i], vectors[j]);
            comparisons.push({ {(int64_t)i, (int64_t)j},  dist });
        }
    }

    size_t conns = 0;
    while(conns++ < n_connections)
    {
        Vec2 curr = comparisons.top().v;
        int64_t xpos = positions[curr.x];
        int64_t ypos = positions[curr.y];
        if (xpos != ypos)
        {
            for (size_t i = 0; i < positions.size(); i++)
            {
                if (positions[i] == ypos)
                {
                    positions[i] = xpos;
                }
            }
        }
        comparisons.pop();
    }

    std::unordered_map<uint64_t, size_t> counts;
    for (uint64_t v : positions)
        ++counts[v];

    int64_t product = 1;
    for (size_t i = 0; i < 3; i++)
    {
        int64_t max_count = 0;
        size_t max_j = 0;
        for (size_t j = 0; j < vectors.size(); j++)
        {
            if (counts[j] > max_count)
            {
                max_count = counts[j];
                max_j = j;
            }
        }
        counts.erase(max_j);
        product *= max_count;
    }

    return product;
}

int64_t day_8_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_8_1.txt");

    std::vector<Vec3> vectors;
    std::vector<size_t> positions;
    std::priority_queue<CompVec, std::vector<CompVec>, MinHeapComparator> comparisons;

    std::string content;
    size_t pos = 0;
    while (std::getline(ifile, content))
    {
        Vec3 v;

        size_t comma_pos = content.find(',');
        v.x = std::stoll(content.substr(0, comma_pos));
        content.erase(0, comma_pos + 1);
        comma_pos = content.find(',');
        v.y = std::stoll(content.substr(0, comma_pos));
        content.erase(0, comma_pos + 1);
        v.z = std::stoll(content);

        positions.push_back(pos++);
        vectors.push_back(v);
    }
    ifile.close();

    for (size_t i = 0; i < vectors.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vectors.size(); j++)
        {
            long double dist = vector_dist(vectors[i], vectors[j]);
            comparisons.push({ {(int64_t)i, (int64_t)j},  dist });
        }
    }

    bool all_same = false;
    int64_t product = 0;
    while (!all_same)
    {
        Vec2 curr = comparisons.top().v;
        int64_t xpos = positions[curr.x];
        int64_t ypos = positions[curr.y];
        product = vectors[curr.x].x * vectors[curr.y].x;
        if (xpos != ypos)
        {
            for (size_t i = 0; i < positions.size(); i++)
            {
                if (positions[i] == ypos)
                {
                    positions[i] = xpos;
                }
            }
        }
        int64_t p = positions[0];
        all_same = true;
        for (size_t i = 1; i < positions.size(); i++)
        {
            all_same &= positions[i] == p;
        }
        comparisons.pop();
    }

    return product;
}
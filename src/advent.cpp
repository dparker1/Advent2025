#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

#include <glpk.h>

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

int64_t day_9_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_9_1.txt");

    std::vector<Vec2> vectors;

    std::string content;
    while (std::getline(ifile, content))
    {
        Vec2 v;

        size_t comma_pos = content.find(',');
        v.x = std::stoll(content.substr(0, comma_pos));
        content.erase(0, comma_pos + 1);
        comma_pos = content.find(',');
        v.y = std::stoll(content.substr(0, comma_pos));

        vectors.push_back(v);
    }
    ifile.close();

    int64_t area = 0;
    int64_t max_area = 0;
    for (size_t i = 0; i < vectors.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vectors.size(); j++)
        {
            area = std::abs((vectors[i].x - vectors[j].x + 1) * (vectors[i].y - vectors[j].y + 1));
            max_area = std::max(max_area, area);
        }
    }

    return max_area;
}

bool line_intersect(std::vector<Vec2> line1, std::vector<Vec2> line2)
{
    int64_t d1 = (line1[1].x - line1[0].x) * (line2[0].y - line1[0].y) - (line1[1].y - line1[0].y) * (line2[0].x - line1[0].x);
    int64_t d2 = (line1[1].x - line1[0].x) * (line2[1].y - line1[0].y) - (line1[1].y - line1[0].y) * (line2[1].x - line1[0].x);
    int64_t d3 = (line2[1].x - line2[0].x) * (line1[0].y - line2[0].y) - (line2[1].y - line2[0].y) * (line1[0].x - line2[0].x);
    int64_t d4 = (line2[1].x - line2[0].x) * (line1[1].y - line2[0].y) - (line2[1].y - line2[0].y) * (line1[1].x - line2[0].x);
    return ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0));
}

bool is_inside(Vec2 p, std::vector<Vec2> vectors)
{
    bool inside = false;
    int64_t n = vectors.size();
    for (size_t ii = 0; ii < n; ii++)
    {
        size_t jj = (ii + n - 1) % n;
        if ((vectors[ii].y > p.y) != (vectors[jj].y > p.y))
        {
            int64_t x_int = (vectors[jj].x - vectors[ii].x) * (p.y - vectors[ii].y) / (vectors[jj].y - vectors[ii].y) + vectors[ii].x;
            if (p.x < x_int)
            {
                inside = !inside;
            }
        }
    }
    return inside;
}

int64_t day_9_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_9_1.txt");

    std::vector<Vec2> vectors;

    std::string content;
    while (std::getline(ifile, content))
    {
        Vec2 v;

        size_t comma_pos = content.find(',');
        v.x = std::stoll(content.substr(0, comma_pos));
        content.erase(0, comma_pos + 1);
        comma_pos = content.find(',');
        v.y = std::stoll(content.substr(0, comma_pos));

        vectors.push_back(v);
    }
    ifile.close();

    int64_t area = 0;
    int64_t max_area = 0;
    for (size_t i = 0; i < vectors.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vectors.size(); j++)
        {
            int64_t max_x = std::max(vectors[i].x, vectors[j].x);
            int64_t max_y = std::max(vectors[i].y, vectors[j].y);
            int64_t min_x = std::min(vectors[i].x, vectors[j].x);
            int64_t min_y = std::min(vectors[i].y, vectors[j].y);

            std::vector<Vec2> points_to_check;
            points_to_check.push_back({ min_x + 1, min_y + 1 });
            points_to_check.push_back({ min_x + 1, max_y - 1 });
            points_to_check.push_back({ max_x - 1, min_y + 1 });
            points_to_check.push_back({ max_x - 1, max_y - 1 });

            std::vector<std::vector<Vec2>> lines_to_check;
            lines_to_check.push_back({ points_to_check[0], points_to_check[1] });
            lines_to_check.push_back({ points_to_check[1], points_to_check[3] });
            lines_to_check.push_back({ points_to_check[3], points_to_check[2] });
            lines_to_check.push_back({ points_to_check[2], points_to_check[0] });

            bool all_inside = true;
            area = (std::abs(vectors[i].x - vectors[j].x) + 1) * (std::abs(vectors[i].y - vectors[j].y) + 1);
            if (area > max_area)
            {
                for (size_t pi = 0; pi < points_to_check.size(); pi++)
                {
                    bool inside = is_inside(points_to_check[pi], vectors);
                    if (!inside)
                    {
                        all_inside = false;
                        break;
                    }
                }
                if (all_inside)
                {
                    for (size_t li = 0; li < lines_to_check.size(); li++)
                    {
                        size_t ii;
                        for (ii = 1; ii < vectors.size(); ii++)
                        {
                            std::vector<Vec2> edge = { vectors[ii - 1], vectors[ii] };
                            if (line_intersect(lines_to_check[li], edge))
                            {
                                all_inside = false;
                                break;
                            }
                        }
                        if (all_inside)
                        {
                            std::vector<Vec2> edge = { vectors[0], vectors[ii - 1] };
                            if (line_intersect(lines_to_check[li], edge))
                            {
                                all_inside = false;
                            }
                        }

                        if (!all_inside)
                        {
                            break;
                        }
                    }
                }
                if (all_inside)
                {
                    max_area = std::max(max_area, area);
                }
            }
        }
    }

    return max_area;
}

int64_t day_10_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_10_1.txt");

    std::vector<int> buttons;
    std::vector<std::vector<int>> switches;
    std::vector<std::vector<int>> values;

    std::string content;
    while (std::getline(ifile, content))
    {
        size_t bracket_pos = content.find(']');
        std::string s_buttons = content.substr(1, bracket_pos-1);
        int b = 0;
        size_t i = 0;
        for(char c : s_buttons)
        {
            if (c == '#')
            {
                b |= (1 << i);
            }
            i++;
        }
        buttons.push_back(b);

        content.erase(0, bracket_pos + 2);

        size_t paren_pos1 = content.find('(');
        size_t paren_pos2 = content.find(')');
        size_t comma_pos;
        std::vector<int> curr_switches;
        while (paren_pos1 != std::string::npos)
        {
            int s = 0;
            std::string s_switches = content.substr(paren_pos1 + 1, paren_pos2 - 1);
            while ((comma_pos = s_switches.find(',')) != std::string::npos)
            {
                s |= 1 << std::stoi(s_switches.substr(0, comma_pos));
                s_switches.erase(0, comma_pos + 1);
            }
            s |= 1 << std::stoi(s_switches);
            content.erase(0, paren_pos2 + 2);
            paren_pos1 = content.find('(');
            paren_pos2 = content.find(')');
            curr_switches.push_back(s);
        }
        switches.push_back(curr_switches);

        bracket_pos = content.find('{');
        content.erase(0, bracket_pos + 1);
        std::vector<int> v;
        while ((comma_pos = content.find(',')) != std::string::npos)
        {
            v.push_back(std::stoi(content.substr(0, comma_pos)));
            content.erase(0, comma_pos + 1);
        }
        bracket_pos = content.find('}');
        v.push_back(std::stoi(content.substr(0, bracket_pos)));
        values.push_back(v);
    }
    ifile.close();

    int64_t sum = 0;
    for (size_t i = 0; i < buttons.size(); i++)
    {
        std::unordered_map<int, int> dict;
        std::queue<int> to_process;
        int curr_button = 0;
        int curr_button_val = 0;
        int new_button = 0;
        int curr_button_target = buttons[i];
        dict[0] = 0;
        to_process.push(0);
        while (dict.find(curr_button_target) == dict.end())
        {
            size_t n = to_process.size();
            for (size_t j = 0; j < n; j++)
            {
                curr_button = to_process.front();
                to_process.pop();
                curr_button_val = dict[curr_button];
                for (size_t k = 0; k < switches[i].size(); k++)
                {
                    new_button = curr_button ^ switches[i][k];
                    if (dict.find(new_button) != dict.end())
                    {
                        if (dict[new_button] > curr_button_val + 1)
                        {
                            dict[new_button] = curr_button_val + 1;
                            to_process.push(new_button);
                        }
                    }
                    else
                    {
                        dict[new_button] = curr_button_val + 1;
                        to_process.push(new_button);
                    }
                }
            }
        }
        sum += dict[curr_button_target];
    }

    return sum;
}

int64_t day_10_2()
{
    std::ifstream ifile;
    ifile.open("./data/input_10_1.txt");

    std::vector<std::vector<std::vector<int>>> switches;
    std::vector<std::vector<int>> values;

    std::string content;
    while (std::getline(ifile, content))
    {
        size_t bracket_pos = content.find(']');
        content.erase(0, bracket_pos + 2);

        size_t paren_pos1 = content.find('(');
        size_t paren_pos2 = content.find(')');
        size_t comma_pos;
        std::vector<std::vector<int>> curr_switches;
        while (paren_pos1 != std::string::npos)
        {
            std::vector<int> s;
            std::string s_switches = content.substr(paren_pos1 + 1, paren_pos2 - 1);
            while ((comma_pos = s_switches.find(',')) != std::string::npos)
            {
                s.push_back(std::stoi(s_switches.substr(0, comma_pos)));
                s_switches.erase(0, comma_pos + 1);
            }
            s.push_back(std::stoi(s_switches));
            content.erase(0, paren_pos2 + 2);
            paren_pos1 = content.find('(');
            paren_pos2 = content.find(')');
            curr_switches.push_back(s);
        }
        switches.push_back(curr_switches);

        bracket_pos = content.find('{');
        content.erase(0, bracket_pos + 1);
        std::vector<int> v;
        while ((comma_pos = content.find(',')) != std::string::npos)
        {
            v.push_back(std::stoi(content.substr(0, comma_pos)));
            content.erase(0, comma_pos + 1);
        }
        bracket_pos = content.find('}');
        v.push_back(std::stoi(content.substr(0, bracket_pos)));
        values.push_back(v);
    }
    ifile.close();

    int64_t sum = 0;

    int ia[1 + 1000], ja[1 + 1000];
    double a[1 + 1000];

    glp_term_out(GLP_OFF);

    for (size_t i = 0; i < values.size(); i++)
    {
        std::fill(std::begin(a), std::end(a), 0);
        int nrows = values[i].size();
        int ncols = switches[i].size();

        glp_prob* lp = glp_create_prob();

        glp_set_obj_dir(lp, GLP_MIN);
        glp_add_rows(lp, nrows);
        for (size_t j = 1; j <= nrows; j++)
        {
            glp_set_row_bnds(lp, j, GLP_FX, values[i][j - 1], values[i][j - 1]);
            for (size_t k = 1; k <= ncols; k++)
            {
                ia[(j - 1) * ncols + k] = j;
                ja[(j - 1) * ncols + k] = k;
            }
        }

        glp_add_cols(lp, ncols);
        for (size_t k = 1; k <= ncols; k++)
        {
            glp_set_col_bnds(lp, k, GLP_LO, 0, 0);
            glp_set_col_kind(lp, k, GLP_IV);
            glp_set_obj_coef(lp, k, 1);
            for (size_t l = 0; l < switches[i][k - 1].size(); l++)
            {
                a[switches[i][k - 1][l] * ncols + k] = 1;
            }
        }

        glp_load_matrix(lp, nrows * ncols, ia, ja, a);

        glp_iocp parm;
        glp_init_iocp(&parm);
        parm.presolve = GLP_ON;
        int err = glp_intopt(lp, &parm);

        sum += (int64_t)glp_mip_obj_val(lp);
        glp_delete_prob(lp);
    }
    glp_free_env();
    return sum;
}

int64_t day_11_1()
{
    std::ifstream ifile;
    ifile.open("./data/input_11_1.txt");

    std::unordered_map<std::string, std::vector<std::string>> edges;

    std::string content;
    while (std::getline(ifile, content))
    {
        std::vector<std::string> curr_edges;

        size_t colon_pos = content.find(':');
        std::string source = content.substr(0, colon_pos);
        content.erase(0, colon_pos + 1);

        std::istringstream content_stream(content);
        std::string tok;
        while (content_stream >> tok)
        {
            curr_edges.push_back(tok);
        }

        edges[source] = curr_edges;
    }
    ifile.close();

    std::queue<std::string> nodes_to_process;
    nodes_to_process.push("you");

    int64_t count = 0;
    while (nodes_to_process.size() > 0)
    {
        std::string curr_node = nodes_to_process.front();
        nodes_to_process.pop();
        std::vector<std::string> curr_edges = edges[curr_node];
        for (std::string ce : curr_edges)
        {
            if (ce == "out")
            {
                count++;
            }
            else
            {
                nodes_to_process.push(ce);
            }
        }
    }

    return count;
}
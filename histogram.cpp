#include "histogram.h"
#include <iostream>

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if (numbers.size() == 0)
    {
        return;
    }
    min = numbers[0], max = numbers[0];
    for (double number:numbers)
    {
        if (number < min)
            min = number;
        else
        {
            if (number > max)
                max = number;
        }
    }
}

vector<size_t> make_histogram (const vector<double>& numbers, size_t bin_count)
{
    double min = 0, max = 0;
    find_minmax(numbers, min, max);
    vector<size_t> foobins (bin_count);
    for (double number:numbers)
    {
        size_t bin_index = (size_t)((number - min)*bin_count/(max - min));
        if (number == max)
        {
             bin_index--;
        }
        foobins[bin_index]++;
    }
    return foobins;
}

size_t find_maxinbins(const vector<size_t>& bins)
{
    size_t max = bins[0];
    for (size_t bin:bins)
    {
        if(bin > max)
            max = bin;
    }
    return max;
}

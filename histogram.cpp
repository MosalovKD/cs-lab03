#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max)
{
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

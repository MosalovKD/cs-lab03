#pragma once
#include <vector>
using namespace std;

struct Input
{
    vector <double> numbers;
    size_t bin_count;
    int HIST_WIDTH;
};

void find_minmax(const vector<double>& numbers, double& min, double& max);

vector<size_t> make_histogram (Input);

size_t find_maxinbins(const vector<size_t>& bins);


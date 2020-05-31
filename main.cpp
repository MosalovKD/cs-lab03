#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include "info.h"

using namespace std;

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

int main()
{
    cerr << "Vvedite kol-vo chisel: ";
    size_t number_count;
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    cerr << "Vvedite kol-vo korzin: ";
    size_t bin_count;
    cin >> bin_count;
    const auto bins = make_histogram(numbers, bin_count);
    if (bins.size() == 0)
    {
        cout << "error";
        return 0;
    }
    show_histogram_svg(bins);
    return 0;
}

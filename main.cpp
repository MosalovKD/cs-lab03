#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

vector<double> input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }
    return result;
}

Input read_input(istream& in)
{
    Input data;
    cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;
    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    cerr << "Vvedite kol-vo korzin: ";
    size_t bin_count;
    cin >> bin_count;
    data.bin_count = bin_count;
    return data;
}

/*
void show_histogram_text (const vector<size_t>& bins)
{
    const size_t max_width = 80;
    const size_t max_ast = max_width - 4;
    double koeff = 1;
    size_t max_count = 0;
    for(size_t bin:bins)
    {
        if(bin > max_count)
            max_count = bin;
    }
    if (max_count > max_ast)
    {
        koeff = static_cast <double> (max_ast)/max_count;
    }
    for(size_t bin:bins)
    {
        if (bin < 10)
            cout << " " << " ";
        if (bin >= 10 && bin < 100)
            cout << " ";
        if (bin > 100)
        {
            cout << "error";
            break;
        }
        cout << bin << "|";
        size_t height = bin * koeff;
        for (int i =0; i < height; i++)
            cout << "*";
        cout << endl;
    }
}
*/

int main()
{

    const auto input = read_input(cin);
    const auto bins = make_histogram(input);
    if (bins.size() == 0)
    {
        cout << "error";
        return 0;
    }
    //show_histogram_text(bins);
    show_histogram_svg(bins);
    return 0;
}

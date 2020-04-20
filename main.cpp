#include <iostream>
#include <vector>

using namespace std;

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

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

vector<double> make_histogram (const vector<double>& numbers, size_t bin_count)
{
    double min = numbers[0], max = numbers[0];
    find_minmax(numbers, min, max);
    vector<double> foobins (bin_count);
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

void show_histogram_text (const vector<double>& bins)
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
    show_histogram_text(bins);
    return 0;
}

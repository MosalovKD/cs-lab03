#include <iostream>
#include <vector>
#include "histogram.h"

using namespace std;

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<size_t> make_histogram (const vector<double>& numbers, size_t bin_count)
{
    double min = numbers[0], max = numbers[0];
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

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>\n";
}

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}



void svg_end()
{
    cout << "</svg>\n";
}

void svg_rect(double x, double y, double width, double height, size_t binmax,
              string stroke = "black", string fil = "black" )
{
    const int max_width = 400;
    const int max_ast = max_width - 50;
    double koeff = 1;
    if(binmax > max_ast/10.0)
    {
        koeff = static_cast <double> (max_ast/10.0)/binmax;
        cout << "<rect x='" << x <<"' y='" << y << "' width='" << width * koeff << "' height='" << height << "' "
         << "stroke='" << stroke << "' fill='" << fil << "' />";

    }
    else
    {
     cout << "<rect x='" << x <<"' y='" << y << "' width='" << width << "' height='" << height << "' "
         << "stroke='" << stroke << "' fill='" << fil << "' />";
    }
}

void show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    size_t binmax = find_maxinbins(bins);
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins) {
    const double bin_width = BLOCK_WIDTH * bin;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, binmax, "red", "#ffeeee");
    top += BIN_HEIGHT;
}

    svg_end();
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
    //show_histogram_text(bins);
    show_histogram_svg(bins);
    return 0;
}

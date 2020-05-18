#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>


using namespace std;



vector<double> input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }
    return result;
}

Input read_input(istream& in, bool promt)
{
    Input data;
    size_t number_count;
    size_t bin_count;
    if(promt == true)
    {
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    }
    data.numbers = input_numbers(in, number_count);
    if (promt == true)
    {
    cerr << "Vvedite kol-vo korzin: ";
    cin >> bin_count;
    }
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

int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        CURL *curl = curl_easy_init();
               if(curl)
               {
                     CURLcode res;
                     curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
                     res = curl_easy_perform(curl);
                     curl_easy_cleanup(curl);
               }
    }
    curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin, true);
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

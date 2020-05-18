#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <string>

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

size_t write_data (void* items, size_t item_size, size_t item_count, void* ctx)
{
    size_t data_size = item_size * item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    const char* c_items = reinterpret_cast<const char*>(items);
    buffer->write(c_items, data_size);
    return data_size;
}

Input download (const string& address)
{
       stringstream buffer;
       curl_global_init(CURL_GLOBAL_ALL);
       CURL *curl = curl_easy_init();
               if(curl)
               {
                     CURLcode res;
                     curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
                     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
                     res = curl_easy_perform(curl);
                     if (res != 0)
                        {
                          string str = curl_easy_strerror(res);
                          cerr << str;
                          exit(1);
                        }
               }
        curl_easy_cleanup(curl);
        return read_input(buffer, false);
}

int main(int argc, char* argv[])
{
    Input input;
    if(argc > 1)
    {
       input = download(argv[1]);
    }
    else
    {
        input = read_input(cin, true);
    }
    const auto bins = make_histogram(input);
    if (bins.size() == 0)
    {
        cout << "error";
        return 0;
    }
    show_histogram_svg(bins);
    return 0;
}

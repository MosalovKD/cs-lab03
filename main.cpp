#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>

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
    DWORD info = GetVersion();
    DWORD build;
    printf("Info in 10 is %u\n", info);
    printf("Info in 16 is %x\n", info);

    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = info & mask;
    printf("Your version in 10 %u\n", version);

    DWORD platform = info >> 16;

    DWORD major_mask = 0x00ff;
    DWORD version_major = version & major_mask;

    DWORD version_minor = version >> 8;

    if ((info & 0x80000000) == 0)
    {
    build = platform;
    }

    printf("Windows v%u.%u (build %u)", version_major, version_minor, build);
    return 0;

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

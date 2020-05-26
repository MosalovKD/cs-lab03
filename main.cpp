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
    /*printf("Your version(10) is %u\n", info);
    printf("Your version(16) is %x\n", info);
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = info & mask;
    printf("Your version(10) is %u\n", version);
    printf("Your version(16) is %x\n", version);
    DWORD mask_major = 0x0000ff00;
    DWORD version_major = version & mask_major;
    DWORD mask_minor = 0x000000ff;
    DWORD version_minor = version & mask_minor;
    printf("Your version(10) is %u %c %u", version_major, '.', version_minor);*/
    DWORD mask_major = 0x0000ff00;
    DWORD version_major = info & mask_major;
    DWORD mask_minor = 0x000000ff;
    DWORD version_minor = info & mask_minor;
    printf("Your version is %u %c %u", version_major, '.', version_minor);
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

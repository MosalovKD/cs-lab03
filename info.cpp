#include "info.h"
#include <windows.h>
#include <sstream>

string info_text()
{
    stringstream buffer;

    DWORD info = GetVersion();
    DWORD build;
    DWORD mask = 0b00000000'00000000'11111111'11111111;
    DWORD version = info & mask;

    DWORD platform = info >> 16;

    DWORD major_mask = 0x00ff;
    DWORD version_major = version & major_mask;

    DWORD version_minor = version >> 8;

    if ((info & 0x80000000) == 0)
    {
    build = platform;
    }

    char name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
    GetComputerNameA(name, &size);

    buffer << "Windows v" << version_major << "." << version_minor << " (build " << build << ")" <<
    "Computer name: " << name;

    return buffer.str();
}

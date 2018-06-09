#include"IntToString.h"

std::string intToString(int x)
{
    std::stringstream ss;
    std::string s;
    ss << x;
    ss >> s;
    return s;
}

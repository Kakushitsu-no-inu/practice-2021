#include "simple_s.h"
#include <iomanip>

String& String::operator=(const String & other)
{
        str = other.str;
        return *this;
    }

String& String::operator+(const String & other)
{
    String tmp(str + other.str);
    return tmp;
}
bool String::operator==(const String& other)
{
    return other.str == str;
}

bool String::operator>(const String& other)
{
    return str > other.str;
}
bool String::operator<(const String& other)
{
    return str < other.str;
}
bool String::operator!=(const String &other)
{
    return str != other.str;
}
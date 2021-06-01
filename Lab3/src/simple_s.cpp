#include "simple_s.h"
#include <iomanip>
#include <string>

String& String::operator=(const String & other)
{
        str = other.str;
        return *this;
    }

String& String::operator+=(const String & other)
{
    str += other.str;
    return *this;
}
String::String(const String &a)
{
    str = a.str;
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



String::String(int a)
{
    str = a;
}
String::String(double a)
{
    str = a;
}
void String::format(int setw, char c ){
    std::string tmp(setw-str.length(), c);
    str = tmp + str;
}
void String::format_print(int setw, char c){
    std::cout << std::setw(setw) << std::setfill(c) << str << std::endl;
}

std::istream& operator>>(std::istream &in, String &obj)
{
    in >> obj.str;
    return in;
}
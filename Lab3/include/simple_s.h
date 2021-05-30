#pragma once
#include <iostream>


class String{
    std::string str{};
public:
    String(std::string str);

    String &operator=(const String &other);
    String &operator+(const String &other);
    bool operator==(const String &other);
    bool operator>(const String &other);
    bool operator<(const String &other);
    bool operator!=(const String &other);
};

#pragma once
#include <iostream>


class String{
    std::string str;
public:
    String() = default;
    String(std::string str);
    String(int);
    String(const String &a);
    String(double);

    String &operator=(const String &other);
    String &operator+=(const String &other);
    bool operator==(const String &other);
    bool operator>(const String &other);
    bool operator<(const String &other);
    bool operator!=(const String &other);
    friend std::istream &operator>>(std::istream &in, String &obj);
    explicit operator int()
{
    std::string tmp(str);
    for (int i = 0; i < str.size(); i++)
    {
        try{
            auto a = std::stoi(tmp);
            return a;
        }catch(...)
        {
            auto len = tmp.size() - 1;
            for (int i = 0; i < len; i++)
            {
                char c = tmp[i];
                tmp[i] = tmp[i + 1];
                tmp[i + 1] = c;
            }
            tmp.resize(len);
    }
    }
    return EXIT_FAILURE;
}
  explicit operator double()
{
    return atof(str.c_str());
}
    void format(int setw, char c );
    void format_print(int setw, char c );
};

#pragma once
#include "person.h"


class book_p : public person
{
    std::string  tel{};
public:
    book_p();
    book_p(std::string name, std::string surname, std::string tel);
    void print() final;
    std::string get_tel() const;
    void set_tel(std::string t);

    friend std::istream &operator>>(std::istream &in, book_p &obj);
    friend std::ostream &operator<<(std::ostream &out, const book_p &obj);
    bool operator==(const book_p &other);
    bool operator!=(const book_p &other);
};
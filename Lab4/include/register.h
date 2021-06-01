#pragma once
#include "book.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <ranges>

class Register{
    // struct compare
    // {
    //     bool operator()(book_p &pers1,book_p &pers2)
    //     {
    //         return pers1.get_surname() < pers2.get_surname() ||
    //          (pers1.get_surname() == pers2.get_surname() && pers1.get_name() < pers2.get_name());
    //     }
    // };

public:
    std::vector<book_p> r_book;
    void add_person(const book_p &a);

    friend std::istream &operator>>(std::istream &in, Register &obj);
    friend std::ostream &operator<<(std::ostream &out, Register &obj);

    void push_to_file();
    void load_from_file();

    void search_(std::string&);
    void remove_person(const book_p &person);
    void sort_(const std::string &param);
};

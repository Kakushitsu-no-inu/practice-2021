#pragma once 
#include <iostream>

class array
{
    int size{};
    int* arr{};
    void init(int data);
    void memory(int size);
public:
    array() = default;
    array(int size);
    array(int size, int data);

    void fill_array();
    class Iterator
    {
        int* ptr;
        public:
        using difference_type = std::ptrdiff_t;
        Iterator(int*a);
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator &other);
        bool operator==(const Iterator &other);
        int operator*() const;
        Iterator operator+(int a);
    };
    Iterator begin();
    Iterator end();    
    int& operator[](int i) const;
    ~array();
    friend std::ostream& operator<<(std::ostream &out, const array &a);
    void func() ;
};
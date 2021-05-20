#include <ctime>
#include <numeric>
#include <exception>
#include <algorithm>
#include "array.h"

void array::init(int data){for(int i = 0; i < size; ++i) arr[i] = data;}
void array::memory(int size){arr = new int[size];}

array::array(int size) : size(size) {
                        memory(size);
                        init(0);
}

array::array(int size, int data) : size(size) {
                        memory(size);
                        init(data);
}

void array::fill_array(){
    std::srand(static_cast<unsigned>(std::time(0))); 
    for(auto i = arr; i < arr+size; i++){ *i =rand()%9+1;}
}

array::Iterator::Iterator(int*a) : ptr(a){}

array::Iterator& array::Iterator::operator++() {
            ptr++;
            return *this;
        }
array::Iterator array::Iterator::operator++(int) {
            auto tmp =*this;
            ptr++;
            return tmp;
        }
bool array::Iterator::operator!=(const Iterator &other){
            return ptr!=other.ptr;
        }
bool array::Iterator::operator==(const Iterator &other){
            return ptr==other.ptr;
        }
double array::Iterator::operator*() const  {return *ptr;}
array::Iterator array::Iterator::operator+(int a){
            auto tmp = ptr;
            for (int i = 0; i < a; i++) {
            tmp++;
            }
            return Iterator{tmp};
        }
array::Iterator array::begin() {return Iterator{arr};}
array::Iterator array::end() {return Iterator{arr+size};}

int& array::operator[](int i) const { 
    if(i < 0 || i > size) 
        throw std::out_of_range("Вихід за межі масиву"); 
    return *(arr + i - 1); 
}

array::~array(){delete[]arr;}

std::ostream& operator<<(std::ostream &out, const array &a) {
        for (int i = 0; i < a.size; i++)
        {
            out << a[i] << " ";
        }
        out << "\n";
        return out;
    }
void array::func(){
    auto mid = (size + 1)/2;
    auto beginIt = this->begin();
    auto endIt = this->end();
    auto midIt = this->begin() + mid;
    std::cout << "Сума першої половини = " << std::accumulate(beginIt, midIt, 0) 
            << " Кількість позитивних = " << std::count_if(beginIt, midIt,[](int &t){return t > 0;})<<std::endl;
    std::cout << "Сума другої половини = " << std::accumulate(midIt, endIt, 0) << std::endl;
}
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
    for(auto i = 0; i < size; i++){ arr[i] =rand()%20-10;}
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
int array::Iterator::operator*() const  {return *ptr;}
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
    return *(arr + i); 
}

array::~array(){delete[]arr;}

std::ostream& operator<<(std::ostream &out, const array &a) {
        for (int i = 0; i < a.size; i++)
        {
            out << a.arr[i] << " ";
        }
        out << "\n";
        return out;
    }
array::result array::func(){
    auto mid = size/2;
    auto beginIt = this->begin();
    auto endIt = this->end();
    auto midIt = this->begin() + mid;
    auto positive = [](const int &t){return t > 0;};
    // size_t pos = std::count_if(beginIt, midIt, positive);
    result a(std::accumulate(beginIt, midIt, 0),std::accumulate(midIt, endIt, 0),
                   std::count_if(beginIt, midIt, positive),std::count_if(midIt, endIt, positive));
    std::cout << "Сума першої половини = " << a.sum1
            << " Кількість позитивних = " << a.pos1 <<std::endl;
    std::cout << "Сума другої половини = " << a.sum2
            << " Кількість позитивних = " << a.pos2 <<std::endl;
    return a;
}
void array::copy_from_vec(std::vector<int> &v)
{
    std::copy(v.begin(),v.end(),arr);
}
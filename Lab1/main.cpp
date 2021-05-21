#include "array.h"

int main()
{
    int n;
    std::cout << "Довжина масиву: ";
    std:: cin >> n; 
    array a(n);
    a.fill_array();
    std::cout << a;
    // a.func();
    return 0;
}
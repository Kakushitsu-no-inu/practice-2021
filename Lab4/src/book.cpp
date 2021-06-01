#include "book.h"
#include <iostream>

book_p::book_p() : person(){}
book_p::book_p(std::string name, std::string surname, std::string tel) : person(name,surname){
    this->tel = tel;
}

void book_p::print(){
    person::print();
    std::cout << tel << std::endl;
}

std::string book_p::get_tel() const { return tel; }

std::ostream &operator<<(std::ostream &out, const book_p &obj) 
{
    out << obj.get_name() << " " << obj.get_surname() << " " << obj.get_tel();
    return out;
}

void book_p::set_tel(std::string t)
{
    tel = t;
}

std::istream& operator>>(std::istream &in, book_p &obj) 
{
    std::string name,surname,tel;
    in >> name >> surname >> tel;
    obj.set_name_surname(name, surname);
    obj.set_tel(tel);
    return in;
}

bool book_p::operator==(const book_p &other) 
{
    return (get_name() == other.get_name() && get_surname() == other.get_surname() && tel == other.tel);
}

bool book_p::operator!=(const book_p&other)
{
    return (get_name() != other.get_name() && get_surname() != other.get_surname() && tel != other.tel);
}
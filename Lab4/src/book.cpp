#include "book.h"

book::book() : person(){}
book::book(std::string name, std::string surname, std::string address, std::string tel) : person(name,surname){
    this->address = address;
    this->tel = tel;
}

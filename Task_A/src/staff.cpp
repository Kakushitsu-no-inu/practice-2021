#include "staff.h"
#include <ranges>

void staff::add_employee(employee *a)
{
    if(a->get_name() == " " || a->get_surname()== " ")
        throw std::logic_error("Пусте поле");
    collection.emplace_back(a);
}

void staff::sort_(){
    auto comp = [](const employee *a, const employee *b)
    { return (a->get_msalary() > b->get_msalary() ||
              (a->get_msalary() == b->get_msalary() && a->get_name() < b->get_name())); };
    std::sort(collection.begin(), collection.end(), comp);
}
void staff::print(int amount = 5){
    int i = 0;
    for (auto &emp : collection)
    {
        if(i == amount)
            break;
        std::cout << emp->get_id() << " " << emp->get_name() << " " << emp->get_surname()
                  << " " << emp->get_msalary() << std::endl;
        ++i;
    }
}

void staff::last_ids(){
    sort_();
    auto n = std::views::take(std::views::reverse(collection), 3);
   for(auto& emp:n)
   {
       std::cout << emp->get_id() << std::endl;
   }
}

staff::~staff()
{
    for(auto& emp:collection)
    {
        delete emp;
    }
}



std::ostream& operator<<(std::ostream &out, const staff &obj) 
{
    for (int i = 0; i < obj.collection.size(); i++)
    {
        auto type = std::typeid(obj.collection[i]);
        // out << obj.collection[i]->print_e() << std::endl;
        out << obj.collection[i]->get_id() << std::endl;
        out << obj.collection[i]->get_name() << std::endl;
        out << obj.collection[i]->get_surname() << std::endl;
        out << obj.collection[i]->get_msalary();
        if (i != obj.collection.size() - 1)
            std::cout << std::endl;
    }
    return out;
}

void staff::load_from_file()
{
    std::ifstream file("staff.txt", std::ios::out);
    while (!file.eof())
    {
        std::string name{}, surname{},def{};
        int id;
        double salary;
        file >> def;
        file >> id;
        file >> name;
        file >> surname;
        file >> salary;
        if(def == "fixed")
            add_employee(new f_emp{name, surname, id, salary});
        else if(def == "hour_wage")
            add_employee(new h_employee{name, surname, id, salary});
        else
            throw std::logic_error("Проблема файлу: помилка запису/зчитування");
    }
    file.close();
}

void staff::push_to_file(){
    std::ofstream file("staff.txt");
    file.clear();
    file << *this;
    file.close();
}

void staff::clear_()
{
    collection.clear();
}

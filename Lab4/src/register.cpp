#include "register.h"


void Register::add_person(const book_p &a) 
{
    if(r_book.empty()) 
        r_book.emplace_back(a);
    else if (auto exists = std::find(r_book.begin(), r_book.end(), a); exists == std::end(r_book))
        r_book.emplace_back(a);
    if(a.get_name() == "" || a.get_surname() == "" || a.get_tel() =="")
        throw std::logic_error("пусте поле");
}

std::ostream& operator<<(std::ostream &out, Register &obj) 
{
    for (size_t i = 0; i < obj.r_book.size(); i++)
    {
        out << obj.r_book[i];
       if(i != obj.r_book.size()-1) out << std::endl;
    }
    return out;
}


void Register::push_to_file() 
{
    std::fstream file("record_book.txt");
    file.clear();
    file << *this;
    file.close();
}

void Register::load_from_file()
{
    std::fstream file("record_book.txt");
    if(!file.is_open())
        throw std::underflow_error("Немає файлу");
    while (!file.eof())
    {
        book_p tmp;
        file >> tmp;
        try{
            add_person(tmp);
        }catch(std::logic_error &err)
        {
            std::cout << "Проблема файлу: пустий рядок " << err.what();
        }
    }
    file.close();
}

void Register::search_(std::string &search)
{
    auto lambda = [&search](const book_p &a)
    { return (a.get_name() == search || a.get_surname() == search || a.get_tel() == search); };
    for (const auto &el : r_book | std::ranges::views::filter(lambda))
        std::cout << el << std::endl;
}

void Register::remove_person(const book_p &person)
{
    auto del = std::find(r_book.begin(), r_book.end(), person);
    if(del != r_book.end())
        r_book.erase(del);
    else
        throw std::logic_error("Немає такого запису");
}

void Register::sort_(const std::string &param){
    
    if(param == "name"){
        auto comp = [](const book_p &person1, const book_p &person2)
        { return (person1.get_name()) <= person2.get_name(); };
        std::sort(r_book.begin(), r_book.end(), comp);
    }
    else if(param == "surname")
    {
        auto comp = [](const book_p &person1, const book_p &person2)
        { return (person1.get_surname()) <= person2.get_surname(); };
        std::sort(r_book.begin(), r_book.end(), comp);
    }
    else if(param == "tel")
    {
        auto comp = [](const book_p &person1, const book_p &person2)
        { return (person1.get_tel()) <= person2.get_tel(); };
        std::sort(r_book.begin(), r_book.end(), comp);
    }
    else
        throw std::logic_error("Параметр сортування хибний");
    for (int i = 0; i < r_book.size(); i++)
    {
        std::cout << r_book[i] << std::endl;
    }
}
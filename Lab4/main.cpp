#include "register.h"
#include "ui.h"

void add_new_record();
void main_search();
void delete_record();
void main_sort();
void quit();
Register rec;
    auto main_menu = make_window("Menu", option{[&](menu_base *)
                                                { add_new_record(); },"Додати новий запис"},
                                        option{[&](menu_base *)
                                                { main_search(); },"Пошук"},
                                        option{[&](menu_base *)
                                                { delete_record(); },"Видалити запис"},
                                        option{[&](menu_base *)
                                                { main_sort(); },"Сортувати"},
                                        option{[&](menu_base *)
                                                { quit(); },"Вийти"});
int main()
{

    return 0;
}

void add_new_record(){
    rec.load_from_file();
    std::string name, surname, tel;
    std::cout << "Введіть ім'я прізвище та телефон: ";
    std::cin >> name >> surname >> tel;
    try{
        rec.add_person(book_p{name, surname, tel});
    }catch(std::logic_error &err){
        std::cout << "\nПоле пусте\n";
    }
}
void main_search(){
    std::string key_word;
    std::cout << "Ключве слово: ";
    std::cin >> key_word;
    rec.search_(key_word);
}
void delete_record(){
    std::string name, surname, tel;
    std::cout << "Введіть ім'я прізвище та телефон: ";
    std::cin >> name >> surname >> tel;
    try{
    rec.remove_person(book_p{name,surname,tel});
    }catch(std::logic_error &err)
    {
        std::cout << err.what();
    }
}
void main_sort(){
    std::string attribute;
    std::cout << "введіть атрибут (name,surname,tel): ";
    std::cin >> attribute;
     try{
        rec.sort_(attribute);
    }catch(std::logic_error &err)
    {
        std::cout << err.what();
    }
}
void quit(){
    rec.push_to_file();
    exit(EXIT_SUCCESS);
}
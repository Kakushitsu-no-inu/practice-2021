#include "register.h"
#include "unistd.h"

void Menu();
void add_new_record();
void main_search();
void delete_record();
void main_sort();
void quit();
Register rec;

int main()
{
    for (;;)
    {
        sleep(5);
        system("clear");
        Menu();
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            add_new_record();
            break;
        case 2:
            delete_record();
            break;
        case 3:
            main_search();
            break;
        case 4:
            main_sort();
            break;
        case 0:
            quit();
            break;
        default:
            break;
        }
    }
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
void Menu(){
    std::cout << "1| Додати новий запис "  << std::endl;
    std::cout << "2| Видалити запис "  << std::endl;
    std::cout << "3| Пошук "  << std::endl;
    std::cout << "4| Сортування"  << std::endl;
    std::cout << "-----------0:EXIT-----------\n\t> ";
}
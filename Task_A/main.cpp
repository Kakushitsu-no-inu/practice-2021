#include "staff.h"
#include "unistd.h"

void Menu();
void add_new_employee();
// void show_last_id();
void first_info();
void main_sort();
void quit();
staff s;

int main()
{
try{
    s.load_from_file();

}catch(std::logic_error &err)
{
    std::cout << " \nНе забудьте зберегти зміни!\n";
}
    for (;;)
    {
        // sleep(5);
        // pause();
        // system("clear");
        Menu();
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            add_new_employee();
            break;
        case 2:
             s.last_ids();
            break;
        case 3:
            main_sort();
            break;
        case 4:
            first_info();
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

void add_new_employee(){
    do{std::string type;
        std::cout << "Тип працівника (fixed or hour_wage): ";
        std::cin >> type;
        if(type == "fixed")
        {
            std::string name,surname;
            int id;
            double sal;
            std::cout << "Ім'я, прізвище, ІD, зарплата: ";
            std::cin >> name >> surname >> id >> sal;
            s.add_employee(new f_emp{name, surname, id, sal});
            break;
        }
        else if(type == "hour_wage")
        {
            std::string name,surname;
            int id;
            double sal;
            std::cout << "Ім'я, прізвище, ІD, погодинна плата: ";
            std::cin >> name >> surname >> id >> sal;
            s.add_employee(new h_employee{name, surname, id, sal});
            break;
        }
        else
            std::cout << "Тип не правильний. Спробуйте ще раз\n";
    } while (true);
}
// void show_last_id(){
//     s.last_ids();
// }
void main_sort(){
    s.sort_();
    s.print(s.size());
}
void first_info(){
    s.sort_();
    s.print(5);
}
void quit()
{
    s.push_to_file();
    exit(EXIT_SUCCESS);
}
void Menu(){
    std::cout << "\n1| Додати нового працівника "  << std::endl;
    std::cout << "2| Показати останні ід "  << std::endl;
    std::cout << "3| Сортування"  << std::endl;
    std::cout << "4| Інформація про 5 перших "  << std::endl;
    std::cout << "-----------0:EXIT-----------\n\t> ";
}
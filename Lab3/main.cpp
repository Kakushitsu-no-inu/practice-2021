#include <simple_s.h>
#include <unistd.h>

void Menu();

int main(){
    for (;;)
    {
        sleep(5);
        system("clear");
        std::cout << "\nВведіть текст: ";
        String str;
        std::cin >> str;
        Menu();
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            {
                std::cout << "Інший текст: ";
                String str2;
                std::cin >> str2;
                std::cout << "Текст 1 == інший текст " << std::boolalpha << (str==str2)   << std::endl;
             
                break;
             }

        case 2:
        {
            std::cout << static_cast<int>(str);
            break;
        }
            case 3:
            {
                std::cout << static_cast<double>(str);

                break;
            }
            
        case 4:
        {
            std::cout << " (int)<setw> (char)<setfill> \n";
            int w;
            char fill;
            std::cin >> w >> fill;
            str.format_print(w,fill);
            break;
        }
        case 5:
        {
            std::cout << "Інший текст: ";
                String str2;
                std::cin >> str2;
                str += str2;
                str.format_print(10,' ');

                break;
        }
        case 0:
            return EXIT_SUCCESS;
            break;
        default:
            break;

        }
}
        return 0;

}


void Menu(){
    std::cout << "1| Порівняти "  << std::endl;
    std::cout << "2| Витягнути число "  << std::endl;
    std::cout << "3| Привести до double "  << std::endl;
    std::cout << "4| Форматний вивід рядка"  << std::endl;
     std::cout << "5| Конкатинаація "  << std::endl;
    std::cout << "-----------0:EXIT-----------\n\t> ";
}
#include "staff.h"

int main()
{
    staff s;
    s.add_employee(new f_emp { "Andrii","Liashenko",1,5000});
    s.add_employee(new h_employee { "Ivan","Tkachuk",2,20});
    s.add_employee(new h_employee { "Florian","Akostakioae",3,10});
    s.add_employee(new f_emp { "Mykhailo","Liashenko",4,5000});
    // std::cout << "-----------------------------------" << std::endl;
    s.sort_();
    // s.print(3);
    // std::cout << "-----------------------------------" << std::endl;
    // s.last_ids();
    // std::cout << "-----------------------------------" << std::endl;
    // s.push_to_file();
    // s.clear_();
    s.load_from_file();
    s.print(4);
    return 0;
}
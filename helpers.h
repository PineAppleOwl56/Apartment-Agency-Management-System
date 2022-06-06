#include <iostream>
#ifndef ASSIGHMENT_2_HELPERS_H
#define ASSIGHMENT_2_HELPERS_H
void menuPrinter(){
    std::cout<<"!!!Welcome to Agency Management System!!!"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"Please select an operation"<<std::endl;
    std::cout<<"1. Add a new building to the agency"<<std::endl;
    std::cout<<"2. Add a new apartment (monthly or daily rental) to a building"<<std::endl;
    std::cout<<"3. List all buildings"<<std::endl;
    std::cout<<"4. List all apartments available for the agency"<<std::endl;
    std::cout<<"5. List all apartments that have the specified number of rooms"<<std::endl;
    std::cout<<"6. List all apartments which the specified apartment size"<<std::endl;
    std::cout<<"7. List all apartments which the specified price in a specified number of days"<<std::endl;
    std::cout<<"8. List all apartments that are either daily or monthly rental"<<std::endl;
    std::cout<<"9. Calculate the price of a specific apartment in a specified number of days \n0.Exit"<<std::endl;

}
#endif //ASSIGHMENT_2_HELPERS_H

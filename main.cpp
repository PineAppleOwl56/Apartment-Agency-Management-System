/* Belousov Daniil – 2491827
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include<iostream>
#include "Agency.h"
#include "helpers.h"

// I have used pointers in this code to provide better flexibility in the storage of buildings and not shorten its amount by any random value
// However, this code is implemented using linked list and sentential search which can lead to long loading and big time consumption if too many buildings will be in the system
// To make the code more efficient, I could have used binary trees to store the buildings based on their id

int main() {
    int choice=-1;
    std::string name_of_building;
    Agency objA1;//creating just one, initial agency
    menuPrinter(); // used another header file with the function to output menu
    std::cout<<"---------------------------------------------"<<std::endl;
    //creating a loop that will run as long as the user does not input a 0 integer (exiting the program)
    while(choice!=0){
        std::cout<<"Your selection: ";
        std::cin>>choice;
        fflush(stdin);
        //check that we actualy have a record of any building that we can perform any operations from the menu
        if((choice>1)&&(objA1.getContainer()->size==0)){
            std::cout<<"Pleace add buildings firts"<<std::endl;
            choice=15;
        }
        switch (choice){
            //the condition that will end the loop and end the program
            case 0:
                std::cout<<"Thanks for choosing Agency Management System!"<<std::endl;
                choice=0;
                break;
            //if the user chooses the 1 option from the menu we are adding the new buildings site to the agency
            case 1:
                //firstly we check that we do not have the building already in the agency and if so, we ask to input a different name, however if the agency does not have any buildings we just continue
                do {
                    std::cout << "What is the address of your building: ";
                    getline(std::cin, name_of_building);
                    if ((objA1.getContainer()->size!=0)&&(objA1.CheackOccurance(&name_of_building[0])))
                        std::cout<<"Building exsists"<<std::endl;
                }while((objA1.getContainer()->size!=0)&&(objA1.CheackOccurance(&name_of_building[0])));
                Buildings *temp;
                objA1.addBuildingsId();
                //calling a specific constructor to creat the new building
                temp= new Buildings(objA1.getBuildingsId(),&name_of_building[0]);

                objA1.Add_New_Building(*temp);
                //stating that the building was created
                std::cout<<"The building is created with the id number "<<objA1.getBuildingsId()<<std::endl;
                break;
            case 2:
                //creating a new apartment and adding it to the record
                int number,type,room_number,room_rooms,room_size;
                struct price room_rent;
                // in the following loop we are making sure that the user chooses one of the given options otherwise ask him to reenter the choice
                do {
                    std::cout << "Which building you want to add apartment into?\nAvailable Buildings:" << std::endl;
                    objA1.Aggency_Buildings_adresses();
                    std::cout<<"Building id: ";
                    std::cin >> number;
                    if (number>objA1.getBuildingsId())
                        std::cout<<"Incorrect id input, please try again!"<<std::endl;
                    fflush(stdin);
                }while(number>objA1.getBuildingsId());
                //making sure that the user chooses one of the given apartment options
                do {
                    std::cout<< "What is the type of the apartment?\n1. Daily Rental Apartment\n2. Monthly Rental Apartment\n\nType: ";
                    std::cin >> type;
                    if ((type!=1)&&(type!=2))
                        std::cout<<"Incorrect type input, please try again!\n"<<std::endl;
                }while((type!=1)&&(type!=2));
                //creating a specific apartment based ob the users choice
                if (type==1){
                    int style;
                    enum apartType insta;
                    //making sure that the apartment the user tries to add does not already exist
                    do {
                        std::cout << "Enter room number: ";
                        std::cin >> room_number;
                        if ((objA1.getBuildingsRecord(number)->getRecord()->size!=0)&&(objA1.getBuildingsRecord(number)->CheackOccurance(room_number,'D')==1))
                            std::cout<<"The flat already excists"<<std::endl;
                    }while((objA1.getBuildingsRecord(number)->getRecord()->size!=0)&&(objA1.getBuildingsRecord(number)->CheackOccurance(room_number,'D')==1));
                    std::cout<<"Enter number of rooms: ";
                    std::cin >> room_rooms;
                    std::cout<<"Enter rent (GBP): ";
                    std::cin >> room_rent.cost;
                    room_rent.price_type='D';
                    std::cout<<"Enter size (m2): ";
                    std::cin >> room_size;
                    do{
                        std::cout<<"Decoration Style:\n1. Minimalist\n2. Modern\n3. Classic\nYour selection: ";
                        std::cin >> style;
                        if ((style!=1)&&(style!=2)&&(style!=3))
                            std::cout<<"Please choose on of the given options"<<std::endl;
                    }while((style!=1)&&(style!=2)&&(style!=3));
                    if (style==1)
                        insta=apartType::Minimalist;
                    else if (style==2)
                        insta=apartType::Modern;
                    else if (style==3)
                        insta=apartType::Classic;
                    //creating the new apartment and adding it to the record of the building, the building is already in the record of the agency
                    Daily_rental_appartment *app1;
                    app1 = new Daily_rental_appartment(room_number,room_rooms,room_rent,room_size,insta);
                    objA1.getBuildingsRecord(number)->Add_Appartment(*app1);
                }
                else{
                    int fur;
                    bool fur1;
                    //making sure that the apartment the user tries to add does not already exist
                    do {
                        std::cout << "Enter room number: ";
                        std::cin >> room_number;
                        if ((objA1.getBuildingsRecord(number)->getRecord()->size!=0)&&(objA1.getBuildingsRecord(number)->CheackOccurance(room_number,'M')==1))
                            std::cout<<"The flat already excists"<<std::endl;
                    }while((objA1.getBuildingsRecord(number)->getRecord()->size!=0)&&(objA1.getBuildingsRecord(number)->CheackOccurance(room_number,'M')==1));
                    std::cout<<"Enter number of rooms: ";
                    std::cin >> room_rooms;
                    std::cout<<"Enter rent (GBP): ";
                    std::cin >> room_rent.cost;
                    room_rent.price_type='M';
                    std::cout<<"Enter size (m2): ";
                    std::cin >> room_size;
                    do{
                        std::cout<<"Furnished (Yes(1) / No(0)): ";
                        std::cin >> fur;
                        if ((fur!=1)&&(fur!=0))
                            std::cout<<"Please choos on of the given options"<<std::endl;
                    }while((fur!=1)&&(fur!=0));
                    if (fur==0)
                        fur1=false;
                    else
                        fur1=true;
                    Monthly_rental_appartment *app1;
                    //creating the new apartment and adding it to the record of the building, the building is already in the record of the agency
                    app1 = new Monthly_rental_appartment(room_number,room_rooms,room_rent,room_size,fur1);
                    objA1.getBuildingsRecord(number)->Add_Appartment(*app1);
                }
                std::cout<<"Apartment successfully added!"<<std::endl;
                break;
            case 3:
                //displaying the addresses of the building we already have
                objA1.Aggency_Buildings_adresses();
                break;
            case 4:
                //displaying all the buildings with their apartments
                objA1.All_Appartments_printer();
                break;
            case 5:
                //trying to find the flat with the specific number of rooms
                int room_n;
                std::cout<<"Enter the specified room number: ";
                std::cin>>room_n;
                objA1.Aggency_Buildings_Appartment_Spec_Room(room_n);
                break;
            case 6:
                //trying to find the flat with the specific size of the flat
                int room_s;
                std::cout<<"Enter minimum size: ";
                std::cin>>room_s;
                objA1.Aggency_Buildings_Appartment_Bigger_Room(room_s);
                break;
            case 7:
                //trying to find the flat that fit the budget
                int price,days;
                std::cout<<"Enter the price (GBP): ";
                std::cin>>price;
                std::cout<<"Enter the days: ";
                std::cin>>days;
                objA1.Aggency_Buildings_Appartment_Cheper(price,days);
                break;
            case 8:
                //displaying the specific types of the apartments
                int choic;
                // making sure the user chooses one of the given options
                do{
                    std::cout<<"Enter Daily/Monthly Rental (0/1): ";
                    std::cin>>choic;
                    if ((choic!=0)&&(choic!=1))
                        std::cout<<"Wrong input, please choose on of the given ones"<<std::endl;
                }while((choic!=0)&&(choic!=1));
                if (choic==0)
                    objA1.Aggency_Buildings_DM('D');
                else
                    objA1.Aggency_Buildings_DM('M');
                break;
            case 9:
                int days1,build,idd;
                std::cout<<"Available Buildings:"<<std::endl;
                objA1.Aggency_Buildings_adresses();
                //making sure the user chooses one of the already provided buildings apartments
                do {
                    std::cout << "Select Building: ";
                    std::cin >> build;
                    if (build>objA1.getContainer()->size-1)
                        std::cout<<"Not Found"<<std::endl;
                }while(build>objA1.getContainer()->size-1);
                std::cout<<"Available Apartments:"<<std::endl;
                //displaying which apartments the agency has
                objA1.getBuildingsRecord(build)->Buldings_with_Appartments_printer();
                std::cout << "Enter Room No: ";
                std::cin >> idd;
                std::cout<<"Enter the days: ";
                std::cin>>days1;
                //culculating the price of the apartment
                objA1.Aggency_Buildings_Appartment_Price(build, idd,days1);
                break;
            default:
                //if the user enters the value not form the menu
                std::cout<<"wrong input"<<std::endl;
                fflush(stdin);
                break;
        }
        fflush(stdin);
        std::cout<<"---------------------------------------------"<<std::endl;
    }
    return 0;
}

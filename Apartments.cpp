#include"Appartments.h"
Apartments::Apartments() {
    ID=0;
    Num_of_Rooms=0;
    Price.cost=0;
    Price.price_type = 'N';
    Size=0;
}
Apartments::Apartments(int id, int NR, price A, int S) {
    ID=id;
    Num_of_Rooms=NR;
    Price=A;
    Size=S;
}
int Apartments::CalculatePrice(int days){
    return days*Price.cost; //counts the final price for each day
}
price Apartments::getPrice() const{
    return Price;
}

int Apartments::getId() const {
    return ID;
}
int Apartments::getNumOfRooms() const {
    return Num_of_Rooms;
}
int Apartments::getSize() const {
    return Size;
}
void Apartments::setId(int id) {
    ID = id;
}
void Apartments::setNumOfRooms(int numOfRooms) {
    Num_of_Rooms = numOfRooms;
}
void Apartments::setPrice(const price &price) {
    Price = price;
}
void Apartments::setSize(int size) {
    Size = size;
}
void Apartments::printer() {
    std::cout<<"Room No: "<< ID<<" Number of Rooms: "<<Num_of_Rooms<<" Rent: "<<Price.cost<<" GBP "<<"Size: "<<Size<<std::endl;
}

Daily_rental_appartment::Daily_rental_appartment() {
    type = Dummy;
}

Daily_rental_appartment::Daily_rental_appartment(int id, int NR,price Pp, int S,enum apartType entered):Apartments(id,NR,Pp,S) {
    type = entered;
}

int Daily_rental_appartment::CalculatePrice(int days){
    return days*Price.cost;
}

void Daily_rental_appartment::printer() {
    std::cout<<"Room No: "<< ID;
    std::cout<<", Number of Rooms: "<< Num_of_Rooms;
    std::cout<<", Rent: "<< Price.cost;
    std::cout<<", Size: "<< Size;
    switch (type){
        case 1:
            std::cout<<", Decoration Style:  Minimalist" << std::endl;
            break;
        case 2:
            std::cout<<", Decoration Style:  Modern" << std::endl;
            break;
        case 3:
            std::cout<<", Decoration Style:  Classic" << std::endl;
            break;
        default:
            std::cout<<"Type : Dummy" << std::endl;
            break;
    }

}



Monthly_rental_appartment::Monthly_rental_appartment() {
    furniture = false;
}

Monthly_rental_appartment::Monthly_rental_appartment(int id, int NR,price Pp, int S,bool entered):Apartments(id,NR,Pp,S) {
    furniture = entered;
}

int Monthly_rental_appartment::CalculatePrice(int days){
    return (days/30)+(days%30!=0)*Price.cost; //calculating the final price and making sure that the number of month is counted correctly, so if the user chooses to stay 31 days it would count to be 2 months
    //the drawback is that we assume that each month has 30 days, we could make it more real by entering the date in the beginning of the program
}

void Monthly_rental_appartment::printer() {
    std::cout<<"Room No: "<< ID;
    std::cout<<", Number of Rooms: "<< Num_of_Rooms;
    std::cout<<", Rent: "<< Price.cost;
    std::cout<<", Size: "<< Size<< std::endl;
    if (furniture==true)
        std::cout<<"Furnished: Yes" << std::endl;
    else
        std::cout<<"Furnished: No" << std::endl;

}




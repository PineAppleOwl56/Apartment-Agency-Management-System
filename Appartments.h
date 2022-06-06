#include<iostream>

#ifndef ASSIGHMENT_2_APPARTMENTS_H
#define ASSIGHMENT_2_APPARTMENTS_H
//the sturcture to store the type of the rent, to easier distinguish it in the code
//no need for any destructors as we do not allocate memory on heap in this classes
struct price{
    int cost;
    char price_type;
};
enum apartType {Dummy,Minimalist, Modern, Classic};
class Apartments{
protected:
    int ID;
    int Num_of_Rooms;
    price Price;// the structure with the integer cost and the charecter for the rent type ('D':Daily rent    'M': Monthly rent)
    int Size;
public:
    Apartments();//basic constructor
    Apartments(int,int,price,int);//constructor with all the variables
    price getPrice() const;
    int getId() const;
    int getNumOfRooms() const;
    int getSize() const;
    void setId(int);
    void setNumOfRooms(int);
    void setPrice(const price &);
    void setSize(int);
    virtual void printer();//making the compiler to choose how to display the flat la
    virtual int CalculatePrice(int);

};

class Daily_rental_appartment:public Apartments {
private:
    enum apartType type;
public:
    Daily_rental_appartment();//basic constructor
    Daily_rental_appartment(int,int,price,int,enum apartType);//constructor with all the variables
    int CalculatePrice(int);
    void printer();
};
class Monthly_rental_appartment:public Apartments {
private:
    bool furniture;
public:
    Monthly_rental_appartment();//basic constructor
    Monthly_rental_appartment(int,int,price,int,bool);//constructor with all the variables
    int CalculatePrice(int);
    void printer();
};
#endif //ASSIGHMENT_2_APPARTMENTS_H

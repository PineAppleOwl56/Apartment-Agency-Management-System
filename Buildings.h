#ifndef ASSIGHMENT_2_BUILDINGS_H
#define ASSIGHMENT_2_BUILDINGS_H
#include"Appartments.h"
#include<iostream>
//the same usage of structure as in the agency class, to create the linked list
struct AppartmentList{
    Apartments* appartment;
    struct AppartmentList* next;
};
//structure for the record keeping
struct AppartmentRecord{
    struct AppartmentList *head;
    struct AppartmentList *tail;
    int size;
};
class Buildings{
private:
    int ID;
    char* Adress;
    struct AppartmentRecord *Record;
public:
    Buildings();// basic constructor
    ~Buildings();// destructor, needed as we use pointers in the private part
    Buildings(int,const char*);
    Buildings(int,const char*, AppartmentRecord*);
    int getId() const;
    AppartmentRecord *getRecord() const;
    const char *getAdress() const;
    void setId(int id);
    void setAdress(char *adress);
    void setRecord(AppartmentRecord *record);
    void Add_Appartment(Apartments&);
    void Print_Specific_Appartment_Room(int);
    void Print_Bigger_then_Appartment_Size(int);
    void Print_Cheaper_then_Appartment_days(int,int);
    void Print_Daily_or_Monthly(char);
    void Rental_Price_Cullculator(int,int);
    void Buldings_and_Adress_printer();
    void Buldings_with_Appartments_printer();
    int CheackOccurance(int,char);//checks if the user tryes to enter a flat that is already in the system, but the flat can still be in different categories, such as daily rent or monthly rent
};


#endif //ASSIGHMENT_2_BUILDINGS_H

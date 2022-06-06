
#ifndef ASSIGHMENT_2_AGENCY_H
#define ASSIGHMENT_2_AGENCY_H
#include<iostream>
#include"Buildings.h"
//creating a structure for the linked list implementation
struct BuildingsList{
    Buildings* building;
    struct BuildingsList* next;
};
//creating a structure for the record of tall the buildings and their number
struct BuildingsRecord{
    struct BuildingsList *head;
    struct BuildingsList *tail;
    int size;
};
class Agency{
private:
    int buildingsID; // storing the ides of the building here provides that noone could alter it in the main function
    char* name; // name of the agency
    struct BuildingsRecord* container; //record of all the buildings
public:
    Agency();  //basic constructor
    ~Agency();// destructor, needed because we store many pointers
    Agency(char*,Buildings&);//constructor for all the private member, no need to send the id because we do not allow anyone to change it themselves
    char *getName() const;
    BuildingsRecord *getContainer() const;
    Buildings* getBuildingsRecord(int);
    void addBuildingsId();
    int getBuildingsId() const;
    void setName(char *name);
    void setContainer(BuildingsRecord *container);
    void Add_New_Building(Buildings&);
    void Aggency_Buildings_adresses();
    void Aggency_Buildings_Appartment_Spec_Room(int);
    void Aggency_Buildings_Appartment_Bigger_Room(int);
    void Aggency_Buildings_Appartment_Cheper(int,int);
    void Aggency_Buildings_DM(char);
    void All_Appartments_printer();
    void Aggency_Buildings_Appartment_Price(int,int,int);
    int CheackOccurance(char*);//checking for the building occurrence
};



#endif //ASSIGHMENT_2_AGENCY_H

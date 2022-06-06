#include"Agency.h"

Agency::Agency() {
    buildingsID=-1;
    name = new char[30];
    strcpy(name, "Nmae_not_set");
    container= new BuildingsRecord;
    container->size=0;
    container->head=new BuildingsList;
    container->tail=container->head;
}
Agency::Agency(char*name_of_ag,Buildings& house){
    name = new char[30];
    buildingsID=0;
    strcpy(name, name_of_ag);
    container= new BuildingsRecord;
    container->size=1;
    container->head=new BuildingsList;
    container->head->building=&house;
    container->head->next=NULL;
    container->tail=container->head;
}
void Agency::Add_New_Building(Buildings&site){
    if (container->size==0){
        container->head->building=&site;
        container->size++;
        container->head->next=NULL;
        container->tail = container->head;
    }
    else{
        container->tail->next=new BuildingsList;
        container->tail=container->tail->next;
        container->tail->next=NULL;
        container->tail->building=&site;
        container->size++;
    }
}
void Agency::All_Appartments_printer(){
    BuildingsList*temp;
    temp=container->head;
    while(temp!=NULL){
        temp->building->Buldings_with_Appartments_printer();
        temp=temp->next;
    }
}
char *Agency::getName() const {
    return name;
}

void Agency::setName(char *name) {
    this->name = name;
}
Buildings* Agency::getBuildingsRecord(int id){
    BuildingsList* temp;
    temp=container->head;
    while(temp->building->getId()!=id)
        temp=temp->next;
    return temp->building;
}
// as we store each building in a pointer way and each building has its own pointers, we need to first destroy the buildings
Agency::~Agency() {
    BuildingsList *next1;
    do{
        next1=container->head->next;
        delete container->head->building;
        container->head=next1;
    }while(next1!=NULL);
    delete [] name;
    delete container;
}

BuildingsRecord *Agency::getContainer() const {
    return container;
}

void Agency::setContainer(BuildingsRecord *container) {
    Agency::container = container;
}
//displaying all the buildings adresses
void Agency::Aggency_Buildings_adresses(){
    BuildingsList*temp;
    temp=container->head;
    while(temp!=NULL){
        temp->building->Buldings_and_Adress_printer();
        temp=temp->next;
    }
}
//
void Agency::Aggency_Buildings_Appartment_Spec_Room(int number){
    BuildingsList*temp;
    temp=container->head;
    while(temp!=NULL){
        //if there are more buidings in the agency record then 1, we display the address of the building first,to avoid misunderstandings
        if (container->size>1)
            std::cout<<"Id: "<<temp->building->getId()<<" ,Adress: "<<temp->building->getAdress()<<std::endl;
        temp->building->Print_Specific_Appartment_Room(number);
        temp=temp->next;
    }
}


void Agency::Aggency_Buildings_Appartment_Bigger_Room(int room_size){
    BuildingsList*temp;
    temp=container->head;
    while(temp!=NULL){
        //if there are more buidings in the agency record then 1, we display the address of the building first,to avoid misunderstandings
        if (container->size>1)
            std::cout<<"Id: "<<temp->building->getId()<<" ,Adress: "<<temp->building->getAdress()<<std::endl;
        //checking the flats in the buildings
        temp->building->Print_Bigger_then_Appartment_Size(room_size);
        temp=temp->next;
    }
}

void Agency::Aggency_Buildings_Appartment_Cheper(int price,int number_of_days){
    BuildingsList*temp;
    temp=container->head;
    while(temp!=NULL){
        //if there are more buidings in the agency record then 1, we display the address of the building first,to avoid misunderstandings
        if (container->size>1)
            std::cout<<"Id: "<<temp->building->getId()<<" ,Adress: "<<temp->building->getAdress()<<std::endl;
        //checking the flats in the buildings
        temp->building->Print_Cheaper_then_Appartment_days(price,number_of_days);
        temp=temp->next;
    }
}
void Agency::Aggency_Buildings_DM(char type){
    BuildingsList*temp;
    temp=container->head;
    while(temp!=NULL){
        //if there are more buidings in the agency record then 1, we display the address of the building first,to avoid misunderstandings
        if (container->size>1)
            std::cout<<"Id: "<<temp->building->getId()<<" ,Adress: "<<temp->building->getAdress()<<std::endl;
        //checking the flats in the buildings
        temp->building->Print_Daily_or_Monthly(type);
        temp=temp->next;
    }
}


void Agency::Aggency_Buildings_Appartment_Price(int build, int id,int number_of_days){
    BuildingsList*temp;
    temp=container->head;
    //culculating the specific flat price
    while((temp->building->getId()!=build)&&(temp!=NULL)) {
        temp=temp->next;
    }
    temp->building->Rental_Price_Cullculator(id, number_of_days);
    }

//this function is used to check if a new building the user tries to enter is not already in the system
int Agency::CheackOccurance(char *str){
    BuildingsList *temp;
    temp=container->head;
    while(temp!=NULL){
        if(strcmp(temp->building->getAdress(),str)==0)
            return 1;
        else
            temp=temp->next;
    }
    return 0;
}

int Agency::getBuildingsId() const {
    return buildingsID;
}
//incrementing the buildings count so that the number of the buildings id would go in order
void Agency::addBuildingsId() {
    buildingsID++;
}


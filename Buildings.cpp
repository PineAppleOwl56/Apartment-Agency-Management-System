#include "Buildings.h"


//in many codes i use errorinput as a flag to output an error message if the function could not find anything that it was looking for
Buildings::Buildings() {
    ID=0;
    Adress = new char[50];
    strcpy(Adress,"No_adress_set");
    Record = new AppartmentRecord;
    Record->size=0;
    Record->head = new AppartmentList;
    Record->tail = Record->head;
}

Buildings::Buildings(int id, const char* name, AppartmentRecord*record){
    ID=id;
    Adress = new char[50];
    strcpy(Adress,name);
    Record = record;
}
Buildings::Buildings(int id, const char* name){
    ID=id;
    Adress = new char[50];
    strcpy(Adress,name);
    Record = new AppartmentRecord;
    Record->size=0;
    Record->head = new AppartmentList;
    Record->tail = Record->head;
    Record->head->next=NULL;
}
int Buildings::getId() const {
    return ID;
}
const char *Buildings::getAdress() const {
    return Adress;
}
AppartmentRecord *Buildings::getRecord() const {
    return Record;
}

void Buildings::setId(int id) {
    ID = id;
}
void Buildings::setAdress(char *adress) {
    Adress = adress;
}
void Buildings::setRecord(AppartmentRecord *record) {
    Record = record;
}

void Buildings::Add_Appartment(Apartments &flat){
    //if we do not have any flat in the record of the building, we add them to it
    if (Record->size==0){
        Record->head->appartment=&flat;
        Record->size++;
        Record->head->next=NULL;
        Record->tail = Record->head;
    }
    //we if do have any record of flats in the building we assign a new one to the end
    else{
        Record->tail->next=new AppartmentList;
        Record->tail=Record->tail->next;
        Record->tail->next=NULL;
        Record->tail->appartment=&flat;
        Record->size++;
    }
}

void Buildings::Print_Specific_Appartment_Room(int room_num){
    AppartmentList *temp;
    temp=Record->head;
    //using for loop for 2 iterations because we need to display two different types of flats individually
    for(int i=0;i<2;i++) {
        int inputerror=0;
        temp = Record->head;
        //displaying the daily apartments first then the ones with monthly rent
        if(i==0){
            std::cout<<"Daily Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                //checking if the flats rent  is chosen correctly and that the number of rooms are the one we are looking for
                if (((temp->appartment->getPrice()).price_type=='D')&&(temp->appartment->getNumOfRooms()==room_num)) {
                    temp->appartment->printer();
                    temp = temp->next;
                }
                else{
                    inputerror++;
                    temp = temp->next;
                }
            }
            if (inputerror==Record->size)
                std::cout<<"Not Found"<<std::endl;
        }
        else{
            //similar implementation as for the daily rent room search
            std::cout<<"Monthly Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                if (((temp->appartment->getPrice()).price_type=='M')&&(temp->appartment->getNumOfRooms()==room_num)) {
                    temp->appartment->printer();
                    temp = temp->next;
                }
                else{
                    inputerror++;
                    temp = temp->next;
                }
            }
            if (inputerror==Record->size)
                std::cout<<"Not Found"<<std::endl;
        }
    }

}
// has similar implementation as the function of room search but here with the size parameter
void Buildings::Print_Bigger_then_Appartment_Size(int room_size){
    AppartmentList *temp;
    //using for loop for 2 iterations because we need to display two different types of flats individually
    for(int i=0;i<2;i++) {
        int inputerror=0;
        temp = Record->head;
        if(i==0){
            std::cout<<"Daily Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                if (((temp->appartment->getPrice()).price_type=='D')&&(temp->appartment->getSize()>=room_size)) {
                    temp->appartment->printer();
                    temp = temp->next;
                }
                else{
                    inputerror++;
                    temp = temp->next;
                }
            }
            if (inputerror==Record->size)
                std::cout<<"Not Found"<<std::endl;
        }
        else{
            std::cout<<"Monthly Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                if (((temp->appartment->getPrice()).price_type=='M')&&(temp->appartment->getSize()>=room_size)) {
                    temp->appartment->printer();
                    temp = temp->next;
                }
                else{
                    inputerror++;
                    temp = temp->next;
                }
            }
            if (inputerror==Record->size)
                std::cout<<"Not Found"<<std::endl;
        }
    }
}
// has similar implementation as the function of room search but here with the price parameter
void Buildings::Print_Cheaper_then_Appartment_days(int price, int num_of_days){
    AppartmentList *temp;
    int inputerror=0;
    //using for loop for 2 iterations because we need to display two different types of flats individually
    for(int i=0;i<2;i++) {
        inputerror=0;
        temp = Record->head;
        if(i==0){
            std::cout<<"Daily Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                if (((temp->appartment->getPrice()).price_type=='D')&&((temp->appartment->getPrice()).cost<= ((price/num_of_days)+price%num_of_days))) {
                    temp->appartment->printer();
                    temp = temp->next;
                }
                else{
                    inputerror++;
                    temp = temp->next;
                }
            }
            if (inputerror==Record->size)
                std::cout<<"Not Found"<<std::endl;
        }
        else{
            std::cout<<"Monthly Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                if (((temp->appartment->getPrice()).price_type=='M')&&((temp->appartment->getPrice()).cost<= price/((num_of_days/30)+(num_of_days%30!=0)))){
                    temp->appartment->printer();
                    temp = temp->next;
                }
                else{
                    inputerror++;
                    temp = temp->next;
                }
            }
            if (inputerror==Record->size)
                std::cout<<"Not Found"<<std::endl;
        }
    }
}

void Buildings::Print_Daily_or_Monthly(char type_of_flat){
    AppartmentList* temp;
    temp=Record->head;
    int inputerror=0;
    if(type_of_flat=='D'){
        std::cout<<"Daily Rental Apartments:"<<std::endl;
        while (temp != NULL) {
            if ((temp->appartment->getPrice()).price_type == type_of_flat) {
                temp->appartment->printer();
                temp = temp->next;
            }
            else{
                inputerror++;
                temp = temp->next;
            }
        }
        if (inputerror==Record->size)
            std::cout<<"Not Found"<<std::endl;
    }
    else{
        std::cout<<"Monthly Rental Apartments:"<<std::endl;
        while (temp != NULL) {
            if ((temp->appartment->getPrice()).price_type == type_of_flat) {
                temp->appartment->printer();
                temp = temp->next;
            }
            else{
                inputerror++;
                temp = temp->next;
            }
        }
        if (inputerror==Record->size)
            std::cout<<"Not Found"<<std::endl;
    }

}

void Buildings::Rental_Price_Cullculator(int id,int num_of_days){
    AppartmentList *temp;
    int inputerror=0;
    temp=Record->head;
    while ((temp!=NULL)&&(temp->appartment->getId()!=id)){
        temp=temp->next;
        inputerror++;
    }
    if (inputerror!=Record->size){
        if ((temp->appartment->getPrice()).price_type=='D')
            std::cout<<"The price is : "<<(temp->appartment->CalculatePrice(num_of_days))<<std::endl;
        else{
            std::cout<<"The price is : "<<(temp->appartment->CalculatePrice(num_of_days))<<std::endl;
        }
    }
    else
        std::cout<<"No such flat"<<std::endl;
}

void Buildings::Buldings_and_Adress_printer(){
    std::cout<<"ID: "<<ID;
    std::cout<<", Adress: "<<Adress<<std::endl;
}

void Buildings::Buldings_with_Appartments_printer(){
    AppartmentList*temp;
    std::cout << "In Building: "<< "ID: " << ID<< ", Adress: " << Adress << std::endl;
    //using for loop for 2 iterations because we need to display two different types of flats individually
    for(int i=0;i<2;i++) {
        temp = Record->head;
        if(i==0){
            std::cout<<"Daily Rental Apartments:"<<std::endl;
            while (temp != NULL) {
                if ((temp->appartment->getPrice()).price_type=='D')
                    temp->appartment->printer();
                temp = temp->next;
            }
        }
        else{
            std::cout<<"Monthly Rental Apartments:"<<std::endl;

            while (temp != NULL) {
                if ((temp->appartment->getPrice()).price_type=='M')
                    temp->appartment->printer();
                temp = temp->next;
            }
        }
    }
}
Buildings::~Buildings(){
    delete [] Adress;
    delete Record;
}

//checking if the user is trying to add a flat that already exists
int Buildings::CheackOccurance(int number,char Type) {
    AppartmentList *temp;
    temp=Record->head;
    while(temp!=NULL){
        if((temp->appartment->getId()==number)&&(temp->appartment->getPrice().price_type==Type))
            return 1;
        else
            temp=temp->next;
    }
    return 0;
}











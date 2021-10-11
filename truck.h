//class for truck
#include<bits/stdc++.h>
#include "vehicle.h"

using namespace std;
class Truck: public Vehicle
{
private:
    string TruckCompany;
    string MaterialExport;
    int Permission;
public:
    Truck(){
        TruckCompany="";
        MaterialExport="";
        Permission=0;
    }
    void travelpermission(){
        cout<<"Does this truck has permission to travel? 1 for yes|| 0 for no: ";
        cout.flush();
        cin>>Permission;
        //getline(cin>>ws,Permission);

    }
    void addentry(){
        cout<<"Enter Truck Company Name: ";
        cout.flush();
        getline(cin >> ws,TruckCompany);

        cout<<"Enter Material Export: ";
        cout.flush();
        getline(cin >> ws,MaterialExport);
    }
    void displayentry(){
        cout<<"Truck Company Name: "<<TruckCompany<<endl;
        cout<<"Material Export: "<<MaterialExport<<endl;
        if(Permission){
            cout<<"This truck has permission to travel"<<endl;
        }
        else{
            cout<<"This truck doesnt have permission to travel"<<endl;
        }
    }
    ~Truck(){
    }
};

#include<bits/stdc++.h>
using namespace std;
static int vehicleID;
class Vehicle
{
private:
    int VehicleID;
    string VehicleRegistration;
    bool Fine;
    int FineAmount;
public:
    Vehicle()
    {
        FineAmount=0;
        Fine=false;
        VehicleRegistration=" ";
        VehicleID=-1;
    }
    void addEntry()
    {
        vehicleID++;
        VehicleID=vehicleID;
        cout<<"Enter Vehicle Registration date: ";
        cout.flush();
        cin>>VehicleRegistration;
    }
    void addFine()
    {
        Fine=true;
        cout<<"Enter Fine Amount: ";
        cout.flush();
        cin>>FineAmount;
    }
    void displayInfo()
    {
        cout<<"Vehicle ID: "<<VehicleID<<endl;
        cout<<"Vehicle Registration Date: "<<VehicleRegistration<<endl;
        if(Fine)
        {
            cout<<"The following Vehicle has a fine of :"<<FineAmount<<endl;
        }
    }
    ~Vehicle()
    {

    }

};

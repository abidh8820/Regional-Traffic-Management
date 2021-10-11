#include <bits/stdc++.h>
using namespace std;

static int bb;

class Vehicle {
   private:
    int VehicleID;
    string VehicleRegistration;
    bool Fine;
    int FineAmount;

   public:
    Vehicle() {
        FineAmount = 0;
        Fine = false;
        VehicleRegistration = " ";
        VehicleID = -1;
    }
    void addEntry() {
        VehicleID = ++bb;
        cout << "Enter Vehicle Registration date: ";
        cout.flush();
        cin >> VehicleRegistration;
    }
    void addFine() {
        Fine = true;
        cout << "Enter Fine Amount: ";
        cout.flush();
        cin >> FineAmount;
    }

    void displayInfo() {
        cout << "Vehicle ID: " << VehicleID << endl;
        cout << "Vehicle Registration Date: " << VehicleRegistration << endl;
        if (Fine) {
            cout << "The following Vehicle has a fine of :" << FineAmount
                 << endl;
        }
    }
    ~Vehicle() {}
};


static int carID;

class PrivateCar: public Vehicle
{
private:
    string CarCompany;
    int CarID;
public:
    PrivateCar(){
        CarCompany="";
        CarID=-1;
    }
    void addentry(){
        cout<<"Enter Car Company Name: ";
        cout.flush();
        getline(cin >> ws,CarCompany);

        carID++;
        CarID=carID;
    }
    void displayentry(){
        cout<<"Car Company Name: "<<CarCompany<<endl;
        cout<<"Car ID: "<<CarID<<endl;
    }
    ~PrivateCar(){
    }
};

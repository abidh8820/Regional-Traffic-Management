#include<bits/stdc++.h>
using namespace std;
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

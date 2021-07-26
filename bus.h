#include<bits/stdc++.h>
using namespace std;
static int busID;
class Bus: public Vehicle
{
private:
    string BusCompany;
    int BusID;
public:
    Bus(){
        BusCompany="";
        BusID=-1;
    }
    void addentry(){
        cout<<"Enter Bus Company Name: ";
        cout.flush();
        getline(cin >> ws,BusCompany);

        busID++;
        BusID=busID;
    }
    void displayentry(){
        cout<<"Bus Company Name: "<<BusCompany<<endl;
        cout<<"Bus ID: "<<BusID<<endl;
    }
    ~Bus(){
    }
};

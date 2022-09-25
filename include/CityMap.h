#include<bits/stdc++.h>
#include "Vehicle.h"
using namespace std;

void RoadStatus(int noofCar);
class CityMap
{
private:
    string HospitalAdress;
    string PoliceStationAdress;
    string RabStationAdress;
    string StadiumAdress;
    string SchoolAdress;
    string ShoppingMall;
    string CentralMosque;
    int noofCar;
    int carlimit;
public:
    //vector<Vehicle>vivi;

    CityMap()
    {
        HospitalAdress="House-50, Road-9, Sector-5, Uttara, Dhaka-1230";
        PoliceStationAdress="House-23 , Road-15 , Sector-3, Uttara, Dhaka-1230";
        RabStationAdress="House-20, Road-3, Sector-4, Uttara, Dhaka-1230";
        StadiumAdress="House-10, Road- 9, Sector- 5, Uttara, Dhaka-1230";
        ShoppingMall="House-5, Road- 25, Sector -3, Uttara, Dhaka-1230";
        CentralMosque="House- 29, Road -10, Sector -5, Uttara, Dhaka-1230";
        noofCar=0;
    }

    void AddVehicleInfo(/*Vehicle &vivia*/)
    {
        noofCar++;
        //vivi.push_back(vivia);
        ///add vehicle objects
    }

    void TrafficCondition()
    {
        if(noofCar<20)
        {
            cout<<"Low Traffic"<<endl;
        }
        else if(noofCar>20 && noofCar<50)
        {
            cout<<"Medium Traffic"<<endl;
        }
        else
        {
            cout<<"Heavy Traffic than usual"<<endl;
        }
    }
    friend void RoadStatus(int noofCar);


    void PrintMap()
    {
        ifstream filepointer;
        string line;
        filepointer.open("map.txt");

        getline(filepointer,line);
        while ( !filepointer.eof() )
        {

            cout << line;
            cout<<endl;
            getline(filepointer,line);
        }
        filepointer.close();
    }
    string returnOption()
    {
        findpath:
        int option;
        cout<<"--Enter Option:\n1. Hospital Adress\n2.Police Station Adress\n3.Rab Station Adress\n4.Stadium Adress\n";
        cout<<"5.Shopping Mall Adress\n6.Central Mosque Adress"<<endl;
        cin>>option;

        try
        {

            if(option==1)
            {
                return HospitalAdress;
            }
            else if(option==2)
            {
                return PoliceStationAdress;
            }
            else if(option==3)
            {
                return RabStationAdress;
            }
            else if(option==4)
            {
                return StadiumAdress;
            }
            else if(option==5)
            {
                return ShoppingMall;

            }
            else if(option==6)
            {
                return CentralMosque;
            }
            else
            {
                throw(option);
            }
        }

        catch(int option)
        {
            cout<<option<<" is a Invalid Option! "<<endl;
            goto findpath;
        }
    }
    void printAdress()
    {
        string adress=returnOption();
        cout<<"The following Adress:\n"<<adress<<endl;
    }

};

void RoadStatus(int noofCar)
{
    if(noofCar<20)
    {
        cout<<"Low Traffic"<<endl;
    }
    else if(noofCar>20 && noofCar<50)
    {
        cout<<"Medium Traffic"<<endl;
    }
    else
    {
        cout<<"Heavy Traffic than usual"<<endl;
    }
}
class Route: public CityMap
{
private:
    string destination;
    string source;
public:
    Route()
    {
        destination=" ";
        source=" ";
    }
    void TakeSource()
    {
        cout<<"Enter your source adress: ";
        source=returnOption();
    }
    void TakeDestination()
    {
        cout<<"Enter your destination :";
        destination=returnOption();
    }
    void PrintRoute()
    {
        ifstream filepointer;
        string line;
        filepointer.open("Route.txt");

        getline(filepointer,line);
        while ( !filepointer.eof() )
        {

            cout << line;
            cout<<endl;
            getline(filepointer,line);
        }
        filepointer.close();
    }
    ~Route() {}
};

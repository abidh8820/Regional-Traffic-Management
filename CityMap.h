#include<bits/stdc++.h>
using namespace std;
class Map
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

    Map()
    {
        HospitalAdress="House-50, Road-9, Sector-5, Uttara, Dhaka-1230";
        PoliceStationAdress="House-23 , Road-15 , Sector-3, Uttara, Dhaka-1230";
        RabStationAdress="House-20, Road-3, Sector-4, Uttara, Dhaka-1230";
        StadiumAdress="House-10, Road- 9, Sector- 5, Uttara, Dhaka-1230";
        ShoppingMall="House-5, Road- 25, Sector -3, Uttara, Dhaka-1230";
        CentralMosque="House- 29, Road -10, Sector -5, Uttara, Dhaka-1230";
        noofCar=0;
    }
    ///vector<vehicle>v1;
    void AddVehicleInfo()
    {
        noofCar++;
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
        int option;
        cout<<"--Enter Option to get Adress for the following:\n1. Hospital Adress\n2.Police Station Adress\n3.Rab Station Adress\n4.Stadium Adress\n";
        cout<<"5.Shopping Mall Adress\n6.Central Mosque Adress"<<endl;
        cin>>option;
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
                return "Invalid!";
            }
    }
    void printAdress()
    {
        string adress=returnOption();
        cout<<"The following Adress:\n"<<adress<<endl;
    }
};


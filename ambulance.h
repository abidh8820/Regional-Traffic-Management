#include<bits/stdc++.h>
using namespace std;
class Ambulance: public Vehicle
{
private:
    string HospitalName;
    string ServiceType;
    string Route;

public:
    Ambulance(){
        HospitalName="";
        ServiceType="";
        Route="";
    }
    void addentry(){
        cout<<"Enter Hospital Name: ";
        cout.flush();
        getline(cin >> ws,HospitalName);

        cout<<"Enter Type of Service: ";
        cout.flush();
        getline(cin >> ws,ServiceType);


        cout<<"Enter the Route you want to go: ";
        cout.flush();
        getline(cin >> ws,Route);
    }
    void displayentry(){
        cout<<"Hospital Name: "<<HospitalName<<endl;
        cout<<"Type of Service: "<<ServiceType<<endl;
        cout<<"Route: "<<Route<<endl;
    }
    void findRoute(){
        cout<<"Enter Route: "<<endl;
        cin>>Route;
    }
    ~Ambulance(){
    }
};

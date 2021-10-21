#include<bits/stdc++.h>
using namespace std;
template <typename atype>
bool checkcarexit(atype username) {  // checks if file "username" is taken
    ifstream PersonFilePointer;
    username+=".txt";
    PersonFilePointer.open(username);
    if(PersonFilePointer){
        PersonFilePointer.close();
        return false;
    }
    else return true;
}

string get_profesion_type(string filename,int x){
    int lineNO=1;
    string line;
    ifstream myfile;
    myfile.open(filename);
    while(getline(myfile,line)){
        if(lineNO==x){
            return line;
            break;
        }
        lineNO++;
    }
    myfile.close();
}

//static int vehicleID=0;
class Vehicle
{
private:
    string VehicleType;
    string VehicleID;
    string VehicleRegistration;
    bool Fine;
    int FineAmount;
    string VehDriver;
public:
    Vehicle()
    {
        FineAmount=0;
        Fine=false;
        VehicleRegistration="";
        VehicleType="";
        VehicleID="";
        VehDriver="";
    }
    virtual void addEntry()
    {
        cout<<"Enter Vehicle type: ";
        cout.flush();
        getline(cin >> ws,VehicleType);

        while(1){
            string s;
            cout<<"Enter Vehicle ID: ";
            cout.flush();
            getline(cin >> ws,s);
            if(checkcarexit(s)){
                VehicleID=s;
                break;
            }
            else cout <<"Username already taken."<< endl;
        }
        cout<<"Enter Vehicle Registration date: ";
        cout.flush();
        getline(cin >> ws,VehicleRegistration);

        while(1){
            cout<<"Enter Vehicle Driver Name: ";
            cout.flush();
            getline(cin >> ws,VehDriver);
            if (!checkuser(VehDriver)){
                string prof;
                prof=get_profesion_type(VehDriver+".txt",4);
                if(prof=="driver"){
                    cout<<"found"<<endl;
                    string drvname=VehDriver+".txt";
                    fstream myfile;
                    myfile.open(drvname,std::ios_base::app);
                    myfile<<VehicleID<<endl;
                    myfile.close();
                    break;
                }
                else{
                    cout<<"This person is not a driver, Enter name again"<<endl;

                }
            }
            else{
                cout<<"NO matching driver found"<<endl;
            }
        }
    }
    virtual void addFine(string filename)
    {
        int newfine;
        Fine=true;
        cout<<"Enter Fine Amount: ";
        cout.flush();
        cin>>newfine;

        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==1)VehicleType=line;
            else if(lineNO==2)VehicleID=line;
            else if(lineNO==3)VehicleRegistration=line;
            else if(lineNO==4)VehDriver=line;
            else if(lineNO==5){
                line=="true"? Fine=true:false;
            }
            else if(lineNO==6)FineAmount=stoi(line);
            lineNO++;
        }
        myfile.close();
        FineAmount+=newfine;
        vehicle_write_to_file(filename);
    }

    virtual void payFine(string filename)
    {
        int payedfine;
        Fine=true;
        cout<<"Enter payed Amount: ";
        cout.flush();
        cin>>payedfine;

        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==1)VehicleType=line;
            else if(lineNO==2)VehicleID=line;
            else if(lineNO==3)VehicleRegistration=line;
            else if(lineNO==4)VehDriver=line;
            else if(lineNO==5){
                line=="true"? Fine=true:false;
            }
            else if(lineNO==6)FineAmount=stoi(line);
            lineNO++;
        }
        myfile.close();
        FineAmount-=payedfine;
        //vehicle_write_to_file(filename);
    }

    string getVehicleID(){
        string filename;
        filename=VehicleID+".txt";
        return filename;
    }
    virtual void displayInfo()
    {
        cout<<"Vehicle ID: "<<VehicleID<<endl;
        cout<<"Vehicle Registration Date: "<<VehicleRegistration<<endl;
        if(Fine)
        {
            cout<<"The following Vehicle has a fine of :"<<FineAmount<<endl;
        }
        cout<<"Vehicle Driver Name: "<<VehDriver<<endl;
    }
    virtual void vehicle_write_to_file(string filename){
        cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;
        fstream myfile;
        myfile.open(filename, std::ios::out);
        myfile << VehicleType <<endl;
        myfile << VehicleID <<endl;
        myfile << VehicleRegistration <<endl;
        myfile << VehDriver <<endl;
        myfile << Fine <<endl;
        myfile << FineAmount <<endl;
        myfile.close();
    }
    /*Vehicle operator - (int fine_payed){
        FineAmount-fine_payed;
    }
    Vehicle operator + (int fined){
        FineAmount+fined;
    }*/
    ~Vehicle(){}

};

class PrivateCar: public Vehicle
{
private:
    string CarCompany;
    //int CarID;
public:
    PrivateCar(){
        CarCompany="";
        //CarID=-1;
        //CarDriver="";
    }
    void addEntry(){
        cout<<"Enter Car Company Name: ";
        cout.flush();
        getline(cin >> ws,CarCompany);
        Vehicle::addEntry();
        //carID++;
        //CarID=carID;
    }
    void vehicle_write_to_file(string filename){
        /*cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;*/
        Vehicle::vehicle_write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<CarCompany<<endl;
        myfile.close();
    }
    void addFine(string filename)
    {
        Vehicle::addFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)CarCompany=line;
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void payFine(string filename)
    {
        Vehicle::payFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)CarCompany=line;
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void displayInfo(){

        cout<<"Car Company Name: "<<CarCompany<<endl;

        Vehicle::displayInfo();
    }

    ~PrivateCar(){}
};

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
    void addEntry(){
        cout<<"Enter Truck Company Name: ";
        cout.flush();
        getline(cin >> ws,TruckCompany);

        cout<<"Enter Material Export: ";
        cout.flush();
        getline(cin >> ws,MaterialExport);

        cout<<"Does this truck has permission to travel? 1 for yes|| 0 for no: ";
        cout.flush();
        cin>>Permission;

        Vehicle::addEntry();
    }
    void vehicle_write_to_file(string filename){
        /*cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;*/

        Vehicle::vehicle_write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<TruckCompany<<endl;
        myfile<<MaterialExport<<endl;
        myfile<<Permission<<endl;
        myfile.close();
    }
    void addFine(string filename)
    {
        Vehicle::addFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)TruckCompany=line;
            else if(lineNO==8)MaterialExport=line;
            else if(lineNO==9)Permission=stoi(line);
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void payFine(string filename)
    {
        Vehicle::payFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)TruckCompany=line;
            else if(lineNO==8)MaterialExport=line;
            else if(lineNO==9)Permission=stoi(line);
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void displayInfo(){
        cout<<"Truck Company Name: "<<TruckCompany<<endl;
        cout<<"Material Export: "<<MaterialExport<<endl;
        if(Permission){
            cout<<"This truck has permission to travel"<<endl;
        }
        else{
            cout<<"This truck doesnt have permission to travel"<<endl;
        }
        Vehicle::displayInfo();
    }
    ~Truck(){}
};

class Bus: public Vehicle
{
private:
    string BusCompany;
public:
    Bus(){
        BusCompany="";
    }
    void addEntry(){
        cout<<"Enter Bus Company Name: ";
        cout.flush();
        getline(cin >> ws,BusCompany);

        Vehicle::addEntry();
    }
    void vehicle_write_to_file(string filename){
        /*cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;*/

        Vehicle::vehicle_write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<BusCompany<<endl;
        myfile.close();
    }
    void addFine(string filename)
    {
        Vehicle::addFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)BusCompany=line;
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void payFine(string filename)
    {
        Vehicle::payFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)BusCompany=line;
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void displayInfo(){
        cout<<"Bus Company Name: "<<BusCompany<<endl;
        Vehicle::displayInfo();
    }
    ~Bus(){}
};


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
    void addEntry(){
        cout<<"Enter Hospital Name: ";
        cout.flush();
        getline(cin >> ws,HospitalName);

        cout<<"Enter Type of Service: ";
        cout.flush();
        getline(cin >> ws,ServiceType);


        cout<<"Enter the Route you want to go: ";
        cout.flush();
        getline(cin >> ws,Route);

        Vehicle::addEntry();
    }
    void vehicle_write_to_file(string filename){
        /*cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;*/

        Vehicle::vehicle_write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<HospitalName<<endl;
        myfile<<ServiceType<<endl;
        myfile<<Route<<endl;
        myfile.close();
    }

    void addFine(string filename)
    {
        Vehicle::addFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)HospitalName=line;
            else if(lineNO==8)ServiceType=line;
            else if(lineNO==9)Route=line;
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }

    void payFine(string filename)
    {
        Vehicle::payFine(filename);
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(filename);
        while(getline(myfile,line)){
            if(lineNO==7)HospitalName=line;
            else if(lineNO==8)ServiceType=line;
            else if(lineNO==9)Route=line;
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    void displayInfo(){
        cout<<"Hospital Name: "<<HospitalName<<endl;
        cout<<"Type of Service: "<<ServiceType<<endl;
        cout<<"Route: "<<Route<<endl;
        Vehicle::displayInfo();
    }
    void findRoute(){
        cout<<"Enter Route: "<<endl;
        cin>>Route;
    }
    ~Ambulance(){}
};




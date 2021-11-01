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

class seat{
private:
public:
    string comfortability;
    seat():comfortability(""){}
    void setseat(){
        cout<<"Enter seat comfortability:"<<endl;
        getline(cin >> ws,comfortability);

    }
    void getseat(){
        cout<<"the seat is "<<comfortability<<endl;
    }
    ~seat(){
    }
};

class wheel{
private:
public:
    int radius;
    wheel():radius(0){
    }
    void setwheel(){
        cout<<"Enter wheel radius:"<<endl;
        cin>>radius;
    }
    void getwheel(){
        cout<<"The circumference is "<<(double)(2*radius*3.1416)<<endl;
    }
    ~wheel(){
    }
};

class engine{
private:
public:
    int AverageRPM;
    engine():AverageRPM(0){
    }
    void setengine(){
        cout<<"Enter Average RPM is:"<<endl;
        cin>>AverageRPM;
    }
    void getengine(){
        cout<<"Average RPM is: "<<AverageRPM<<endl;
    }
    ~engine(){
    }
};
class door{
private:
public:
    string OpeningMode;
    door():OpeningMode(""){
    }
    void setdoor(){
        cout<<"Enter opening mode of car:"<<endl;
        getline(cin >> ws,OpeningMode);
    }
    void getdoor(){
        cout<<"Opening Mode of car is: "<<OpeningMode<<endl;
    }
    ~door(){
    }

};

class Vehicle
{
protected:
    string VehicleType;
    string VehicleID;
    string VehicleRegistration;
    bool Fine;
    int FineAmount;
    string VehDriver;
    seat st;
    wheel wl;
    engine egn;
    door dr;
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

        st.setseat();
        wl.setwheel();
        egn.setengine();
        dr.setdoor();

        while(1){
            cout<<"Enter Vehicle Driver Name: ";
            cout.flush();
            getline(cin >> ws,VehDriver);
            if (!checkuser(VehDriver)){
                string prof;
                prof=get_profesion_type(VehDriver+".txt",8);
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

    virtual void vehicle_write_to_file(string filename){
        cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;
        fstream myfile;
        myfile.open(filename, std::ios::out);
        myfile <<"Type of Vehicle:"<<endl;
        myfile << VehicleType <<endl;
        myfile <<"Vehicle ID:"<<endl;
        myfile << VehicleID <<endl;
        myfile <<"Vehicle Registration:"<<endl;
        myfile << VehicleRegistration <<endl;
        myfile <<"Vehicle Driver Name:"<<endl;
        myfile << VehDriver <<endl;
        myfile <<"Seat comfortability"<<endl;
        myfile << st.comfortability <<endl;
        myfile <<"Wheel radius:"<<endl;
        myfile << wl.radius <<endl;
        myfile <<"Engine AverageRPM:"<<endl;
        myfile << egn.AverageRPM <<endl;
        myfile <<"Door Opening Mode:"<<endl;
        myfile << dr.OpeningMode <<endl;
        myfile <<"Is Vehicle ever Fined?"<<endl;
        myfile << Fine <<endl;
        myfile <<"Fine Amount"<<endl;
        myfile << FineAmount <<endl;
        myfile.close();
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
            if(lineNO==2)VehicleType=line;
            else if(lineNO==4)VehicleID=line;
            else if(lineNO==6)VehicleRegistration=line;
            else if(lineNO==8)VehDriver=line;
            else if(lineNO==10)st.comfortability=line;
            else if(lineNO==12)wl.radius=stoi(line);
            else if(lineNO==14)egn.AverageRPM=stoi(line);
            else if(lineNO==16)dr.OpeningMode=line;
            else if(lineNO==18){
                line=="true"? Fine=true:false;
            }
            else if(lineNO==20)FineAmount=stoi(line);
            cout<<line<<endl;
            lineNO++;
        }
        myfile.close();
        FineAmount+=newfine;
        //vehicle_write_to_file(filename);
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
            if(lineNO==2)VehicleType=line;
            else if(lineNO==4)VehicleID=line;
            else if(lineNO==6)VehicleRegistration=line;
            else if(lineNO==8)VehDriver=line;
            else if(lineNO==10)st.comfortability=line;
            else if(lineNO==12)wl.radius=stoi(line);
            else if(lineNO==14)egn.AverageRPM=stoi(line);
            else if(lineNO==16)dr.OpeningMode=line;
            else if(lineNO==18){
                line=="true"? Fine=true:false;
            }
            else if(lineNO==20)FineAmount=stoi(line);
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
    ~Vehicle(){}

};

class PrivateCar: public Vehicle
{
protected:
    string CarCompany;
public:
    PrivateCar(){
        CarCompany="";
    }
    void addEntry(){
        cout<<"Enter Car Company Name: ";
        cout.flush();
        getline(cin >> ws,CarCompany);
        Vehicle::addEntry();
    }
    void vehicle_write_to_file(string filename){
        Vehicle::vehicle_write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<"Car Company Name:"<<endl;
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
        cout<<"break"<<endl;
        while(getline(myfile,line)){
            if(lineNO==22)CarCompany=line;
            /*cout<<lineNO<<endl;
            cout<<line<<endl;*/
            lineNO++;
        }
        myfile.close();
        cout<<CarCompany<<endl;
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
            if(lineNO==22)CarCompany=line;
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
        myfile<<"Truck Company Name:"<<endl;
        myfile<<TruckCompany<<endl;
        myfile<<"Material Export:"<<endl;
        myfile<<MaterialExport<<endl;
        myfile<<"Does vehicle has Permission to travel?:"<<endl;
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
            if(lineNO==22)TruckCompany=line;
            else if(lineNO==24)MaterialExport=line;
            else if(lineNO==26)Permission=stoi(line);
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
            if(lineNO==22)TruckCompany=line;
            else if(lineNO==24)MaterialExport=line;
            else if(lineNO==26)Permission=stoi(line);
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
        myfile<<"Bus Company Name:"<<endl;
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
            if(lineNO==22)BusCompany=line;
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
            if(lineNO==22)BusCompany=line;
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
        myfile<<"Hospital Name:"<<endl;
        myfile<<HospitalName<<endl;
        myfile<<"Service Type:"<<endl;
        myfile<<ServiceType<<endl;
        myfile<<"Route:"<<endl;
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
            if(lineNO==22)HospitalName=line;
            else if(lineNO==24)ServiceType=line;
            else if(lineNO==26)Route=line;
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
            if(lineNO==22)HospitalName=line;
            else if(lineNO==24)ServiceType=line;
            else if(lineNO==26)Route=line;
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

class FireService: public Vehicle
{
private:
    bool checkStation;
    string callStation;
    bool accident;
public:
    FireService()
    {
        checkStation=false;
        callStation="-1111";
        accident=false;
        checkAccident();

    }
    void addEntry(){
        int opt;

        cout<<"Enter Call Station: ";
        cout.flush();
        getline(cin >> ws,callStation);

        cout<<"Did accident occur?1.true  2.false "<<endl;
        cin>>opt;
        if(opt==1)accident=true;
        else accident=false;

        checkAccident();

        Vehicle::addEntry();
    }
    void vehicle_write_to_file(string filename){

        Vehicle::vehicle_write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<"Check Station:"<<endl;
        myfile<<checkStation<<endl;
        myfile<<"Call Station:"<<endl;
        myfile<<callStation<<endl;
        myfile<<"Accident:"<<endl;
        myfile<<accident<<endl;
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
            if(lineNO==22){
                line=="true"? checkStation=true:false;
            }
            else if(lineNO==24)callStation=line;
            else if(lineNO==26){
                line=="true"? accident=true:false;
            }
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
            if(lineNO==22){
                line=="true"? checkStation=true:false;
            }
            else if(lineNO==24)callStation=line;
            else if(lineNO==26){
                line=="true"? accident=true:false;
            }
            lineNO++;
        }
        myfile.close();
        vehicle_write_to_file(filename);
    }
    string StationNo()

    {
        return callStation;
    }
    void checkAccident()
    {
        if(accident)
        {
            checkStation=true;
            notifyStation();
        }
    }
    void notifyStation()
    {
        accident=true;
        cout<<"The Message has already been sent to the Fire Station"<<endl;
        cout<<"Call for Service :"<<callStation<<endl;
    }
    ~FireService()
    {

    }

};




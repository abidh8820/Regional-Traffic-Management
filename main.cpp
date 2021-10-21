#include <bits/stdc++.h>
#include <stdio.h>
#include "Person.h"
#include "Vehicle.h"
#include "role.h"

using namespace std;
int main(){
    restart:
    cout << "1.Sign-Up\n2.Login\n3.Vehicle registration\n4.Exit" << endl;
    int option;
    cin >> option;

    if (option == 1) {
        cout << "1.Sign up as Passenger\n2.Sign up as Driver\n3.Sign up as Police" << endl;
        int profession;
        cin >> profession;
        if (profession == 1) {
            Person* passenger=new Passenger;
            passenger->set_info();
            passenger->write_to_file(passenger->getuserID());
            cout<<"Information has been entered successfully!"<<endl<<endl;
            viewFile(passenger->getuserID());
        }
        else  if(profession == 2) {
            Person* driver=new Driver;
            driver->set_info();
            //driver.set_driver_info();
            driver->write_to_file(driver->getuserID());
            //driver.driver_write_to_file(driver.getuserID());
            cout<<"Information has been entered successfully!"<<endl<<endl;
            viewFile(driver->getuserID());

        }
        else if(profession == 3) {
            Person* police=new Police;
            police->set_info();
            //driver.set_driver_info();
            police->write_to_file(police->getuserID());
            //driver.driver_write_to_file(driver.getuserID());
            cout<<"Information has been entered successfully!"<<endl<<endl;
            viewFile(police->getuserID());

        }
        goto restart;
    }

    else if(option == 2){

        string username;
        cout << "Enter User Name :";
        cout.flush();
        getline(cin >> ws,username);
        if (!checkuser(username)){
            retype_password_to_login:
            cout << "Enter Password : ";
            cout.flush();
            string password;
            getline(cin >> ws,password);

            if (checkpass(password,username)) {
                cout << "Login Successful!" << endl<<endl;

            }
            else {
                cout << "Password incorrect" << endl;
                cout << "1.Try again?\n2.Exit" << endl;

                int opt;
                cin>>opt;
                if(opt==1)goto retype_password_to_login;
                else return 0;
            }
        }
        else {
            cout << "Username does not exists!" << endl;
            cout << "Login Failed" << endl;
            cout << "1.Return to menu?\n2.Exit" << endl;

            int opt;
            cin>>opt;
            if(opt==1)goto restart;
            else return 0;
        }

        //logged in

        string prof=get_proffesion(username+".txt");
        cout<<"Logged in as: "<<prof<<endl;
        if (prof != "driver" && prof != "police" && prof != "admin"){
            passenger_login:

            // check if hes a passenger, if not return
            cout << "1.View Personal Information" << endl;
            cout << "2.View Anothers Information" << endl;
            cout << "3.Update Information" << endl;
            cout << "4.Delete Information" << endl;
            cout << "5.View City Map" << endl;
            cout << "6.Find Path" << endl;
            cout << "7.Check Road status" << endl;
            cout << "8.Log out" << endl;

            int option;
            cin >> option;
            Role role;
            role.GivePermissions("User");

            if(option == 1) {
                if(role.viewPersonal())viewFile(username+".txt");
            }
            else if (option == 2) {
                role.viewOthers();
            }
            else if (option == 3) {
                role.updateInfo();
            }
            else if (option == 4) {
                role.deleteInfo();
            }
            else if(option == 8) {
                goto restart;
            }
            else {
                cout << "Enter Source" << endl;
                string source;
                cin >> source;
                cout << "Enter Destination" << endl;
                string destination;
                cin >> destination;
                // then make the pathfinding algorithm
            }
            goto passenger_login;
        }
        else if (prof == "driver"){
            // check if the person is a driver
            driver_login:
            cout << "1.View Personal Information" << endl;
            cout << "2.View Anothers Information" << endl;
            cout << "3.Update Information" << endl;
            cout << "4.Delete Information" << endl;
            cout << "5.View City Map" << endl;
            cout << "6.Find Path" << endl;
            cout << "7.Check Road status" << endl;
            cout << "8.Pay Fine" << endl;
            cout << "9.Log out" << endl;

            int option;
            cin >> option;
            Role role;
            role.GivePermissions("User");

            if(option == 1) {
                if(role.viewPersonal())viewFile(username+".txt");
            }
            else if (option == 2) {
                role.viewOthers();
            }
            else if (option == 3) {
                role.updateInfo();
            }
            else if (option == 4) {
                role.deleteInfo();
            }
            else if(option == 8) {
                string s,vehtype;
                cout<<"Enter Vehicle ID you want to find: ";
                cout.flush();
                getline(cin >> ws,s);
                vehtype=get_profesion_type(s+".txt",1);
                Vehicle* vehic;
                if(vehtype=="car")vehic=new PrivateCar;
                else if(vehtype=="bus")vehic=new Bus;
                else if(vehtype=="truck")vehic=new Truck;
                else if(vehtype=="ambulance")vehic=new Ambulance;
                vehic->payFine(s+".txt");
            }
            else if(option == 9) {
                goto restart;
            }
            goto driver_login;
        }
        else if (prof == "police") {
            // check if the person is a police
            police_login:
            cout << "1.View Personal Information" << endl;
            cout << "2.View Anothers Information" << endl;
            cout << "3.Update Information" << endl;
            cout << "4.Delete Information" << endl;
            cout << "5.View City Map" << endl;
            cout << "6.Find Path" << endl;
            cout << "7.Check Road status" << endl;
            cout << "8.Fine Vehicle" << endl;
            cout << "9.Log out" << endl;

            int option;
            cin >> option;
            Role role;
            role.GivePermissions(prof);

            if(option == 1) {
                if(role.viewPersonal())viewFile(username+".txt");
            }
            else if (option == 2) {
                if(role.viewPersonal()){
                    string s;
                    cout<<"Enter username you want to find: ";
                    cout.flush();
                    getline(cin >> ws,s);
                    viewFile(s+".txt");
                }
            }
            else if (option == 3) {
                role.updateInfo();
            }
            else if (option == 4) {
                role.deleteInfo();
            }
            else if(option == 8) {
                string s,vehtype;
                cout<<"Enter Vehicle ID you want to find: ";
                cout.flush();
                getline(cin >> ws,s);
                vehtype=get_profesion_type(s+".txt",1);
                Vehicle* vehic;
                if(vehtype=="car")vehic=new PrivateCar;
                else if(vehtype=="bus")vehic=new Bus;
                else if(vehtype=="truck")vehic=new Truck;
                else if(vehtype=="ambulance")vehic=new Ambulance;
                vehic->addFine(s+".txt");
            }
            else if(option == 9) {
                goto restart;
            }
            goto police_login;
        }

        else if (prof == "admin"){
            // check if the person is a Admin
            admin_login:
            cout << "1.View Personal Information" << endl;
            cout << "2.View Anothers Information" << endl;
            cout << "3.Update Information" << endl;
            cout << "4.Delete Information" << endl;
            cout << "5.View City Map" << endl;
            cout << "6.Find Path" << endl;
            cout << "7.Check Road status" << endl;
            cout << "8.Log out" << endl;

            int option;
            cin >> option;

            Role role;
            role.GivePermissions(prof);

            if(option == 1) {
                if(role.viewPersonal())viewFile(username+".txt");
            }
            else if (option == 2) {
                if(role.viewPersonal()){
                    string s;
                    cout<<"Enter username you want to find: ";
                    cout.flush();
                    getline(cin >> ws,s);
                    viewFile(s+".txt");
                }
            }
            else if (option == 3) {
                if(role.updateInfo()){
                    string s,s1;
                    cout<<"Enter username you want to find: ";
                    cout.flush();
                    getline(cin >> ws,s);
                    s1=get_proffesion(s+".txt");
                    Person* pers;
                    if(s1=="driver")pers=new Driver;
                    else if(s1=="police")pers=new Police;
                    else if(s1=="admin")pers=new Admin;
                    else pers=new Passenger;
                    pers->update_info(s+".txt");
                }
            }
            else if (option == 4) {
                if(role.deleteInfo()){
                    string s;
                    cout<<"Enter username you want to find: ";
                    cout.flush();
                    getline(cin >> ws,s);
                    s+=".txt";
                    if( remove(s.c_str()) != 0 )perror( "Error deleting file" );
                    else puts( "File successfully deleted" );
                    /*if( remove( s+".txt" ) != 0 )perror( "Error deleting file" );
                    else puts( "File successfully deleted" );*/
                }
            }
            else if(option == 8) {
                goto restart;
            }
            goto admin_login;
        }
    }
    else if(option == 3){
        cout << "1.Car\n2.Bus\n3.Truck\n4.Ambulance" << endl;
        int option;
        cin >> option;
        Vehicle* vehicle;

        if(option==1){
            vehicle=new PrivateCar;
            vehicle->addEntry();
            //cout<<car.getVehicleID();
            vehicle->vehicle_write_to_file(vehicle->getVehicleID());
            //viewcarFile(car.getvehicleID());
            goto restart;

        }
        else if(option==2){
            vehicle=new Truck;
            vehicle->addEntry();
            vehicle->vehicle_write_to_file(vehicle->getVehicleID());
            goto restart;
        }
        else if(option==3){
            vehicle=new Bus;
            vehicle->addEntry();
            vehicle->vehicle_write_to_file(vehicle->getVehicleID());
            goto restart;
        }
        else{
            vehicle=new Ambulance;
            vehicle->addEntry();
            vehicle->vehicle_write_to_file(vehicle->getVehicleID());
            goto restart;
        }

    }
    else return 0;

    return 0;
}

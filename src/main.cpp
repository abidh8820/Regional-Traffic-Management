#include <bits/stdc++.h>
#include <stdio.h>
#include<ctime>
#include "Person.h"
#include "CityMap.h"
#include "role.h"
using namespace std;

void intro ();
void gettime ();

int main ()
{

    intro ();
    cout << endl;
    gettime();
    cout << endl;

    cout <<
         "----------------------------------------------------------------------------"
         << endl;
    cout <<
         "----------------------------------------------------------------------------"
         << endl;

    restart:
    cout << "1.Sign-Up\n2.Login\n3.Vehicle registration\n4.Emergency Contact\n5.Exit" << endl;
    cout << "Enter your option: ";
    int option;
    cin >> option;
    CityMap citymap;


    if (option == 1)
    {
        try
        {
            cout <<
                 "1.Sign up as Passenger\n2.Sign up as Driver\n3.Sign up as Police"
                 << endl;
            cout << "Enter your option: ";
            int profession;
            cin >> profession;
            if (profession == 1)
            {
                Person *passenger = new Passenger;
                passenger->set_info ();
                passenger->write_to_file (passenger->getuserID ());
                cout << "Information has been entered successfully!" << endl <<
                     endl;
                viewFile (passenger->getuserID ());

            }

            else if (profession == 2)
            {
                Person *driver = new Driver;
                driver->set_info ();
                //driver.set_driver_info();
                driver->write_to_file (driver->getuserID ());
                //driver.driver_write_to_file(driver.getuserID());
                cout << "Information has been entered successfully!" << endl <<
                     endl;
                viewFile (driver->getuserID ());

            }
            else if (profession == 3)
            {
                Person *police = new Police;
                police->set_info ();
                //driver.set_driver_info();
                police->write_to_file (police->getuserID ());
                //driver.driver_write_to_file(driver.getuserID());
                cout << "Information has been entered successfully!" << endl <<
                     endl;
                viewFile (police->getuserID ());

            }
            else
            {
                throw (profession);
            }

        }

        catch (int profession)
        {
            cout <<profession << " is Invalid option! " << endl;
        }

        cout <<
             "----------------------------------------------------------------------------"
             << endl;
        cout <<
             "----------------------------------------------------------------------------"
             << endl;
        goto restart;
    }

    else if (option == 2)
    {

        string username;
        cout << "Enter User Name :";
        cout.flush ();
        getline (cin >> ws, username);
        if (!checkuser (username))
        {
            retype_password_to_login:
            cout << "Enter Password : ";
            cout.flush ();
            string password;
            getline (cin >> ws, password);

            if (checkpass < string, string > (password, username))
            {
                cout << "Login Successful!" << endl << endl;

            }
            else
            {
                cout << "Password incorrect" << endl;
                cout << "1.Try again?\n2.Exit" << endl;

                int opt;
                cin >> opt;
                if (opt == 1)
                    goto retype_password_to_login;
                else
                    return 0;
            }

            cout <<
                 "----------------------------------------------------------------------------"
                 << endl;
            cout <<
                 "----------------------------------------------------------------------------"
                 << endl;
        }
        else
        {
            cout << "Username does not exists!" << endl;
            cout << "1.Return to menu?\n2.Exit" << endl;

            int opt;
            cin >> opt;
            if (opt == 1)
                goto restart;
            else
                return 0;
        }
        string prof = get_proffesion (username + ".txt");
        cout << "Logged in as: " << prof << endl;
        if (prof != "driver" && prof != "police" && prof != "admin")
        {
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
            role.GivePermissions ("User");


            if (option == 1)
            {
                if (role.viewPersonal())
                    viewFile (username + ".txt");
            }
            else if (option == 2)
            {
                role.viewOthers();
            }
            else if (option == 3)
            {
                role.updateInfo();
            }
            else if (option == 4)
            {
                role.deleteInfo();
            }
            else if (option == 5)
            {
                citymap.PrintMap();
            }
            else if (option == 6)
            {
                Route route;
                route.TakeSource();
                route.TakeDestination();
                route.PrintRoute();
            }
            else if (option == 7)
            {
                citymap.TrafficCondition();
            }
            else if (option == 8)
            {
                goto restart;
            }

            cout <<
                 "----------------------------------------------------------------------------"
                 << endl;
            cout <<
                 "----------------------------------------------------------------------------"
                 << endl;

            goto passenger_login;
        }
        else if (prof == "driver")
        {
            // check if the person is a driver
            cout << "Are you driving right now?\n1.Yes\n2.No" << endl;
            int driving;
            cin >> driving;
            if (driving == 1)
            {
                /*Vehicle d;
                cout<<"Add Vehicle Information: "<<endl;
                d.addEntry();*/

                citymap.AddVehicleInfo ();

            }

            cout <<
                 "----------------------------------------------------------------------------"
                 << endl;
            cout <<
                 "----------------------------------------------------------------------------"
                 << endl;

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
            role.GivePermissions ("User");

            if (option == 1)
            {
                if (role.viewPersonal())
                    viewFile (username + ".txt");
            }
            else if (option == 2)
            {
                role.viewOthers();
            }
            else if (option == 3)
            {
                role.updateInfo();
            }
            else if (option == 4)
            {
                role.deleteInfo();
            }
            else if (option == 5)
            {
                citymap.PrintMap();
            }
            else if (option == 6)
            {
                Route route;
                route.TakeSource();
                route.TakeDestination();
                route.PrintRoute();

            }

            else if (option == 7)
            {
                citymap.TrafficCondition();
            }
            else if (option == 8)
            {
                string s, vehtype;
                cout << "Enter Vehicle ID you want to find: " << endl;
                getline (cin >> ws, s);
                if (checkcarexit (s))
                {
                    cout << "Vehicle ID does not exist" << endl;
                    goto driver_login;
                }
                vehtype = get_profesion_type (s + ".txt", 2);
                Vehicle *vehic;
                if (vehtype == "car")
                    vehic = new PrivateCar;
                else if (vehtype == "bus")
                    vehic = new Bus;
                else if (vehtype == "truck")
                    vehic = new Truck;
                vehic->payFine (s + ".txt");
            }
            else if (option == 9)
            {
                goto restart;
            }
            goto driver_login;
        }
        else if (prof == "police")
        {
            // check if the person is a police
            police_login:
            cout << "1.View Personal Information" << endl;
            cout << "2.View Anothers Information" << endl;
            cout << "3.Update Information" << endl;
            cout << "4.Delete Information" << endl;
            cout << "5.View City Map" << endl;
            cout << "6.Find Path" << endl;
            cout << "7.Check Road status" << endl;
            cout << "8.Add Fine to Vehicle" << endl;
            cout << "9.Log out" << endl;

            int option;
            cin >> option;
            Role role;
            role.GivePermissions (prof);

            if (option == 1)
            {
                if (role.viewPersonal())
                    viewFile (username + ".txt");
            }
            else if (option == 2)
            {
                if (role.viewPersonal())
                {
                    string s;
                    cout << "Enter username you want to find: ";
                    cout.flush ();
                    getline (cin >> ws, s);
                    viewFile (s + ".txt");
                }
            }
            else if (option == 3)
            {
                role.updateInfo();
            }
            else if (option == 4)
            {
                role.deleteInfo();
            }
            else if (option == 5)
            {
                citymap.PrintMap();
            }
            else if (option == 6)
            {
                Route route;
                route.TakeSource();
                route.TakeDestination();
                route.PrintRoute();

            }
            else if (option == 7)
            {
                citymap.TrafficCondition();
            }
            else if (option == 8)
            {
                string s, vehtype;
                cout << "Enter Vehicle ID you want to find: " << endl;
                getline (cin >> ws, s);
                if (checkcarexit (s))
                {
                    cout << "Vehicle ID does not exist" << endl;
                    goto police_login;
                }
                vehtype = get_profesion_type (s + ".txt", 2);
                Vehicle *vehic;
                if (vehtype == "car")
                    vehic = new PrivateCar;
                else if (vehtype == "bus")
                    vehic = new Bus;
                else if (vehtype == "truck")
                    vehic = new Truck;
                vehic->addFine (s + ".txt");
            }
            else if (option == 9)
            {
                goto restart;
            }
            goto police_login;
        }

        else if (prof == "admin")
        {
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
            role.GivePermissions (prof);

            if (option == 1)
            {
                if (role.viewPersonal ())
                    viewFile (username + ".txt");
            }
            else if (option == 2)
            {
                if (role.viewPersonal ())
                {
                    string s;
                    cout << "Enter username you want to find: ";
                    cout.flush ();
                    getline (cin >> ws, s);
                    viewFile (s + ".txt");
                }
            }
            else if (option == 3)
            {
                if (role.updateInfo ())
                {
                    string s, s1;
                    cout << "Enter username you want to find: ";
                    cout.flush ();
                    getline (cin >> ws, s);
                    if (checkuser (s))
                    {
                        cout << "Username does not exist" << endl;
                        goto admin_login;
                    }
                    s1 = get_proffesion (s + ".txt");
                    Person *pers;
                    if (s1 == "driver")
                        pers = new Driver;
                    else if (s1 == "police")
                        pers = new Police;
                    else if (s1 == "admin")
                        pers = new Admin;
                    else
                        pers = new Passenger;
                    pers->update_info (s + ".txt");
                }
            }
            else if (option == 4)
            {
                if (role.deleteInfo ())
                {
                    string s;
                    cout << "Enter username you want to find: ";
                    cout.flush ();
                    getline (cin >> ws, s);
                    if (checkuser (s))
                    {
                        cout << "Username does not exist" << endl;
                        goto admin_login;
                    }
                    s += ".txt";
                    if (remove (s.c_str ()) != 0)
                        perror ("Error deleting file");
                    else
                        puts ("File successfully deleted");
                    /*if( remove( s+".txt" ) != 0 )perror( "Error deleting file" );
                       else puts( "File successfully deleted" ); */
                }
            }
            else if (option == 5)
            {
                citymap.PrintMap ();

            }
            else if (option == 7)
            {
                citymap.TrafficCondition ();
            }
            else if (option == 6)
            {
                Route route;
                route.TakeSource ();
                route.TakeDestination ();
                route.PrintRoute ();

            }

            else if (option == 8)
            {
                goto restart;
            }
            goto admin_login;
        }
    }

    else if (option == 3)
    {
        cout << "1.Car\n2.Bus\n3.Truck" << endl;
        int option;
        cin >> option;
        Vehicle *vehicle;

        if (option == 1)
        {
            vehicle = new PrivateCar;
            vehicle->addEntry ();
            //cout<<car.getVehicleID();
            vehicle->vehicle_write_to_file (vehicle->getVehicleID ());
            //viewcarFile(car.getvehicleID());
            goto restart;

        }
        else if (option == 2)
        {
            vehicle = new Bus;
            vehicle->addEntry ();
            vehicle->vehicle_write_to_file (vehicle->getVehicleID ());
            goto restart;
        }
        else if (option == 3)
        {
            vehicle = new Truck;
            vehicle->addEntry ();
            vehicle->vehicle_write_to_file (vehicle->getVehicleID ());
            goto restart;
        }
        goto restart;
    }
    else if(option==4)
    {
        cout<<"Notify Emergency Stations\n1.Fire Station\n2.Ambulance"<<endl;
        cout<<"Enter your option: ";
        int choice;
        cin>>choice;
        try
        {
            if(choice==1)
            {
                string acci;
                FireService fire;
                acci="true";
                fire.checkAccident(acci);
                acci="false";
                fire.checkAccident(acci);
                //cout<<"Fire Station Number: "<<fire.StationNo()<<endl;
                goto restart;
            }
            else if(choice==2)
            {
                Ambulance amb;
                cout<<"The list of available ambulance and information: "<<endl<<endl;
                amb.ambu_list();
                goto restart;
            }
            else
            {
                throw(choice);
            }
        }
        catch(int choice)
        {
            cout<<choice<<" is Invalid Option!"<<endl;
        }

        cout <<
             "----------------------------------------------------------------------------"
             << endl;
        cout <<
             "----------------------------------------------------------------------------"
             << endl;
        goto restart;
    }
    else
        return 0;


}

void intro ()
{
    ifstream filepointer;
    string line;
    filepointer.open ("hehe.txt");

    getline (filepointer, line);
    while (!filepointer.eof ())
    {

        cout << line;
        cout << endl;
        getline (filepointer, line);
    }
}

void gettime()
{
time_t now = time(0);
char* dt = ctime(&now);

   cout<< dt << endl;
}

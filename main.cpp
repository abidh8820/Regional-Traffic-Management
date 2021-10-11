#include <bits/stdc++.h>

#include "person.h"
#include "vehicle.h"

using namespace std;

void register_vechile() {
    cout << "1.Car\n2.Bus\n3.Truck\n4.Ambulance" << endl;
    int option;
    cin >> option;
    if (option == 1) {
        PrivateCar car;
        car.addentry();
    }
}

int main() {
restart:
    cout << "1.Sign-Up\n2.Login\n3.Vehicle registration" << endl;
    int option;
    cin >> option;

    if (option == 1) {
        cout << "1.Sign as passenger\n2.Sign up as driver" << endl;
        int profession;
        cin >> profession;
        if (profession == 1) {
            Passenger passenger;
            passenger.set_info();
            cout << "Information has been entered successfully!" << endl;
        } else if (profession == 2) {
            Driver driver;
            driver.set_info();
            driver.set_driver_info();
            cout << "Information has been entered successfully!" << endl
                 << endl;
        }
        goto restart;
    }

    else if (option == 2) {
        cout << "Log In as:" << endl;
        cout << "1.Passenger\n2.Driver\n3.Administrator\n4.Police" << endl;
        string username;
        int option;
        cin >> option;

        cout << "Enter User Name :";
        cout.flush();
        cin >> username;
        if (!checkuser(username)) {
        retype_password_to_login:
            cout << "Enter Password : ";
            cout.flush();
            string password;
            cin >> password;
            if (checkpass(password, username)) {
                cout << "Login Successful!" << endl;

            } else {
                cout << "Login Failed" << endl;
                cout << "1.Try again?\n2.Exit" << endl;

                int opt;
                cin >> opt;
                if (opt == 1)
                    goto restart;
                else
                    return 0;
            }

        } else {
            cout << "User does not exists!" << endl;
            cout << "Login Failed" << endl;
            cout << "1.Return to menu?\n2.Exit" << endl;

            int opt;
            cin >> opt;
            if (opt == 1)
                goto retype_password_to_login;
            else
                return 0;
        }

        if (option == 1) {
        passenger_login:

            // check if hes a passenger, if not return
            cout << "1.View City Map" << endl;
            cout << "2.Find Path" << endl;
            cout << "3.Check Road status" << endl;
            cout << "4.View Personal Information" << endl;
            cout << "5.Log out" << endl;

            int option;
            cin >> option;

            if (option == 1) {
                // SFML VIEW
            } else if (option == 4) {
                // viewFile(username+".txt");
            } else if (option == 5) {
                goto restart;
            } else {
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



        else if (option == 2) {
        // check if the person is a driver
        driver_login:
            cout << "1.View City Map\n2.Find Path\n3.Check Personal "
                    "Information\n"
                    "4.Check Vehicle Information\n5.Logout"
                 << endl;
            // driver.viewFile(username);
            // class for giving vehicle info etc.
            int option;
            cin >> option;
            if (option == 1) {
                // SFML VIEW
            } else if (option == 2) {
                // find path
            } else if (option == 3) {
                // viewFile(username+".txt");
            } else if (option == 4) {
                // vehicle info
            } else if (option == 5) {
                goto restart;
            }
            goto driver_login;
        } 



        else if (option == 3) {
            cout << "1.Register new vehicle.\n2.Update User\n3.Delete User\n4.Add "
                    "User\n5.Add notice";
            int option;
            cin >> option;
            if(option==1) register_vechile();
            else if (option == 2) {
                // add any information in the user, append or change any column
            } else if (option == 3) {
                // delete any user
            } else if (option == 4) {
                // add all the police admin level information file
            } else {
                // make a file where the notice will be given for the police
            }
        } 


        else {
            cout << "1. Check your profile(as police)\n3.Check Vehicle  "
                    "Information\n4.Add fine"
                 << endl;
            int option;
            cin >> option;
            if (option == 1) {
                // view file
            } else if (option == 3) {
                // open a vehicle file and see if its registered /license ase
                // naki thik thak
            } else {
                // open a file, add fine to the driver
            }
        }
    }
}

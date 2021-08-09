#include <bits/stdc++.h>

#include "Person.h"
using namespace std;

inline bool checkuser(string username) {
    ifstream PersonFilePointer;
    PersonFilePointer.open(username.c_str());
    return PersonFilePointer.is_open();
}

inline bool checkpass(string password, string username) {
    string line;
    ifstream PersonFilePointer(username.c_str());
    int lineno = 0;
    password = "Password :" + password;
    while (getline(PersonFilePointer, line)) {
        lineno++;
        if (lineno == 3) {
            break;
        }
    }
    if (line == password) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cout << "1.Sign-Up\n2.Login" << endl;
    int option;
    cin >> option;

    if (option == 1) {
        cout << "1.Sign as passenger\n2.Sign up as driver\n" << endl;
        int profession;
        cin >> profession;
        if (profession == 1) {
            Passenger passenger;
            passenger.get_info();
            passenger.writeOnFile();
            // cout<<"Information has been entered successfully!"<<endl;
            // cout<<"View your file\n1.Yes/2.No"?<<endl;
            int view;
            cin >> view;
            if (view == 1) {
                passenger.viewFile(passenger.name);
            }
        } else {
            Driver driver;
            driver.get_info();
            driver.writeOnFile();
            driver.add_info("2021", "2025");
            // cout<<"Information has been entered successfully!"<<endl;
            // cout<<"View your file\n1.Yes/2.No"?<<endl;
            int view;
            cin >> view;
            if (view == 1) {
                driver.viewFile(driver.name);
            }
        }
    } 
    else {
        cout << "Log In as:" << endl;
        cout << "1.Passenger\n2.Driver\n3.Administrator\n4.Police" << endl;
        int option;
        cin >> option;
        cout << "Enter User Name :";
        cout.flush();
        string username;
        cin >> username;
        bool userexists = checkuser(username);
        if (userexists) {
            cout << "Enter Password : ";
            cout.flush();
            string password;
            cin >> password;
            bool passwordcorrect = checkpass(password, username);
            if (passwordcorrect) {
                cout << "Login Successful!" << endl;

            } else {
                cout << "Login Failed" << endl;
                cout << "1.Return to menu?\n2.Exit" << endl;
            }

        } else {
            cout << "User does not exists!" << endl;
            cout << "Login Failed" << endl;
            cout << "1.Return to menu?\n2.Exit" << endl;
        }

        if (option == 1) {
            // check if hes a passenger, if not return
            cout << "1.View City Map" << endl;
            cout << "2.Find Path" << endl;
            cout << "3.Check Road status" << endl;
            int option;
            cin >> option;
            if (option == 1) {
                // SFML VIEW
            } else {
                cout << "Enter Source" << endl;
                string source;
                cin >> source;
                cout << "Enter Destination" << endl;
                string destination;
                cin >> destination;
                // then make the pathfinding algorithm
            }
        } else if (option == 2) {
            // check if the person is a driver
            cout << "1.Check Information\n2.Check Vehicle Information\n3.See "
                    "city map\n4.Find path"
                 << endl;
            // driver.viewFile(username);
            // class for giving vehicle info etc.
        } else if (option == 3) {
            cout << "1.Check Road Status\n2.Update User\n3.Delete User\n4.Add "
                    "User\n5.Add notice";
            int option;
            cin >> option;
            if (option == 1) {
                // will view the SFML file and check status
            } else if (option == 2) {
                // add any information in the user, append or change any column
            } else if (option == 3) {
                // delete any user
            } else if (option == 4) {
                // add all the police admin level information file
            } else {
                // make a file where the notice will be given for the police
            }
        } else {
            cout << "1. Check your File\n2.Check Notice\n3.Check Vehicle "
                    "Information\n4.Add fine"
                 << endl;
            int option;
            cin >> option;
            if (option == 1) {
                // view file
            } else if (option == 2) {
                // make a file to give any notice, regarding road condition or
                // rules
            } else if (option == 3) {
                // open a vehicle file and see if its registered /license ase
                // naki thik thak
            } else {
                // open a file, add fine to the driver
            }
        }
    }
}

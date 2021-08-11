#include <bits/stdc++.h>

#include "Person.h"
using namespace std;
int main() {
    restart:
    cout << "1.Sign-Up\n2.Login" << endl;
    int option;
    cin >> option;

    if (option == 1) {
        cout << "1.Sign as passenger\n2.Sign up as driver" << endl;
        int profession;
        string userid;
        cin >> profession;
        if (profession == 1) {
            Passenger passenger;
            passenger.set_info();
            passenger.write_to_file(passenger.getuserID());
            cout<<"Information has been entered successfully!"<<endl;
            viewFile(passenger.getuserID());
            goto pasaanger_login;
        }
        else  if(profession == 2) {
            Driver driver;
            driver.set_info();
            driver.set_driver_info();
            driver.write_to_file(driver.getuserID());
            driver.driver_write_to_file(driver.getuserID());
            cout<<"Information has been entered successfully!"<<endl<<endl;
            viewFile(driver.getuserID());
            goto driver_login;

        }
    }

    else {
        cout << "Log In as:" << endl;
        cout << "1.Passenger\n2.Driver\n3.Administrator\n4.Police" << endl;
        int option;
        string username;
        cin >> option;

        if(option<=2){
            cout << "Enter User ID :";
            cout.flush();
            cin >> username;
            //bool userexists = checkuser(username);
            if (!checkuser(username)){
                retype_password_to_login:
                cout << "Enter Password : ";
                cout.flush();
                string password;
                cin >> password;
                //bool passwordcorrect = checkpass(password, username);
                if (checkpass(password,username)) {
                    cout << "Login Successful!" << endl<<endl;
                }
                else {
                    cout << "Login Failed" << endl;
                    cout << "1.Try again?\n2.Exit" << endl;

                    int opt;
                    cin>>opt;
                    if(opt==1)goto restart;
                    else return 0;
                }

            }
            else {
                cout << "User does not exists!" << endl;
                cout << "Login Failed" << endl;
                cout << "1.Return to menu?\n2.Exit" << endl;

                int opt;
                cin>>opt;
                if(opt==1)goto retype_password_to_login;
                else return 0;
            }
        }
        else if(option==3){}
        else if(option==4){}

        if (option == 1) {
            // check if hes a passenger, if not return
            pasaanger_login:
            cout << "1.View City Map" << endl;
            cout << "2.Find Path" << endl;
            cout << "3.Check Road status" << endl;
            cout << "4.View Personal Information" << endl;
            cout << "5.Log out" << endl;
            int option;
            cin >> option;
            if (option == 1) {
                // SFML VIEW
            }
            else if(option == 4) {
                viewFile(username+".txt");
            }
            else if(option == 5) {
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
            goto passanger_login;
        }
        else if (option == 2) {
            // check if the person is a driver
            driver_login:
            cout <<"1.View City Map\n2.Find Path\n3.Check Personal Information\n"
                   "4.Check Vehicle Information\n5Logout"<< endl;
            // driver.viewFile(username);
            // class for giving vehicle info etc.
            goto driver_login;
        }
        else if (option == 3) {
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
        }
        else {
            cout << "1. Check your File\n2.Check Notice\n3.Check Vehicle "
                    "Information\n4.Add fine"
                 << endl;
            int option;
            cin >> option;
            if (option == 1) {
                // view file
            }
            else if (option == 2) {
                // make a file to give any notice, regarding road condition or
                // rules
            }
            else if (option == 3) {
                // open a vehicle file and see if its registered /license ase
                // naki thik thak
            }
            else {
                // open a file, add fine to the driver
            }
        }
    }
}

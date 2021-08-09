#include <bits/stdc++.h>
#include "Person.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
mainmenu:
    cout << "1. Sign up." << endl;
    cout << "2. Login ." << endl;

    int id; cin >> id;

    if (id == 1) {  // sign up
        cout << "1.Passenger: " << endl;
        cout << "2.Driver: " << endl;
        int x;  cin >> x;

        if (x == 1) {  // passenger
            Passenger passenger;
            passenger.set_info();
            string filename = passenger.getusername();
            passenger.write_info(filename);
        }

        else { //Driver;
            Driver driver;
            driver.set_info(); // sets basic information
            driver.write_to_file(driver.getusername());
            driver.set_driver_info(); // sets additional driver's info
            driver.driver_write_to_file();
        }
    }

    else {  // Login
        cout << "Log In as:" << endl;
        cout << "1.Passenger\n2.Driver\n3.Administrator\n4.Police" << endl;
        int option;
        cin >> option;

        auto [possible, cur_user]  = login_possible();
        if(!possible) goto mainmenu;

        if(option==1) {
            // passenger
        }
        else if(option == 2) {
            // Driver
        }
        else if(option==3){
          //  Administrator
        }
        else {
            // police
        }
    }
}


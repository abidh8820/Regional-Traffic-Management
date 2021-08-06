#include <bits/stdc++.h>

#include "Passenger.h"
//#include "Driver.h"

using namespace std;

static int globalid;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //    police  0
    //    Admin   1
    //    Passenger 2
    //    Driver   3
    //
    cout << "1. Sign up." << endl;
    cout << "2. Login ." << endl;

    int id;
    cin >> id;

    if (id == 1) {  // sign up
        cout << "1.Passenger: " << endl;
        cout << "2.Driver: " << endl;
        int x;
        cin >> x;
        if (x == 1) {  // passenger
            Person passenger;
            passenger.get_info();
            string username = '2' + passenger.getusername();
            string password = passenger.getpass();
            string filename = username + ".txt";
        }

    }

    else {  // Login
        int x;
        cin >> x;

        if (x == 1) {  // user

        } else if (x == 2) {  // Police

        } else {  // Admin
        }
    }
}


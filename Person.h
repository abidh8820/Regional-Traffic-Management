#include "bits/stdc++.h"
using namespace std;

static int userID;

class Person {
    int user_id;
    string name;
    string email;
    string phone;
    string adress;
    string profession;
    string password;

   public:
    Person() {}

    int gen_user_id() { return ++userID; }

    string check_pass() { // takes password, denies if does not match
    abar:
        cout << "Insert password" << endl;
        string s1, s2;
        cin >> s1;
        cout << "Insert  the same password again" << endl;
        cin >> s2;
        if (s1 != s2) {
            cout<<"Doesn't match"<<endl;
            goto abar;
        }
        return s1;
    }

    void get_info() {  /// generic informationfo
        cout << "Enter Your Name: " << endl;
        cin >> name;
        cout << "Enter your email: " << endl;
        cin >> email;
        cout << "Enter your profession: " << endl;
        cin >> profession;
        cout << "Enter your adress: " << endl;
        cin >> adress;
        cout << "Enter your phone number: " << endl;
        cin >> phone;
        user_id = gen_user_id();
        password = check_pass();
    }
};

#include "bits/stdc++.h"
using namespace std;

static int l_id;

class Person {
   protected:
    string user_id;
    string name;
    string email;
    string phone;
    string adress;
    string profession;
    string password;

   public:
    Person() {}

    string check_pass() {  // takes password, denies if does not match
    abar:
        cout << "Insert password" << endl;
        string s1, s2;
        cin >> s1;
        cout << "Insert  the same password again" << endl;
        cin >> s2;
        if (s1 != s2) {
            cout << "Doesn't match" << endl;
            goto abar;
        }
        return s1;
    }
    string getusername() { return user_id; }
    string getpass() { return password; }

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
        cout << "Enter your NID: " << endl;
        cin >> user_id;
        password = check_pass();
    }

    //        string name;
    //    string email;
    //    string phone;
    //    string adress;
    //    string profession;
    //
    void write_to_file(string filename) {
        cout << "Writing in file" << endl;
        cout << filename << endl;
        fstream myfile;
        myfile.open(filename, std::ios::out);
        myfile << name + "\n";
        myfile << email + "\n";
        myfile << phone + "\n";
        myfile << adress + "\n";
        myfile << profession + "\n";
        myfile.close();
    }
};



class Passenger : public Person {
    //    string source, destination;

   public:
    void write_info(string filename) {  // file naming format : '2' + id.txt
        Person::write_to_file(filename);
        fstream myfile;
        myfile.open(filename, ios::out | ios::app);
    }
};

class Driver : public Person {
    int lincense_id;
    string date_of_registraion;
    string date_of_expiration;

   public:
    int get_id() { return ++l_id; }
    void add_info(string dor, string doe) {
        date_of_expiration = doe;
        date_of_registraion = dor;
        lincense_id = get_id();
    }
    void get_info_driver() {
        cout << "Date of Registration: " << date_of_registraion << endl;
        cout << "Date of Expiration: " << date_of_expiration << endl;
        cout << "License ID " << lincense_id << endl;
    }
};


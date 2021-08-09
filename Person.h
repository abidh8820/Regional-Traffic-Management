#include "bits/stdc++.h"
#include <fstream>
using namespace std;

static int l_id;

inline bool checkuser(string username) {  // checks if file "username" is taken
    ifstream PersonFilePointer;
    PersonFilePointer.open(username.c_str());
    return !PersonFilePointer.is_open();
}

pair<bool, string> login_possible(){
    while(true)   {
        cout<<"Enter your username: ";
        cout.flush();
        string s;
        cin >> s;
        bool valid = checkuser(s);
        if(!valid){
            cout<<"Ener your pass: ";
            cout.flush();

            string givenpass;
            cin >> givenpass;

            ifstream myfile;
            myfile.open(s);

            string pass;
            getline(myfile,pass);
            cout<<pass<<endl;

            if(pass==givenpass){
                cout<<"Login successful."<<endl;
                return make_pair(1,s);
            }
            cout<<"Password does not match"<<endl;
            cout<<"1.Try again.\n2.Exit"<<endl;
            int option;
            cin >> option;

            if(option) continue;
            return make_pair(0,"");
        }
        else{
            cout<<"Username not found."<<endl;
            cout<<"1.Try again.\n2.Exit"<<endl;
            int option;
            cin >> option;

            if(option) continue;
            return make_pair(0,"");
        }
    }
}

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

    string set_username() {
        while (true) {
            cout << "Enter username: " << endl;
            string s;
            cin >> s;
            if (checkuser(s)) return s;
            cout << "Usernamae already taken." << endl;
        }
    }


    string getusername(){
        return  user_id;
    }
    string getpass() { return password; }

    void set_info() {  /// generic informationfo
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
        user_id = set_username();
        password = check_pass();
    }

    void write_to_file(string filename) { // writes ll personal info
        cout << "Writing in file" << endl;
        cout << filename << endl;
        fstream myfile;
        myfile.open(filename, std::ios::out);
        myfile << password + "\n";
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

    void set_driver_info(){
        cout<<"Enter date of Registration: ";
        cout.flush();
        cin >> date_of_registraion;
        cout<<"Enter date of Expiration: ";
        cout.flush();
        cin >> date_of_expiration;
    }

    void driver_write_to_file() {   //writes  only dates to file
        fstream myfile;
        myfile.open(this->getusername(), ios::out | ios::app);
        myfile<<date_of_registraion+"\n";
        myfile<<date_of_expiration+"\n";
        myfile.close();
    }

    void get_info_driver() {
        cout << "Date of Registration: " << date_of_registraion << endl;
        cout << "Date of Expiration: " << date_of_expiration << endl;
        cout << "License ID " << lincense_id << endl;
    }
};


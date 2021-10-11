#include <fstream>
#include "bits/stdc++.h"
using namespace std;

static int l_id;

bool checkuser(string username) {  // checks if file "username" is taken
    ifstream PersonFilePointer;
    username += ".txt";
    PersonFilePointer.open(username);
    if (PersonFilePointer) {
        PersonFilePointer.close();
        return false;
    } 
    return true;
}

bool checkpass(string password, string username) {
    string line;
    ifstream PersonFilePointer;
    username += ".txt";
    PersonFilePointer.open(username);

    getline(PersonFilePointer, line);
    if (line == password)  return true;
    return false;
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

    string set_pass() {  // takes password, denies if does not match
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
            if (checkuser(s))
                return s;
            else
                cout << "Username already taken." << endl;
        }
    }

    string getuserID() {
        string filename;
        filename = user_id + ".txt";
        return filename;
    }
    string getpass() { return password; }

    void set_info() {  /// generic informationfo
        user_id = set_username();
        password = set_pass();
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
    }

    void write_to_file(string filename) {  // writes ll personal info
        // write *this to user_id.txt file
        auto x = *this;     

    }
    // friend void viewFile(string filename);
};

class Passenger : public Person {
    //    string source, destination;

   public:
    /*void write_info(string filename) {  // file naming format : '2' + id.txt
        Person::write_to_file(filename);
        fstream myfile;
        myfile.open(filename, ios::out | ios::app);
    }*/
};

class Driver : public Person {
   private:
    int lincense_id;
    string date_of_registraion;
    string date_of_expiration;

   public:
    void set_driver_info() {
        cout << "Enter date of Registration: ";
        cout.flush();
        cin >> date_of_registraion;
        cout << "Enter date of Expiration: ";
        cout.flush();
        cin >> date_of_expiration;
        l_id++;
        lincense_id = l_id;
        ;
    }

    void get_info_driver() {
        cout << "Date of Registration: " << date_of_registraion << endl;
        cout << "Date of Expiration: " << date_of_expiration << endl;
        cout << "License ID " << lincense_id << endl;
    }
};





class Police : public Person {
   private:
    string post;
    string placement;

   public:
    Police() {
        post = "";
        placement = "";
    }

    void getInfo() {
        cout << "Enter Post:";
        cout.flush();
        cin >> post;
        cout << "Enter Placement:";
        cout.flush();
        cin >> placement;
    }

    void updateInfo() {
        cout << "Is there any change in your post or placement? If yes,press 1 "
                "to continue.";
        int x;
        cout.flush();
        cin >> x;
        if (x == 1) {
            cout << "Enter Post:";
            cout.flush();
            cin >> post;
            cout << "Enter Placement:";
            cout.flush();
            cin >> placement;
        }
    }

    void showInfo() {
        cout << "Post: " << post << endl;
        cout << "Placement: " << placement << endl;
    }

    ~Police() {}
};

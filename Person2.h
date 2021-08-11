#include "bits/stdc++.h"
#include <fstream>
using namespace std;

static int l_id;

bool checkuser(string username) {  // checks if file "username" is taken
    ifstream PersonFilePointer;
    username+=".txt";
    PersonFilePointer.open(username);
    if(PersonFilePointer){
        PersonFilePointer.close();
        return false;
    }
    else return true;
}

bool checkpass(string password,string username) {
    string line;
    ifstream PersonFilePointer;
    username+=".txt";
    PersonFilePointer.open(username);

    getline(PersonFilePointer,line);
    if (line == password) {
        return true;
    }
    else {
        return false;
    }
}
void viewFile(string filename){
    int lineNO=1;
    string line;
    ifstream myfile;
    myfile.open(filename);
    while(getline(myfile,line)){
        if(lineNO==2)cout<<"Logged into "<<line<<endl;
        else if(lineNO>2)cout<<line<<endl;
        lineNO++;
    }
    cout<<endl;
}

/*pair<bool, string> login_possible(){
    while(true)   {
        cout<<"Enter your username: ";
        cout.flush();
        string s;
        cin >> s;
        //bool valid = checkuser(s);
        if(checkuser(s)){
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
}*/

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

    string set_username(){
        while (true) {
            cout << "Enter username: " << endl;
            string s;
            cin >> s;
            if (checkuser(s))return s;
            else cout <<"Username already taken."<< endl;
        }
    }


    string getuserID(){
        string filename;
        filename=user_id+".txt";
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

    void write_to_file(string filename) { // writes ll personal info
        cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;
        fstream myfile;
        myfile.open(filename, std::ios::out);
        myfile << password + "\n";
        myfile << user_id + "\n";
        myfile << name + "\n";
        myfile << email + "\n";
        myfile << phone + "\n";
        myfile << adress + "\n";
        myfile << profession + "\n";
        myfile.close();
    }
    //friend void viewFile(string filename);
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
    void set_driver_info(){
        cout<<"Enter date of Registration: ";
        cout.flush();
        cin >> date_of_registraion;
        cout<<"Enter date of Expiration: ";
        cout.flush();
        cin >> date_of_expiration;
        l_id++;
        lincense_id=l_id;;

    }

    void driver_write_to_file(string filename) {   //writes  only dates to file
        cout<<"blacksheep"<<endl;
        fstream myfile;
        myfile.open(filename, std::ios_base::app);
        myfile<<lincense_id<<endl;
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


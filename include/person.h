#include "bits/stdc++.h"
using namespace std;

static int l_id;
template<class user>
bool checkuser(user username) {  // checks if file "username" is taken
    ifstream PersonFilePointer;
    username+=".txt";
    PersonFilePointer.open(username);
    if(PersonFilePointer){
        PersonFilePointer.close();
        return false;
    }
    else return true;
}
template<class pass, class users>
bool checkpass(pass password,users username) {
    string line;
    ifstream PersonFilePointer;
    username+=".txt";
    PersonFilePointer.open(username);

    getline(PersonFilePointer,line);
    getline(PersonFilePointer,line);
    if (line == password) {
        return true;
    }
    else {
        return false;
    }
}
void viewFile(string filename){
    int lineNO=1,d=0;
    string line;
    ifstream myfile;
    myfile.open(filename);
    if(myfile){
        while(getline(myfile,line)){
            if(lineNO==2)cout<<"User details:"<<endl;
            else if(d==1 && lineNO>18 && line!=""){
                cout<<endl;
                cout<<"Details of vehicle id "<<line<<":"<<endl;
                string l;
                ifstream mfile;
                mfile.open(line+".txt");
                while(getline(mfile,l)){
                    cout<<l<<endl;
                }
                mfile.close();
            }
            else if(lineNO>2)cout<<line<<endl;
            if(lineNO==8 && line=="driver")d=1;
            lineNO++;
        }
        cout<<endl;
        myfile.close();
    }
    else{
        cout<<"Username does not exist"<<endl;
    }
}

string get_proffesion(string filename){
    int lineNO=1;
    string line;
    ifstream myfile;
    myfile.open(filename);
    while(getline(myfile,line)){
        if(lineNO==8){
            return line;
            break;
        }
        lineNO++;
    }
    myfile.close();
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
        cout << "Confirm password" << endl;
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
            if (checkuser<string>(s))return s;
            else cout <<"Username already taken.Enter another username"<< endl;
        }
    }


    string getuserID(){
        string filename;
        filename=user_id+".txt";
        return filename;
    }
    string getpass() { return password; }

    virtual void set_info() {  /// generic informationfo
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
    virtual void update_info(string username){
        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(username);
        while(getline(myfile,line)){
            if(lineNO==2)password=line;
            else if(lineNO==4)user_id=line;
            else if(lineNO==6)name=line;
            else if(lineNO==8)profession=line;
            else if(lineNO==10)email=line;
            else if(lineNO==12)phone=line;
            else if(lineNO==14)adress=line;
            lineNO++;
        }
        myfile.close();

        cout<<"Old name: "<<name<<endl;
        cout << "Enter new Name: " << endl;
        getline(cin >> ws,line);
        if(line!="same")name=line;

        cout<<"Old email: "<<email<<endl;
        cout << "Enter new email: " << endl;
        getline(cin >> ws,line);
        if(line!="same")email=line;

        cout<<"Old profession: "<<profession<<endl;
        cout << "Enter New profession: " << endl;
        getline(cin >> ws,line);
        if(line!="same")profession=line;

        cout<<"Old adress: "<<adress<<endl;
        cout << "Enter new adress: " << endl;
        getline(cin >> ws,line);
        if(line!="same")adress=line;

        cout<<"Old phone: "<<phone<<endl;
        cout << "Enter new phone number: " << endl;
        getline(cin >> ws,line);
        if(line!="same")phone=line;
    }

    virtual void write_to_file(string filename) { // writes ll personal info
        cout << "Writing in file...." << endl;
        cout <<"File name: "<< filename << endl;
        fstream myfile;
        myfile.open(filename, std::ios::out);
        myfile <<"password:\n";
        myfile << password + "\n";
        myfile <<"User ID:\n";
        myfile << user_id + "\n";
        myfile <<"Name:\n";
        myfile << name + "\n";
        myfile <<"Profession:\n";
        myfile << profession + "\n";
        myfile <<"email:\n";
        myfile << email + "\n";
        myfile <<"Phone No:\n";
        myfile << phone + "\n";
        myfile <<"Adress:\n";
        myfile << adress + "\n";
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
    void update_info(string username){
        Person::update_info(username);
        write_to_file(username);
    }
};

class Driver : public Person {
   private:
    //int lincense_id;
    string date_of_registraion;
    string date_of_expiration;
    string vehic[5];

   public:
    Driver(){
        date_of_registraion="";
        date_of_expiration="";
        vehic[0]="";
        vehic[1]="";
        vehic[2]="";
        vehic[3]="";
        vehic[4]="";
    }

    void set_info(){
        Person::set_info();
        cout<<"Enter date of Registration: ";
        cout.flush();
        cin >> date_of_registraion;
        cout<<"Enter date of Expiration: ";
        cout.flush();
        cin >> date_of_expiration;
    }

    void write_to_file(string filename) {   //writes  only dates to file

        Person::write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<"Date of Registraion:"<<endl;
        myfile<<date_of_registraion<<endl;
        myfile<<"Date of Expiration:"<<endl;
        myfile<<date_of_expiration<<endl;
        if(vehic[0]!="")myfile<<vehic[0]<<endl;
        if(vehic[1]!="")myfile<<vehic[1]<<endl;
        if(vehic[2]!="")myfile<<vehic[2]<<endl;
        if(vehic[3]!="")myfile<<vehic[3]<<endl;
        if(vehic[4]!="")myfile<<vehic[4]<<endl;
        myfile.close();
    }
    void update_info(string username){
        Person::update_info(username);

        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(username);
        while(getline(myfile,line)){
            if(lineNO==16)date_of_registraion=line;
            else if(lineNO==18)date_of_expiration=line;
            else if(lineNO>=19)vehic[lineNO-19]=line;
            lineNO++;
        }
        myfile.close();

        cout<<"Old date of Registration: "<<date_of_registraion<<endl;
        cout<<"Enter New date of Registration: ";
        cout.flush();
        cin >> line;
        if(line!="same")date_of_registraion=line;

        cout<<"Old date of Expiration: "<<date_of_expiration<<endl;
        cout<<"Enter New date of Expiration: ";
        cout.flush();
        cin >> line;
        if(line!="same")date_of_expiration=line;

        write_to_file(username);
    }

    //friend void VehicleDriver(string,string);
    void get_info_driver() {
        cout << "Date of Registration: " << date_of_registraion << endl;
        cout << "Date of Expiration: " << date_of_expiration << endl;
        //cout << "License ID " << lincense_id << endl;
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

    void set_info(){
        Person::set_info();
        cout << "Enter Post:";
        cout.flush();
        cin >> post;
        cout << "Enter Placement:";
        cout.flush();
        cin >> placement;
    }

    void write_to_file(string filename){
        Person::write_to_file(filename);
        fstream myfile;
        myfile.open(filename,std::ios_base::app);
        myfile<<"post: "<<endl;
        myfile<<post<<endl;
        myfile<<"placement:"<<endl;
        myfile<<placement<<endl;
        myfile.close();
    }

    void update_info(string username){
        Person::update_info(username);

        int lineNO=1;
        string line;
        ifstream myfile;
        myfile.open(username);
        while(getline(myfile,line)){
            if(lineNO==16)post=line;
            else if(lineNO==18)placement=line;
            lineNO++;
        }
        myfile.close();

        cout<<"Old post :"<<post<<endl;
        cout<<"Enter New post: ";
        cout.flush();
        cin >> line;
        if(line!="same")post=line;

        cout<<"Old placement :"<<placement<<endl;
        cout<<"Enter New placement: ";
        cout.flush();
        cin >> line;
        if(line!="same")placement=line;

        write_to_file(username);
    }

    void showInfo() {
        cout << "Post: " << post << endl;
        cout << "Placement: " << placement << endl;
    }
    ~Police() {}
};


class Admin : public Person{
   private:
    string AdminRole;
    string AdminRoleDescription;
    bool notice;
    bool message;
    string Notice;
    string Message;

   public:
    Admin() {
        AdminRole = " ";
        AdminRoleDescription = " ";
        notice = false;
        message = false;
        Notice = " ";
        Message = " ";
    }
    void set_info(){
        Person::set_info();
        cout << "Enter Admin Role: ";
        cout.flush();
        cin >> AdminRole;
        cout << "Enter Admin Role Description:";
        cout.flush();
        cin >> AdminRoleDescription;
    }
    void getMessage() {
        message = true;
        cout << "Enter message for Admin: ";
        cout.flush();
        //cin.get(Message);
    }
    void getNotice() {
        notice = true;
        cout << "Enter notice for Admin: ";
        cout.flush();
        getchar();
    }
    void displayInfo() {
        cout << "Admin Role: " << AdminRole << endl;
        cout << "Admin Role Description : " << AdminRoleDescription << endl;
        if (message) {
            cout << "Message for the Admin: " << endl;
            cout << Message << endl;
        }
        if (notice) {
            cout << "Notice for the Admin :" << endl;
            cout << Notice << endl;
        }
    }
    ~Admin() {}
};


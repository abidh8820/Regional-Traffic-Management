#include <bits/stdc++.h>
using namespace std;

class Admin {
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
    void getInfo() {
        cout << "Enter Admin ID:";
        cout.flush();
        cin >> AdminID;
        cout << "Enter Admin Role: ";
        cout.flush();
        cin >> AdminRole;
    }
    void getMessage() {
        message = true;
        cout << "Enter message for Admin: ";
        cout.flush();
        cin.get(Message);
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

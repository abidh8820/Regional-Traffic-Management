#include "Person.h"
#include <bits/stdc++.h>
using namespace std;

static int l_id;

class Driver : public Person{
    int lincense_id;
    string date_of_registraion;
    string date_of_expiration;

    public:
    int get_id(){
        return ++l_id;
    }
    void add_info(string dor, string doe){
        date_of_expiration = doe;
        date_of_registraion = dor;
        lincense_id = get_id();
    }
    void get_info_driver(){
        cout<<"Date of Registration: "<<date_of_registraion<<endl;
        cout<<"Date of Expiration: "<<date_of_expiration<<endl;
        cout<<"License ID "<<lincense_id<<endl;
    }
}

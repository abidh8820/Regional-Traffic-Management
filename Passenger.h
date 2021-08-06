#include <bits/stdc++.h>
#include <fstream>
#include "Person.h"

using namespace std;
class Passenger : public Person {
//    string source, destination;

   public:
    void write_info(string filename) {  // file naming format : '2' + id.txt
        Person::write_to_file(filename);
        fstream myfile;
        myfile.open(filename, ios::out | ios::app);

    }
};

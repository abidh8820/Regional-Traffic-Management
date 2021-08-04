#include "Person.h"
#include <bits/stdc++.h>

using namespace std;
static int p_id;

class Passenger : public Person {
    int passenger_id;
    string source , destination;
    public:
    int get_id(){
        return ++p_id;
    }
    
}

#include <bits/stdc++.h>

#include <fstream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream myfile;
    myfile.open("ayonlal");

    string s;
    getline(myfile,s);
    cout<<s<<endl;
}


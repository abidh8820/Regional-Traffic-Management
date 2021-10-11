#include<bits/stdc++.h>
using namespace std;
class File
{
private:
    fstream FilePointer;
    string Filename;
public:
    File(string Filename)
    {
        this->Filename=Filename;
        FilePointer.open(Filename);

        if(!FilePointer.is_open())
        {
          cout<<"Unable to open the File."<<endl;
        }
    }

    void GiveEntry(int ID)
    {
        string str=to_string(ID);
        Filename=str+".txt";
        FilePointer.open(Filename);
        cin>>"User ID :">>str;
        cin>>"Password :">>password;
        cin>>"Name :">>name;
        cin>>"Email :">>email;
        cin>>"Profession :">>profession;
        cin>>"Phone :">>phone;
        cin>>"Adress :">>adress;
        }
    void UpdateEntry()
    {

    }
   void DeleteEntry()
   {

   }
   void SearchEntry()
   {

   }
};

#include "bits/stdc++.h"
using namespace std;

class Role
{
private:
    bool AccessToViewPersonal;
    bool AccessToViewOthers;
    bool AccessToDelete;
    bool AccessToUpdate;

public:
    Role()
    {
        AccessToViewPersonal=false;
        AccessToUpdate=false;
        AccessToDelete=false;
        AccessToViewOthers=false;
    }
    void GivePermissions(string role)
    {
      if(role=="User")
      {
          AccessToViewPersonal=true;
      }
      else if(role=="police" || role=="Government Worker")
      {
          AccessToViewPersonal=true;
          AccessToViewOthers=true;
      }
      else if(role=="admin")
      {
          AccessToViewPersonal=true;
          AccessToViewOthers=true;
          AccessToDelete=true;
          AccessToUpdate=true;
      }
      else
      {
        cout<<"Unknown Role"<<endl;
      }

    }
    /*void CheckPermission()
    {
        if(!AccessToView)
        {
            cout<<"You don't have permission to view the database system."<<endl;
        }
        if(!AccessToQuery)
        {
            cout<<"You don't have permission to make query"<<endl;
        }
        if(!AccessToUpdate)
        {
            cout<<"You don't have permission to update any database entry"<<endl;
        }
        if(!AccessToDelete)
        {
            cout<<"You don't have permission to delete any query"<<endl;
        }

    }*/
    bool viewPersonal(){
        if(!AccessToViewPersonal)
        {
            cout<<"You don't have permission to view the database system."<<endl;
        }
        return AccessToViewPersonal;
    }
    bool viewOthers(){
        if(!AccessToViewOthers)
        {
            cout<<"You don't have permission to view Others int the database system."<<endl;
        }
        return AccessToViewOthers;
    }
    bool deleteInfo(){
        if(!AccessToDelete)
        {
            cout<<"You don't have permission to delete any query."<<endl;
        }
        return AccessToDelete;
    }
    bool updateInfo(){
        if(!AccessToUpdate)
        {
            cout<<"You don't have permission to update any database entry."<<endl;
        }
        return AccessToUpdate;
    }
    ~Role()
    {

    }

};

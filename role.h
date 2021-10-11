#include "bits/stdc++.h"
using namespace std;

class Permission
{
private:
    bool AccessToView;
    bool AccessToUpdate;
    bool AccessToDelete;
    bool AccessToQuery;

public:
    Role
    {
        AccessToView=false;
        AccessToUpdate=false;
        AccessToDelete=false;
        AccessToQuery=false;
    }
    void GivePermissions(string role)
    {
      if(role=="User")
      {
          AccessToView=true;
      }
      if(role=="Police" || role=="Government Worker")
      {
          AccessToQuery=true;
          AccessToView=true;
      }
      if(role=="Central Administrator")
      {
          AccessToView=true;
          AccessToQuery=true;
          AccessToDelete=true;
          AccessToUpdate=true;
      }
      else
      {
        cout<<"Unknown Role"<<endl;
      }

    }
    void CheckPermission()
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

    }
    ~Role()
    {

    }

};

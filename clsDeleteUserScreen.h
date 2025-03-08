#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsDeleteUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:
    static void ShowDeleteUserScreen() {
        _DrawScreenHeader("\t Delete User Screen");
        string UserName = "";
		cout << "\n Enter UserName ? ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\t UserName  Not Found, Choose another one ? ";

			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\n Are Sure You want to delete this User ? y/n ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (User.Delete())
			{
				cout << "\n User Deleted Successfuly :-) \n";
				_PrintUser(User);
			}
			else
			{
				cout << " \n Error User Was not Deleted !\n";
			}
		}
		else
		{
			cout << "\n\n Operation Canceled !";
		}


    }


};


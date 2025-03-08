#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}


public:
	static void ShowFindClientScreen() {
	
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\t Find Client Screan ");
		string AccountNumber = "";
		cout << "\nPlease,Enter Clint AccountNumber : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "\n AccountNumber is Not Found Chooce another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty())
		{
			cout << "\n Clinet Found :-) \n";
		}
		else
		{
			cout << "\n Clinet was Not Found :-) \n";

		}

		_PrintClient(Client1);
	}
};


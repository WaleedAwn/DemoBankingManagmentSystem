#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
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
	static  void ShowDeleteClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\t Delete Client Screan ");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Not Found, Choose another one ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n Are Sure You want to delete this Client ? y/n ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Delete())
			{
				cout << "\n Clients Deleted Successfuly :-) \n";
				_PrintClient(Client1);
				;
			}
			else
			{
				cout << " \n Error Clint Was not Deleted !\n";
			}
		}
		else
		{
			cout << "\n\n Operation Canceled !";
		}

	}


};


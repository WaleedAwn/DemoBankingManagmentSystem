#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
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
	static void ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter AccountBalance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatlNumber();
	}


public:
	static void ShowUpdateClientScrean() {

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("\t Update Client Screan ");
		string AccountNumber = "";
		cout << "\nPlease,Enter Clint AccountNumber : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "\n AccountNumber is Not Found Choce another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		cout << "\n\nUpdate Clint Info : ";
		cout << "\n________________________\n";
		_PrintClient(Client1);
		ReadClientInfo(Client1);
		clsBankClient::enSaveResults SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not Saved Becouse it's Empety ! ";
			break;
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\n Account Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;
		default:
			break;
		}

	}



};


#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsBankClient.h"
class clsWithdrawScreen:protected clsScreen
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
	static string _ReadAccountNumber() {
		cout << "\nPlease,Enter Clint AccountNumber : ";
		return clsInputValidate::ReadString();;
	}

public:
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("\t Withdraw Screen ");

		string AccountNumber;
		AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Client with [" << AccountNumber << "]  Not Found : ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\n Please Enter Withdraw Amount : ";
		Amount = clsInputValidate::ReadDblNumber();
		cout << "\n Are you Sure you want to Perform this Transaction ? y/n ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\n Amount Withdraw Successfully.\n";
				cout << "\n New Balance Is: " << Client1.AccountBalance;

			}
			else
			{
		     cout << "\n Cannot Withdraw,Insuffecient Balanc! \n";
              cout<<"\n Amount To Withdraw is : "<< Amount;
             cout << " \n Your Balance is : " << Client1.AccountBalance;;
			}
			
		}
		else
		{
			cout << "\n Transaction Was Cancelled . \n";
		}

	}

};


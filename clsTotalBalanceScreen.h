#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include "clsBankClient.h"
class clsTotalBalanceScreen:protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}



public:
	static void ShowTotalBalancesScreen()
	{

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\tBalances List Screen";
		string SubTitle="\t    ("+to_string(vClients.size())+ ") Client(s).";
		_DrawScreenHeader(Title, SubTitle);
	
		cout<<setw(25)<<left <<"" << "\n\t\t______________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(25) << left<<"" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";

		cout << setw(25) << left << "" << "\n\t\t______________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << setw(25) << left << "" << "\n\t\t______________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
	}

};


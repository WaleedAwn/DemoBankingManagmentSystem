#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

    static void _ShowResults(clsCurrency Currency) {
        if (!Currency.IsEmpty())
        {
            cout << "\n Currency  Found :-) !\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n Currency was not Found :-( !\n";
        }
      
    }


public:

	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("\tFind Currency Screen");
        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;
        cin >> Answer;
 
        if (Answer==1)
        {
            string CurrencyCode;
            cout << "\n Please Enter Cuurency Code ? ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(C1);
        }
        else
        {
            string Country;
            cout << "\n Please Enter Country Name  ? ";
            Country = clsInputValidate::ReadString();
            clsCurrency C2 = clsCurrency::FindByCountry(Country);
            _ShowResults(C2);
        }

       
	}


};


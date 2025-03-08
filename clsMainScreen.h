#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h";
#include "clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"

using namespace std;

class clsMainScreen:protected clsScreen
{

private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eShowLogInRegister = 8,eCurrncyExchange=9 , eExit = 10
    };
    
    static short _ReadMainMenueOption(short From,short To)
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? ["<<From <<" to "<<To<< "] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(From, To, "Enter Number between 1 to 10 ? ");
        return Choice;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScrean();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }
    static void _ShowLoginRegisterScreen() {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyExchangeMainScreen() {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
      //  clsLoginScreen::ShowLoginScreen();
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption) 
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();

            break;
        case enMainMenueOptions::eShowLogInRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();

            break;
        case enMainMenueOptions::eCurrncyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();
            break; 
        }

    }

public:

    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen","\t\t WA,2024");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]  Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2]  Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3]  Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4]  Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5]  Find Client.\n";
        cout << setw(37) << left << "" << "\t[6]  Transactions.\n";
        cout << setw(37) << left << "" << "\t[7]  Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8]  Show Login Register.\n";
        cout << setw(37) << left << "" << "\t[9]  Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption(1,10));
    }

};

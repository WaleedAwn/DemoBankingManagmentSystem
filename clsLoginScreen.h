#pragma once
#include <iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"

class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login( ) {
	
		short FaildLoginCount = 0;
		string UserName, Password;
		bool LoginFaild = false;
		do
		{
			
			if (LoginFaild )
			{
				FaildLoginCount++;
				cout << "\n Invalid UserName or Password !";	
				cout << "\n You Have " <<(3- FaildLoginCount) << " Trial(s) to Login! \n\n";				
			}
			if (FaildLoginCount==3)
			{
				cout << "\n\nYou Have Loked After 3 Faild trails\n\n";
				return false;
			}
			
			cout << "\nEnter Username ? ";
			cin >> UserName;
			cout << "Enter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
			
		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();

		
	}
public:
	static bool ShowLoginScreen( ) {
		
	
		system("cls");
		_DrawScreenHeader("\t Login Screen ");
		return _Login();
	
	}
};


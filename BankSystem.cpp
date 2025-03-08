#include <iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsLoginScreen.h"
using namespace std;

int main()
{
	// UserName =WA
	// Password = 111 // the Password is encrypted inside the file 
	// i Have used the [Caesar] Algorithm to encrypt the password by using the Key = 2

	// i also used the permission to control the access to the system  . in permission i used th Bitwise OR to combine the permissions
	// [-1] to allow all permissions

	while (true)
	{
		
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}
	
	return 0;
}

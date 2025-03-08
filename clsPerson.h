#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		this->_FirstName = FirstName;
		this->_LastName = LastName;
		this->_Email = Email;
		this->_Phone = Phone;
	}

	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstname() {
		return _FirstName;
	}
	__declspec(property(get=GetFirstname,put=SetFirstName))string FirstName;

	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastname() {
		return _LastName;
	}
	__declspec(property(get = GetLastname, put = SetLastName))string LastName;

	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	string FullName() {
		return _FirstName + " " + _LastName;
	}
};


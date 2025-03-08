#pragma once
#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
using namespace std;
string TransferLogFile = "TransferLog.txt";

class clsBankClient :public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkeForDelete = false;
	
	
	string _PrepareTransferLogRecord(float Amount, clsBankClient DestanaionClint, 
		string UserName,string Seperator = "#//#") {
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestanaionClint.AccountNumber() + Seperator;
		TransferLogRecord +=to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestanaionClint.AccountBalance )+ Seperator;
		TransferLogRecord += UserName ;


		return TransferLogRecord;
	}
	void _RegisterTransferLog(float Amount, clsBankClient DestanaionClint,
		string UserName) {

		string stDataLine = _PrepareTransferLogRecord(Amount, DestanaionClint,UserName);

		fstream MyFile;
		MyFile.open(TransferLogFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}


	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#") {
		vector<string>vDateCLints;
		vDateCLints = clsString::Split(Line, Seperator);
		//clsUtil::DecryptText(vDateCLints[5])

		return clsBankClient(enMode::UpdateMode, vDateCLints[0], vDateCLints[1], vDateCLints[2],
			vDateCLints[3], vDateCLints[4], clsUtil::DecryptText(vDateCLints[5]), stod(vDateCLints[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += clsUtil::EncryptText(Client.PinCode) + Seperator;
		//stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance) + Seperator;
		return stClientRecord;
	}
	
	static vector<clsBankClient>_LoadClientsDateFromFile() {
		vector<clsBankClient>vClientsDate;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsBankClient Clients = clsBankClient::_ConvertLinetoClientObject(Line);
				vClientsDate.push_back(Clients);
			}		
		}
		MyFile.close();
		return vClientsDate;

	}
	
	static void _SaveClientDateToFile(vector<clsBankClient>vClientsDate) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			string DateLine;
			for (clsBankClient&C: vClientsDate)
			{
				if (C.MarkeForDelete()==false)
				{
					DateLine = clsBankClient::_ConvertClientObjectToLine(C);
					MyFile << DateLine << endl;
				}
			
			}

		}
		MyFile.close();
	}
	
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _Update() {
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientsDateFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber()==AccountNumber())
			{
				C = *this; 
				break;
			}
		}
		_SaveClientDateToFile(_vClients);
	}
	void _AddNew() {
		_AddDateLineToFile(_ConvertClientObjectToLine(*this));
	}
	
	void _AddDateLineToFile(string stDataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	struct stTrnsferLogRecord;
	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#") {
		
		vector<string >vtranferData = clsString::Split(Line,Seperator);
		stTrnsferLogRecord stTransfer;
		stTransfer.DateTime = vtranferData[0];
		stTransfer.SourceAccountNumber = vtranferData[1];
		stTransfer.DestinationAccountNumber = vtranferData[2];
		stTransfer.Amount = stod(vtranferData[3]);
		stTransfer.srcBalanceAfter = stod(vtranferData[4]);
		stTransfer.destBalanceAfter = stod(vtranferData[5]);
		stTransfer.UserName = vtranferData[6];

		return stTransfer;
	}


public:

	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone,
		string AccountNumber,string PinCode,float AccountBalance
	):clsPerson( FirstName,  LastName,  Email,  Phone)
	{
		this->_Mode = Mode;
		this->_AccountNumber = AccountNumber;
		this->_PinCode = PinCode;
		this->_AccountBalance = AccountBalance;
	}

	void Print() {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << AccountNumber();
		cout << "\nPassword    : " << PinCode;
		cout << "\nBalance     : " << AccountBalance;
		cout << "\n___________________\n";
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkeForDelete() {
		return _MarkeForDelete;
    }
	
	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;


	static clsBankClient Find(string AccountNumber) {
		vector<clsBankClient>vDateClints;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mod

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsBankClient Clint = _ConvertLinetoClientObject(Line, "#//#");
				if (Clint.AccountNumber()==AccountNumber)
				{
					MyFile.close();
					return Clint;
				}
				vDateClints.push_back(Clint);
			}
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string PinCode) {
		vector<clsBankClient>vDateClints;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mod

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Clint = _ConvertLinetoClientObject(Line, "#//#");
				if (Clint.AccountNumber() == AccountNumber && Clint.PinCode==PinCode)
				{
					MyFile.close();
					return Clint;
				}
				vDateClints.push_back(Clint);
			}

		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Clients = clsBankClient::Find(AccountNumber);
		return !(Clients.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResults{svFaildEmptyObject=0,svSucceeded=1, svFaildAccountNumberExists = 2};

	enSaveResults Save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return clsBankClient::enSaveResults::svFaildEmptyObject;
			break;
		case clsBankClient::UpdateMode:
			_Update();
			return clsBankClient::enSaveResults::svSucceeded;
			break;
		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		default:
			break;
		}

	}

	bool Delete() {
		vector <clsBankClient>vClientsData;
		vClientsData = _LoadClientsDateFromFile();
		for (clsBankClient &C: vClientsData)
		{
			if (C.AccountNumber()==_AccountNumber)
			{
				C._MarkeForDelete = true;
				break;
			}
		}
		_SaveClientDateToFile(vClientsData);

		*this = _GetEmptyClientObject();
		return true;

	}

	static vector<clsBankClient> GetClientsList() {
		return _LoadClientsDateFromFile();
	}

	static double GetTotalBalances() {
		vector<clsBankClient>vClints = GetClientsList();
		double TotalBalance = 0;
		for (clsBankClient C : vClints) {
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if (Amount>_AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		
	}
	
	bool Transfer(double Amount, clsBankClient& DestinationClient,string UserName)
	{
		if (Amount>AccountBalance)
		{
			return false;
		}
	
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
    }

	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;
	};

	static vector< stTrnsferLogRecord> GetTransfersLogList() {
		vector< stTrnsferLogRecord> vTransferLogDate;

		fstream MyFile;
		MyFile.open(TransferLogFile, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				
				vTransferLogDate.push_back(_ConvertTransferLogLineToRecord(Line));
			}
		}
		MyFile.close();
		return vTransferLogDate;
	}




};


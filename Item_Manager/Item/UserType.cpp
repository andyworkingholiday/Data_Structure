#include "pch.h"
#include "UserType.h"


// Set user ID from keyboard
void UserType::SetIDFromKB()
{
	while (m_sID.empty())
	{
		cout << "\tID\t : ";
		getline(cin, m_sID);
		if (!m_sID.empty())
			break;

		cout << "\tYou didn't enter ID!! Please enter ID!!!" << endl;
	}
}


// Set user password from keyboard.
void UserType::SetPWFromKB()
{
	while (m_sPW.empty())
	{
		cout << "\tPW\t : ";
		getline(cin, m_sPW);
		if (!m_sPW.empty())
			break;

		cout << "\tYou didn't enter password!! Please enter password!!!" << endl;
	}
}


// Set user name from keyboard
void UserType::SetNameFromKB()
{
	while (m_sName.empty())
	{
		cout << "\tName\t : ";
		getline(cin, m_sName);
		if (!m_sName.empty())
			break;

		cout << "\tYou didn't enter name!! Please enter name!!!" << endl;
	}
}


// Set user record from keyboard.
void UserType::SetRecordFromKB()
{

	cin.ignore();
	SetIDFromKB();
	SetPWFromKB();
	SetNameFromKB();
}


// Read a record from file.
int UserType::ReadDataFromFile(ifstream& fin)
{
	string dummy;
	getline(fin, m_sID, '\n');
	getline(fin, m_sPW, '\n');
	getline(fin, m_sName, '\n');
	getline(fin, dummy, '\n');

	return 1;
};


// Write a record into file.
int UserType::WriteDataToFile(ofstream& fout)
{
	fout << m_sID << '\n';
	fout << m_sPW << '\n';
	fout << m_sName << '\n' << '\n';

	return 1;
}
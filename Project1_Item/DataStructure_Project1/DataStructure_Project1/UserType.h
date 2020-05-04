#ifndef _USER_TYPE_H
#define _USER_TYPE_H

class UserType
{
protected:
	string m_sID;		///< user's ID
	string m_sPW;		///< user's password
	string m_sName;		///< user's name

public:
	/**
	*	default constructor.
	*/
	UserType()
	{
		m_sID = "";
		m_sPW = "";
		m_sName = "";
	};

	/**
	*	parameterized constructor.
	*/
	UserType(string inID, string inPW, string inName)
	{
		m_sID = inID;
		m_sPW = inPW;
		m_sName = inName;
	}

	/**
	*	destructor.
	*/
	~UserType() {};

	/**
	*	@brief	Get user ID.
	*	@pre	user ID is set.
	*	@post	none.
	*	@return	user ID.
	*/
	string GetID() { return m_sID; }

	/**
	*	@brief	Get user password.
	*	@pre	user password is set.
	*	@post	none.
	*	@return	user password.
	*/
	string GetPW() { return m_sPW; }

	/**
	*	@brief	Get user name.
	*	@pre	user name is set.
	*	@post	none.
	*	@return	user name.
	*/
	string GetName() { return m_sName; }

	/**
	*	@brief	Set user ID.
	*	@pre	none.
	*	@post	user ID is set.
	*	@param	inID		user ID.
	*/
	void SetID(string inID) { m_sID = inID; }

	/**
	*	@brief	Set user password.
	*	@pre	none.
	*	@post	user password is set.
	*	@param	inPW		user password.
	*/
	void SetPW(string inPW) { m_sPW = inPW; }

	/**
	*	@brief	Set user name.
	*	@pre	none.
	*	@post	user name is set.
	*	@param	inName		user name.
	*/
	void SetName(string inName) { m_sName = inName; }

	/**
	*	@brief	Set user record.
	*	@pre	none.
	*	@post	user record is set.
	*	@param	inID		user ID.
	*	@param	inPW		user password.
	*	@param	inName		user name.
	*/
	void SetRecord(string inID, string inPW, string inName)
	{
		SetID(inID);
		SetPW(inPW);
		SetName(inName);
	}

	/**
	*	@brief	Display user ID on screen.
	*	@pre	user ID is set.
	*	@post	user ID is on screen.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID\t : " << m_sID << endl;
	}

	/**
	*	@brief	Display user password on screen.
	*	@pre	user password is set.
	*	@post	user password is on screen.
	*/
	void DisplayPWOnScreen()
	{
		cout << "\tPW\t : " << m_sPW << endl;
	}

	/**
	*	@brief	Display user name on screen.
	*	@pre	user name is set.
	*	@post	user name is on screen.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName\t : " << m_sName << endl;
	}

	/**
	*	@brief	Display an user record on screen.
	*	@pre	user record is set.
	*	@post	user record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		cout << endl;
		DisplayIDOnScreen();
		DisplayPWOnScreen();
		DisplayNameOnScreen();
	}

	/**
	*	@brief	Set user ID from keyboard.
	*	@pre	none.
	*	@post	user ID is set.
	*/
	void SetIDFromKB();

	/**
	*	@brief	Set user passwoed from keyboard.
	*	@pre	none.
	*	@post	user password is set.
	*/
	void SetPWFromKB();

	/**
	*	@brief	Set user name from keyboard.
	*	@pre	none.
	*	@post	user name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set user record from keyboard.
	*	@pre	none.
	*	@post	user record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);


	// 연산자 오버로딩
	bool operator==(const UserType& data)
	{
		return (this->m_sID == data.m_sID);
	}
	bool operator!=(const UserType& data)
	{
		return !(*this == data);
	}
	bool operator<(const UserType& data)
	{
		if (this->m_sID < data.m_sID)
			return true;
		else
			return false;
	}
	bool operator<=(const UserType& data)
	{
		return (*this == data || *this < data);
	}
	bool operator>(const UserType& data)
	{
		return !(*this <= data);
	}
	bool operator>=(const UserType& data)
	{
		return !(*this < data);
	}
};


#endif // _USER_TYPE_H
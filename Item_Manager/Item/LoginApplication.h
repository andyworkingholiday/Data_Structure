#ifndef _LOGIN_APPLICATION_H
#define _LOGIN_APPLICATION_H

class LoginApplication {

public:
	/**
	*	default constructor.
	*/
	LoginApplication() { m_LoginCommand = 0; }

	/**
	*	destructor.
	*/
	~LoginApplication() { SaveDB(); }

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	main command.
	*/
	int GetMainCommand();

	/**
	*	@brief	sign in
	*/
	void SignIn();

	/**
	*	@brief	sign up
	*/
	void SignUp();

	/**
	*	@brief	find user ID
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int FindID();

	/**
	*	@brief	find user password
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int FindPW();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* fileName);

	/*
	*	@brief	User's mail information load from file
	**/
	int LoadDB();

	/*
	*	@brief	User's mail information save into file
	**/
	int SaveDB();

private:
	ifstream m_InFile;				///< input file descriptor.
	ofstream m_OutFile;				///< output file descriptor.
	SingleSortedLinkedList<UserType> UserList;	///< user list.
	int m_LoginCommand;				///< main command number.
};


#endif	// _LOGIN_APPLICATION_H

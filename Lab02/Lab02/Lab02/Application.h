#ifndef _APPLICATION_H
#define _APPLICATION_H
#define FILENAMESIZE 1024

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "SortedList.h"

class Application {
public:

	/**
	*	default constructor.
	*/
	Application() {
		m_Command = 0;
	}

	/**
	*	destructor.
	*/
	~Application() {}

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
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();


	/**
	*	@brief	Retrieve item using binary search from keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with same primary key
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void RetrieveItem();

/**
	*	@brief	Delete item using binary search from keyboard input
	*	@pre	list should be initalized
	*	@post	Delete the item with same primary key
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void DeleteItem();

/**
	*	@brief	Replace item using binary search from keyboard input
	*	@pre	list should be initalized
	*	@post	find the item in the list with same primary key and replace it with input parameter
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void ReplaceItem();

/**
	*	@brief	Search item by member usage from the keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with the function SearchListByMemberUsage
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetreiveRecordByMemberUsage();

/**
	*	@brief	Search item by member name from the keyboard input
	*	@pre	list should be initalized
	*	@post	find the item with the function SearchListByMemberName
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetreiveRecordByMemberName();

/**
	*	@brief	Search item by member name
	*	@pre	list should be initalized
	*	@post	find the item in the list include name from param data
	*	@param	inData	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchListByMemberName(ItemType &inData);

/**
	*	@brief	Search item by member usage
	*	@pre	list should be initalized
	*	@post	find the item in the list with same usage from param data
	*	@param	inData	input data
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchListByMemberUsage(ItemType &inData);

private:
	ifstream m_InFile;  // input file
	ofstream m_OutFile; // output file
	SortedListType m_List; // sorted list
	int m_Command; // input command from keyboard
};

#endif	// _APPLICATION_H
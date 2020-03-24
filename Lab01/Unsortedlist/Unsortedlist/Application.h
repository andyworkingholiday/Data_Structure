#ifndef _APPLICATION_H
#define _APPLICATION_H
#define FILENAMESIZE 1024

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

class Application {
public:
	void Run();
	int GetCommand();
	int AddItem();
	void DisplayAllItem();
	int OpenInFile(char *fileName);
	int OpenOutFile(char *fileName);
	int ReadDataFromFile();
	int WriteDataToFile();
	void RetrieveStudent();
	void DeleteStudent();
	void Replace();


private:
	ifstream m_InFile;
	ofstream m_OutFile;
	ArrayList m_List;
	int m_Command;
};

#endif	// _APPLICATION_H
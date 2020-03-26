#include "Application.h"

void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command) {
		case 1:		// read a record and add to list.
			AddMusic();
			break;
		case 2:		// Delete Data from the list.
			DeleteMusic();
			break;
		case 3:		// Replace Data from the list.
			ReplaceMusic();
			break;	
		case 4:		// Find Data from the list.
			RetrieveMusic();
			break;
		case 5:		// display all the records in list on screen.
			DisplayAllMusic();
			break;
		case 6:    // make empty list.
			m_List.MakeEmpty();
			break;
		case 7:    // load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// // save list data into a file
			WriteDataToFile();
			break;			
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music " << endl;
	cout << "\t   3 : Replace Music " << endl;
	cout << "\t   4 : Find Music " << endl;
	cout << "\t   5 : Print all Music on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddMusic() {
	if (m_List.IsFull()) return 0;
	else {
		ItemType Music;
		Music.SetRecordFromKB();
		m_List.Add(Music);
	}

	DisplayAllMusic();
	return 1;
}

void Application::DisplayAllMusic() {
	if (m_List.IsEmpty()) return;

	printf("\n\tCurrent list\n");
	ItemType Music;
	m_List.ResetList();

	while (1) {
		if (m_List.GetNextItem(Music) >= 0)
			Music.DisplayRecordOnScreen();
		else break;
	}
}

int Application::OpenInFile(char *fileName) {
	m_InFile.open(fileName);
	if (m_InFile) return 1;
	else return 0;
}


int Application::OpenOutFile(char *fileName) {
	m_OutFile.open(fileName);
	if (m_OutFile) return 1;
	else return 0;
}

int Application::ReadDataFromFile() {
	ItemType Music;
	char filename[FILENAMESIZE];
	printf("\n\tEnter Input file Name : ");
	cin >> filename;

	if (!OpenInFile(filename)) return 0;

	while (!m_InFile.eof()) {
		Music.ReadDataFromFile(m_InFile);
		if (m_InFile.eof()) break;
		m_List.Add(Music);
	}

	m_InFile.close();
	DisplayAllMusic();

	return 1;
}

int Application::WriteDataToFile() {
	ItemType Music;
	char filename[FILENAMESIZE];
	printf("\n\tEnter Output file Name : ");
	cin >> filename;

	if (!OpenOutFile(filename)) return 0;
	m_List.ResetList();

	while (1) {
		if (m_List.GetNextItem(Music) >= 0)
			Music.WriteDataToFile(m_OutFile);
		else break;
	}

	return 1;
}

void Application::RetrieveMusic() {
	ItemType Music;

	printf("\n\tEnter the SongNumber you want to retrieve.\n");
	Music.SetSongNumberFromKB();

	if (m_List.Get(Music) >= 0) {
		printf("\n\tThe Music's data : \n");
		Music.DisplayRecordOnScreen();
	}
	else printf("\n\tThere is no Music you want to find.\n");
}

void Application::DeleteMusic() {
	ItemType Music;

	printf("\n\tEnter the SongNumber you want to delete.\n");
	Music.SetSongNumberFromKB();

	if (m_List.Delete(Music) == 1) {
		printf("\n\tDelete Success.");
		DisplayAllMusic();
	}

	else printf("\n\tThere is no Music you want to delete.\n");
}

void Application::ReplaceMusic() {
	ItemType Music;

	printf("\n\tEnter the new Music's data you want to replace.\n");
	Music.SetRecordFromKB();

	if (m_List.Replace(Music) == 1) {
		printf("\n\tReplace Success\n.");
		DisplayAllMusic();
	}

	else printf("\n\tThere is no Music's SongNumber you want to replace.\n");
}
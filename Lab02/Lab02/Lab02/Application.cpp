#include "Application.h"

void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command) {
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 4:
			RetrieveItem();
			break;
		case 5:
			RetreiveRecordByMemberUsage();
			break;
		case 6:
			RetreiveRecordByMemberName();
			break;
		case 7:
			DeleteItem();
			break;
		case 8:
			ReplaceItem();
			break;
		case 9:
			ReadDataFromFile();
			break;
		case 10:
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
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Find item " << endl;
	cout << "\t   5 : Find item by usage " << endl;
	cout << "\t   6 : Find item by name " << endl;
	cout << "\t   7 : Delete item " << endl;
	cout << "\t   8 : Replace item " << endl;
	cout << "\t   9 : Get from file" << endl;
	cout << "\t   10 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddItem() {
	if (m_List.IsFull()) {
		printf("\tList is Full\n");
		return 0;
	}

	else {
		ItemType t;
		t.SetRecordFromKB();
		m_List.Add(t);
	}

	DisplayAllItem();
	return 1;
}

void Application::DisplayAllItem() {
	if (m_List.IsEmpty()) {
		printf("\tList is Empty\n");
		return;
	}

	printf("\n\tCurrent list\n");
	ItemType t;
	m_List.ResetList();
	int len = m_List.GetLength();

	while (len--) {
		if (m_List.GetNextItem(t) >= 0)
			t.DisplayRecordOnScreen();
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
	ItemType t;
	char filename[FILENAMESIZE];
	printf("\n\tEnter Input file Name : ");
	cin >> filename;

	if (!OpenInFile(filename)) return 0;

	while (!m_InFile.eof()) {
		t.ReadDataFromFile(m_InFile);
		if (m_InFile.eof()) break;
		m_List.Add(t);
	}

	m_InFile.close();
	DisplayAllItem();

	return 1;
}

int Application::WriteDataToFile() {
	ItemType t;
	char filename[FILENAMESIZE];
	printf("\n\tEnter Output file Name : ");
	cin >> filename;

	if (!OpenOutFile(filename)) return 0;
	m_List.ResetList();
	int len = m_List.GetLength();

	while (len--) {
		if (m_List.GetNextItem(t) >= 0)
			t.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();
	return 1;
}

void Application::RetrieveItem() {
	ItemType t;

	printf("\n\tEnter the KeyNumber you want to retrieve.\n");
	t.SetKeyNumberFromKB();

	if (m_List.RetrieveByBS(t)!= -1) {
		printf("\n\tThe Item's data : \n");
		t.DisplayRecordOnScreen();
	}
	else printf("\n\tThere is no Item you want to find.\n");
}

void Application::DeleteItem() {
	ItemType t;

	printf("\n\tEnter the KeyNumber you want to delete.\n");
	t.SetKeyNumberFromKB();

	if (m_List.Delete(t)) {
		printf("\n\tDelete Success.\n");
		DisplayAllItem();
	}

	else printf("\n\tThere is no student you want to delete.\n");
}

void Application::ReplaceItem() {
	ItemType t;

	printf("\n\tEnter the KeyNumber you want to replace.\n");
	t.SetKeyNumberFromKB();

	int index = m_List.RetrieveByBS(t);
	if (index != -1) {
		cout << "\tEnter the new data.\n" << endl;
		t.SetUsageFromKB();
		t.SetPdayFromKB();
		t.SetRdayFromKB();
		t.SetPlaceFromKB();
		t.SetNameFromKB();
		t.SetNumFromKB();
		m_List.Replace(t);
		cout << "\n\tReplace Success.\n" << endl;
	}

	else printf("\n\tThere is no Item you want to replace.\n");
}

int Application::RetreiveRecordByMemberUsage() {
	printf("\n\tEnter the Usage you want to find\n");
	ItemType data;
	data.SetUsageFromKB();
	if (SearchListByMemberUsage(data)) return 1;
	return 0;
}

int Application::SearchListByMemberUsage(ItemType &inData) {
	ItemType CurData;
	m_List.ResetList();
	int len = m_List.GetLength();
	bool found = false;
	while (len--) {
		m_List.GetNextItem(CurData);
		if (CurData.GetUsage()==inData.GetUsage()) {
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no usage you want to search");
	return 0;
}

int Application::RetreiveRecordByMemberName() {
	printf("\n\tEnter the name you want to find\n");
	ItemType data;
	data.SetNameFromKB();
	if (SearchListByMemberName(data)) return 1;
	return 0;
}

int Application::SearchListByMemberName(ItemType &inData) {
	ItemType CurData;
	m_List.ResetList();
	int len = m_List.GetLength();
	bool found = false;
	while (len--) {
		m_List.GetNextItem(CurData);
		if (CurData.GetName().find(inData.GetName()) != -1) {
			CurData.DisplayRecordOnScreen();
			found = true;
		}
	}
	if (found) return 1;
	printf("\n\tList has no name you want to search");
	return 0;
}
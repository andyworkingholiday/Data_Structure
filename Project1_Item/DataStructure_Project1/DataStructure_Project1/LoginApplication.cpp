#include "pch.h"
#include "LoginApplication.h"


// Program driver.
void LoginApplication::Run() {
	LoadDB();

	while (1) {
		system("cls");
		m_LoginCommand = GetMainCommand();

		switch (m_LoginCommand){
		case 1:		// Sign in.
			SignIn();
			break;
		case 2:		// Sign up.
			SignUp();
			break;
		case 3:		// Find ID.
			FindID();
			break;
		case 4:		// Find password.
			FindPW();
			break;
		case 0:		// Quit
			return;
		default:
			cout << "\tIllegal selection...\n";
			pause;
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int LoginApplication::GetMainCommand(){
	int command;
	cout << endl << endl << endl;
	cout << "\t---ID----Command-------" << endl;
	cout << "\t   1 : Sign In" << endl;
	cout << "\t   2 : Sign Up" << endl;
	cout << "\t   3 : Find ID" << endl;
	cout << "\t   4 : Find PW" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << "\t-----------------------" << endl;

	cout << endl << "\tChoose a Command" << endl << "\t>> ";
	cin >> command;
	cout << endl;

	return command;
}


// Sign in
void LoginApplication::SignIn(){
	UserType data;
	UserType tmp;
	int idChk, pwChk;
	idChk = pwChk = 0;

	cin.ignore();

	while (!UserList.Get(data)){
		data.SetID("");

		system("cls");
		cout << endl << endl;
		cout << "\t[[ Sign In ]]" << endl;

		if (idChk != 0){ // ���̵� �Է��� Ʋ�� ��
			cout << "\tThat ID does not exist" << endl;
			if (idChk > 3){ // ���̵� 3�� �̻� Ʋ���� ��
				char cmd;
				char cmd2;
				cout << "\tForgot your ID? (Y/N)  "; // y ���� �� ���� ã��� �̵�
				cin >> cmd;
				switch (cmd) {
				case 'Y': 
					FindID();
					return;
				case 'y':
					FindID();
					return;
				case 'N':
					cout << "\tDon't you have your account? (Y/N)  "; // y ���� �� ���� ������ �̵�
					cin >> cmd2;
					switch (cmd2) {
					case 'Y':
						SignUp();
						return;
					case 'y':
						SignUp();
						return;
					case 'N':
						cin.ignore();
						break;
					case 'n':
						cin.ignore();
						break;
					default:
						cout << "\tIllegal selection...\n";
						pause;
						return;
					}
					break;
				case 'n':
					cout << "\tDon't you have your account? (Y/N)  ";
					cin >> cmd2;
					switch (cmd2){
					case 'Y':
						SignUp();
						return;
					case 'y':
						SignUp();
						return;
					case 'N':
						cin.ignore();
						break;
					case 'n':
						cin.ignore();
						break;
					default:
						cout << "\tIllegal selection...\n";
						pause;
						return;
					}
					break;
				default:
					cout << "\tIllegal selection...\n";
					pause;
					return;
				}
			}
		}

		data.SetIDFromKB();
		idChk++;
	}
	while (tmp.GetPW() != data.GetPW())
	{
		tmp.SetPW("");

		system("cls");
		cout << endl << endl;
		cout << "\t[[ Sign In ]]" << endl;
		data.DisplayIDOnScreen();

		if (pwChk != 0)
		{
			cout << "\tWrong PassWord!! Please reenter your password." << endl;
			if (pwChk > 3)
			{
				char cmd;
				char cmd2;
				cout << "\tForgot your password? (Y/N)  ";
				cin >> cmd;
				switch (cmd)
				{
				case 'Y':
					FindPW();
					return;
				case 'y':
					FindPW();
					return;
				case 'N':
					cout << "\tDo you want to go back main screen? (Y/N)  ";
					cin >> cmd2;
					switch (cmd2)
					{
					case 'Y':
						return;
					case 'y':
						return;
					case 'N':
						cin.ignore();
						break;
					case 'n':
						cin.ignore();
						break;
					default:
						cout << "\tIllegal selection...\n";
						pause;
						return;
					}
					break;
				case 'n':
					cout << "\tDo you want to go back main screen? (Y/N)  ";
					cin >> cmd2;
					switch (cmd2)
					{
					case 'Y':
						return;
					case 'y':
						return;
					case 'N':
						cin.ignore();
						break;
					case 'n':
						cin.ignore();
						break;
					default:
						cout << "\tIllegal selection...\n";
						pause;
						return;
					}
					break;
				default:
					cout << "\tIllegal selection...\n";
					pause;
					return;
				}
			}
		}

		tmp.SetPWFromKB();
		pwChk++;
	}

	// user's mail app �۵�
	MainApplication UserApp(data);
	UserApp.Run();

	return;
}


// Sign up
void LoginApplication::SignUp()
{
	UserType data;
	UserType tmp;
	int pwChkNum = 0;

	cin.ignore();

	// ID �Է� �ޱ�
	while (data.GetID().size() < 4 && !UserList.Get(data))
	{
		data.SetID("");
		system("cls");
		cout << endl << endl;
		cout << "\t[[ Sign Up ]]" << endl;
		cout << "\tPlease enter ID at least 4 characters." << endl;
		cout << "\tID must be used alphabet or number." << endl;
		data.SetIDFromKB();

		// ȸ�� ����Ʈ�� �����ϸ�
		if (UserList.Get(data))
		{
			cout << "\tAlready exist that ID!" << endl;
			data.SetID("");
			pause;
		}
		else
		{
			if (data.GetID().size() >= 4)
				break;
			else
			{
				cout << "\tThis ID is less than 4 characters." << endl;
				pause;
			}
		}

	}

	data.SetPW("");

	// ��й�ȣ �ޱ�
	while (data.GetPW().size() < 8)
	{
		data.SetPW("");
		system("cls");
		cout << endl << endl;
		cout << "\t[[ Sign Up ]]" << endl;
		data.DisplayIDOnScreen();
		cout << "\tPlease enter password at least 8 characters." << endl;
		cout << "\tPassword must be used alphabet or number." << endl;
		data.SetPWFromKB();

		if (data.GetPW().size() < 8)
		{
			cout << "\tThis password is less than 8 characters." << endl;
			pause;
		}
	}

	// ��й�ȣ Ȯ��
	while (tmp.GetPW() != data.GetPW())
	{
		tmp.SetPW("");
		system("cls");
		cout << endl << endl;
		cout << "\t[[ Sign Up ]]" << endl;
		data.DisplayIDOnScreen();
		data.DisplayPWOnScreen();

		if (pwChkNum > 3)
		{
			char cmd;
			cout << "\tDo you want to go back main screen? (Y/N)  ";
			cin >> cmd;
			switch (cmd)
			{
			case 'Y':
				return;
			case 'y':
				return;
			case 'N':
				cin.ignore();
				break;
			case 'n':
				cin.ignore();
				break;
			default:
				cout << "\tIllegal selection...\n";
				pause;
				return;
			}
		}

		cout << "\tPlease enter password once more." << endl;
		tmp.SetPWFromKB();

		if (tmp.GetPW() != data.GetPW())
		{
			cout << "\tThis is not consistent with that password." << endl;
			pause;
		}

		pwChkNum++;
	}

	// ����Ʈ�� Get�Լ��� ���� �̸��� ����Ǿ������� �����Ƿ� �̸� �ʱ�ȭ
	data.SetName("");

	// �̸� �Է� �ޱ�
	system("cls");
	cout << endl << endl;
	cout << "\t[[ Sign Up ]]" << endl;
	data.DisplayIDOnScreen();
	data.DisplayPWOnScreen();
	data.SetNameFromKB();

	// ���� ����Ʈ�� �߰�
	UserList.Add(data);

	return;
}


// Find user ID
int LoginApplication::FindID()
{
	UserType data;
	UserType tmp;
	SingleSortedLinkedList<UserType> tempList;
	bool found = false;

	cin.ignore();

	system("cls");
	cout << endl << endl;
	cout << "\t[[ Find ID ]]" << endl;
	cout << "\tEnter your name." << endl;
	data.SetNameFromKB();

	if (UserList.GetLength() != 0)
	{
		// ���� ����Ʈ �ʱ�ȭ
		UserList.ResetList();

		// �̸����� ã��
		for (int i = 0; i < UserList.GetLength(); i++)
		{
			UserList.GetNextItem(tmp);

			if (tmp.GetName() == data.GetName())
			{
				tempList.Add(tmp);
				found = true;
			}
		}

		// �̸��� �´� ID�� ���� ȭ�鿡 ���
		if (tempList.GetLength() != 0)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t[[ Find ID ]]" << endl;
			data.DisplayNameOnScreen();
			cout << endl;

			// tempList �ʱ�ȭ
			tempList.ResetList();

			// ��� ȭ�鿡 ���
			for (int i = 0; i < tempList.GetLength(); i++)
			{
				tempList.GetNextItem(tmp);
				cout << "\tNo. " << i + 1 << endl;

				string id = tmp.GetID();
				id.replace(id.size() - 2, 2, "**");

				cout << "\tID\t : " << id << endl;
				cout << endl;

			}

			// �н����� ã������ ���
			char cmd;
			cout << "\tDo you want to find your password? (Y/N)  ";
			cin >> cmd;
			switch (cmd)
			{
			case 'Y':
				FindPW();
				return 1;
			case 'y':
				FindPW();
				return 1;
			case 'N':
				return 1;
			case 'n':
				return 1;
			default:
				cout << "\tIllegal selection...\n";
				pause;
				break;
			}
		}
	}

	if (!found)
	{
		cout << "\n\tTarget account isn't exist in user list." << endl;
		pause;
		return 0;
	}

	return 1;
}


// Find user password
int LoginApplication::FindPW(){
	UserType data;
	UserType tmp;
	UserType chk;
	bool found = false;

	cin.ignore();

	system("cls");
	cout << endl << endl;
	cout << "\t[[ Find PW ]]" << endl;
	cout << "\tEnter your ID." << endl;
	data.SetIDFromKB();

	if (UserList.GetLength() != 0)
	{
		// ���� ����Ʈ �ʱ�ȭ
		UserList.ResetList();

		// ID�� ã��
		for (int i = 0; i < UserList.GetLength(); i++)
		{
			UserList.GetNextItem(tmp);
			if (tmp == data)
			{
				found = true;
				chk.SetRecord(tmp.GetID(), tmp.GetPW(), tmp.GetName());
			}
		}

		// ã�Ҵٸ�
		if (found)
		{
			while (data.GetName() != chk.GetName())
			{
				data.SetName("");

				system("cls");
				cout << endl << endl;
				cout << "\t[[ Find PW ]]" << endl;
				data.DisplayIDOnScreen();
				cout << "\tEnter your name." << endl;
				data.SetNameFromKB();

				if (data.GetName() != chk.GetName())
				{
					cout << "\tWrong name! Please enter right name!" << endl;
					pause;
				}
			}

			cout << "\n\t< Your password >" << endl;

			string pw = chk.GetPW();
			pw.replace(pw.size() - 3, 3, "***");

			cout << "\tPW\t : " << pw << endl << endl;
			pause;
			return 1;
		}
	}

	// ����Ʈ�� ����ų� ã�� �� ���� ��
	cout << "\n\tTarget account isn't exist in user list." << endl;
	pause;
	return 0;
}


// Open a file by file descriptor as an input file.
int LoginApplication::OpenInFile(char* fileName)
{
	// file open for reading.
	m_InFile.open(fileName);

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int LoginApplication::OpenOutFile(char* fileName)
{
	// file open for writing.
	m_OutFile.open(fileName);

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Load DB from file
int LoginApplication::LoadDB()
{
	int index = 0;

	// �б�� �ӽ� ����
	UserType data;

	// file open, open error�� �߻��ϸ� 0�� ����
	char f[13] = "DB\\Users.txt";

	if (!OpenInFile(f))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// List�� �ּҵ��� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		if (data.GetID() == "")
			break;
		UserList.Add(data);
	}

	m_InFile.close();	// file close

	return 1;
}


// Save DB into file
int LoginApplication::SaveDB()
{
	// ����� �ӽ� ����
	UserType data;

	// file open, open error�� �߻��ϸ� 0�� ����
	char f[13] = "DB\\Users.txt";
	if (!OpenOutFile(f))
		return 0;

	// list �����͸� �ʱ�ȭ
	UserList.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = UserList.GetLength();
	int curIndex = 0;
	while (curIndex < length)
	{
		UserList.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
		curIndex++;
	}

	// file close
	m_OutFile.close();

	return 1;
}
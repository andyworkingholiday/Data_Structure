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

		if (idChk != 0){ // 아이디 입력이 틀릴 시
			cout << "\tThat ID does not exist" << endl;
			if (idChk > 3){ // 아이디를 3번 이상 틀렸을 시
				char cmd;
				char cmd2;
				cout << "\tForgot your ID? (Y/N)  "; // y 선택 시 계정 찾기로 이동
				cin >> cmd;
				switch (cmd) {
				case 'Y': 
					FindID();
					return;
				case 'y':
					FindID();
					return;
				case 'N':
					cout << "\tDon't you have your account? (Y/N)  "; // y 선택 시 계정 만들기로 이동
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

	// user's mail app 작동
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

	// ID 입력 받기
	while (data.GetID().size() < 4 && !UserList.Get(data))
	{
		data.SetID("");
		system("cls");
		cout << endl << endl;
		cout << "\t[[ Sign Up ]]" << endl;
		cout << "\tPlease enter ID at least 4 characters." << endl;
		cout << "\tID must be used alphabet or number." << endl;
		data.SetIDFromKB();

		// 회원 리스트에 존재하면
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

	// 비밀번호 받기
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

	// 비밀번호 확인
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

	// 리스트의 Get함수에 의해 이름이 저장되었을수도 있으므로 이름 초기화
	data.SetName("");

	// 이름 입력 받기
	system("cls");
	cout << endl << endl;
	cout << "\t[[ Sign Up ]]" << endl;
	data.DisplayIDOnScreen();
	data.DisplayPWOnScreen();
	data.SetNameFromKB();

	// 유저 리스트에 추가
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
		// 유저 리스트 초기화
		UserList.ResetList();

		// 이름으로 찾기
		for (int i = 0; i < UserList.GetLength(); i++)
		{
			UserList.GetNextItem(tmp);

			if (tmp.GetName() == data.GetName())
			{
				tempList.Add(tmp);
				found = true;
			}
		}

		// 이름이 맞는 ID들 전부 화면에 출력
		if (tempList.GetLength() != 0)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t[[ Find ID ]]" << endl;
			data.DisplayNameOnScreen();
			cout << endl;

			// tempList 초기화
			tempList.ResetList();

			// 모두 화면에 출력
			for (int i = 0; i < tempList.GetLength(); i++)
			{
				tempList.GetNextItem(tmp);
				cout << "\tNo. " << i + 1 << endl;

				string id = tmp.GetID();
				id.replace(id.size() - 2, 2, "**");

				cout << "\tID\t : " << id << endl;
				cout << endl;

			}

			// 패스워드 찾을건지 물어봄
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
		// 유저 리스트 초기화
		UserList.ResetList();

		// ID로 찾기
		for (int i = 0; i < UserList.GetLength(); i++)
		{
			UserList.GetNextItem(tmp);
			if (tmp == data)
			{
				found = true;
				chk.SetRecord(tmp.GetID(), tmp.GetPW(), tmp.GetName());
			}
		}

		// 찾았다면
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

	// 리스트가 비었거나 찾지 못 했을 때
	cout << "\n\tTarget account isn't exist in user list." << endl;
	pause;
	return 0;
}


// Open a file by file descriptor as an input file.
int LoginApplication::OpenInFile(char* fileName)
{
	// file open for reading.
	m_InFile.open(fileName);

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int LoginApplication::OpenOutFile(char* fileName)
{
	// file open for writing.
	m_OutFile.open(fileName);

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Load DB from file
int LoginApplication::LoadDB()
{
	int index = 0;

	// 읽기용 임시 변수
	UserType data;

	// file open, open error가 발생하면 0을 리턴
	char f[13] = "DB\\Users.txt";

	if (!OpenInFile(f))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// List에 주소들의 정보가 들어있는 structure 저장
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
	// 쓰기용 임시 변수
	UserType data;

	// file open, open error가 발생하면 0을 리턴
	char f[13] = "DB\\Users.txt";
	if (!OpenOutFile(f))
		return 0;

	// list 포인터를 초기화
	UserList.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->Create->setVisible(false);
    ui->Back->setVisible(false);
    ui->lineEdit_Name->setVisible(false);
    LoadDB();
}

MainWindow::~MainWindow()
{
    SaveDB();
    delete ui;
}

// Open a file by file descriptor as an input file.
int MainWindow::OpenInFile(char* fileName)
{
    // file open for reading.
    m_InFile.open(fileName);

    // 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
    if (!m_InFile)	return 0;
    else	return 1;
}


// Open a file by file descriptor as an output file.
int MainWindow::OpenOutFile(char* fileName)
{
    // file open for writing.
    m_OutFile.open(fileName);

    // 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
    if (!m_OutFile)	return 0;
    else	return 1;
}

// Load DB from file
int MainWindow::LoadDB()
{

    // 읽기용 임시 변수
    UserType data;

    // file open, open error가 발생하면 0을 리턴
    char f[13] = "DB\\Users.txt";

    if (!OpenInFile(f)) {
        QMessageBox::warning(this, "File Corrupt", "File Read Fail!");
        return 0;
    }




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
int MainWindow::SaveDB()
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




void MainWindow::on_LogIn_clicked()
{
    QString idd = ui->lineEdit_ID->text();
    QString pww = ui->lineEdit_PW->text();

    string id = idd.toStdString();
    string pw = pww.toStdString();
    UserType data,copy;
    data.SetID(id);
    data.SetPW(pw);
    copy=data;

    if(UserList.Get(data)) {
        if(data.GetPW()==copy.GetPW()) {
            QMessageBox::information(this, "Login", "Login Success!");
            close();
            newDialog= new MainDialog(this);
            newDialog->SetUser(data);
            newDialog->LoadDB();
            newDialog->show();
        }

        else {
            QMessageBox::warning(this, "Login", "Password Incorrect!");
        }
    }

    else {
        QMessageBox::warning(this, "Login", "ID Incorrect!");
    }


}

void MainWindow::on_Quit_clicked()
{
    SaveDB();
    delete ui;
}

void MainWindow::on_Back_clicked()
{
    ui->Create->setVisible(false);
    ui->Back->setVisible(false);
    ui->lineEdit_Name->setVisible(false);

    ui->LogIn->setVisible(true);
    ui->SignUp->setVisible(true);

    ui->lineEdit_ID->clear();
    ui->lineEdit_PW->clear();
    ui->lineEdit_Name->clear();

}

void MainWindow::on_SignUp_clicked()
{
    ui->Create->setVisible(true);
    ui->Back->setVisible(true);
    ui->lineEdit_Name->setVisible(true);
    ui->LogIn->setVisible(false);
    ui->SignUp->setVisible(false);
    ui->lineEdit_ID->clear();
    ui->lineEdit_PW->clear();
    ui->lineEdit_Name->clear();

}

void MainWindow::on_Create_clicked()
{
    QString idd = ui->lineEdit_ID->text();
    QString pww = ui->lineEdit_PW->text();
    QString nname = ui->lineEdit_Name->text();

    string id = idd.toStdString();
    string pw = pww.toStdString();
    string name= nname.toStdString();

    if(id.length()>=4) {
        if(pw.length()>=4) {
            UserType data;
            data.SetID(id); data.SetPW(pw); data.SetName(name);
            UserList.Add(data);

            QMessageBox::information(this, "SignUp", "Create Success!");
            on_Back_clicked();
            SaveDB();
        }

        else {
            QMessageBox::warning(this, "SignUp", "Password must be at least 4 characters!");
        }
    }

    else {
        QMessageBox::warning(this, "SignUp", "ID must be at least 4 characters!");
    }

}

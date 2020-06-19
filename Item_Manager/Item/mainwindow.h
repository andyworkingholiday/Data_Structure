#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QScreen>
#include "pch.h"
#include "maindialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private slots:
    void on_LogIn_clicked();

    void on_Quit_clicked();

    void on_Back_clicked();

    void on_SignUp_clicked();

    void on_Create_clicked();

private:
    Ui::MainWindow *ui;
    ifstream m_InFile;				///< input file descriptor.
    ofstream m_OutFile;				///< output file descriptor.
    SingleSortedLinkedList<UserType> UserList;	///< user list.
    MainDialog *newDialog;
};
#endif // MAINWINDOW_H

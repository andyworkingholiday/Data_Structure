#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "pch.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

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

    /**
    *	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
    *	@pre	The file is not opened.
    *	@post	list holds all records from the file.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int LoadDB();

    /**
    *	@brief	Open a file as a write mode, and write all data into the file,
    *	@pre	The file is not opened.
    *	@post	the list is stored in the output file.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int SaveDB();

    void SetUser(UserType user);

    string SetTimeFromSystem();
    string GetRTimeFromItem(ItemType data);

    /**
    *	@brief	Add new record into Master list.
    *	@pre	The Master list should be initialized.
    *	@post	new record is added into the the Master list and Container List together
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int AddItemToMaster();

    /**
    *	@brief	Add new record into Master list.
    *	@pre	The Master list should be initialized.
    *	@post	new record is added into the the Master list and Container List together
    *	@param	data	The data which is put
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int AddItemToMasterList(ItemType data);

    /**
    *	@brief	Add new record into Temporary list.
    *	@pre	The Temporary list. should be initialized.
    *	@post	new record is added into the the Temporary list.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int AddItemToTemp();

    /**
    *	@brief	Delete item using binary search from the All the List
    *	@pre	List should be initalized
    *	@post	Delete the item with same primary key from the All the List
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int DeleteItem();

    /**
    *	@brief	Replace item using binary search from the Master List
    *	@pre	List should be initalized
    *	@post	Replace the item with same primary key from the Master List
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int ReplaceItemFromMaster();

    /**
    *	@brief	Display all Items in the stroage.
    *	@pre	none.
    *	@post	none.
    */
    void DisplayItembyLocation(int n);

    void ReadFromGuiMaster(ItemType& data);
    void ReadFromGuiTemp(ItemType& data);
    void ReadFromGuiChange(ItemType& data);
    void ShowMasterGui();
    void ShowTempGui();
    void ShowSearchGui(ItemType data, int index);

private slots:
    void on_AddPush_clicked();

    void on_AddPush_2_clicked();

    void on_DeletePush_clicked();

    void on_AddPush_3_clicked();

    void on_ChangePush_clicked();

    void on_FindByUsage_clicked();

    void on_FindNamePush_clicked();

    void on_FindNumerPush_clicked();

    void on_FindByDate_clicked();

    void on_SavePush_clicked();

    void on_QuitPush_clicked();

    void on_ChoosePush_clicked();

    void on_AddPhotoPush_clicked();

    void on_ShowPhotoPush_clicked();

    void on_DeletePhotoPush_clicked();

private:
    Ui::MainDialog *ui;
    ifstream m_InFile;
    ofstream m_OutFile;
    UserType User;	///< program user.
    DoublySortedLinkedList<ItemType> MasterList;
    DoublySortedLinkedList<StorageType> PlaceList;
    DoublySortedLinkedList<ItemType> TempList;
};

#endif // MAINDIALOG_H

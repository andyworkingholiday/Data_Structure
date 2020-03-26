#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class ItemType {
public:
	ItemType() {
		m_SongName = "";
		m_Composer = "";
		m_Artist = "";
		m_Genre = 0;
		m_SongNumber = 0;
	}

	~ItemType() {}

	bool operator == (ItemType& data) {
		if (this->m_SongNumber == data.m_SongNumber) return true;
		return false;
	}

	string GetName();
	string GetComposer();
	string GetArtist();
	int GetGenre();
	int GetSongNumber();
	void SetName(string inName);
	void SetComposer(string inComposer);
	void SetArtist(string inArtist);
	void SetGenre(int inGenre);
	void SetSongNumber(int inSongNumber);
	void SetRecord(string inName, string inComposer, string inArtist, int inGenre, int inSongNumber);
	void DisplayNameOnScreen();
	void DisplayComposerOnScreen();
	void DisplayArtistOnScreen();
	void DisplayGenreOnScreen();
	void DisplaySongNumberOnScreen();
	void DisplayRecordOnScreen();
	void SetNameFromKB();
	void SetComposerFromKB();
	void SetArtistFromKB();
	void SetGenreFromKB();
	void SetSongNumberFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	RelationType CompareBySongNumber(ItemType data);

private:
	string m_SongName;
	string m_Composer;
	string m_Artist;
	int m_Genre;
	int m_SongNumber;
};

#endif	// _ITEMTYPE_H
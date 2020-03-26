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

	// ArrayList에서 GET, DELETE, REPLACE 함수를 사용할 때 compareID함수를 쓰면 Generic에 위반되기 
	// 때문에 따로 연산자를 정의해 주었습니다.

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
	string m_SongName; //곡명
	string m_Composer; // 작곡가
	string m_Artist; // 아티스트명
	int m_Genre; // 장르 ex) 1 = Pop, 2 = Ballad ...
	int m_SongNumber; // 곡의 고유번호 Primary key
};

#endif	// _ITEMTYPE_H
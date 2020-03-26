#include "ItemType.h"
#include <string>
using namespace std;

string ItemType::GetName() {
	return this->m_SongName;
}

string ItemType::GetComposer() {
	return this->m_Composer;
}

string ItemType::GetArtist() {
	return this->m_Artist;
}

int ItemType::GetGenre() {
	return this->m_Genre;
}

int ItemType::GetSongNumber() {
	return this->m_SongNumber;
}

void ItemType::SetName(string inName) {
	this->m_SongName = inName;
}

void ItemType::SetComposer(string inComposer) {
	this->m_Composer = inComposer;
}

void ItemType::SetArtist(string inArtist) {
	this->m_Artist = inArtist;
}


void ItemType::SetGenre(int inGenre) {
	this->m_Genre = inGenre;
}

void ItemType::SetSongNumber(int inSongNumber) {
	this->m_SongNumber = inSongNumber;
}

void ItemType::SetRecord(string inName, string inComposer, string inArtist, int inGenre, int inSongNumber) {
	SetName(inName);
	SetComposer(inComposer);
	SetArtist(inArtist);
	SetGenre(inGenre);
	SetSongNumber(inSongNumber);
}

void ItemType::DisplayNameOnScreen() {
	cout << "\tSongName    : " << m_SongName << endl;
}

void ItemType::DisplayComposerOnScreen() {
	cout << "\tComposer    : " << m_Composer << endl;
}

void ItemType::DisplayArtistOnScreen() {
	cout << "\tArtist    : " << m_Artist << endl;
}

void ItemType::DisplayGenreOnScreen() {
	printf("\tGenre    : %d\n", m_Genre);
}

void ItemType::DisplaySongNumberOnScreen() {
	printf("\tSongNumber    : %d\n", m_SongNumber);
}
void ItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayNameOnScreen();
	DisplayComposerOnScreen();
	DisplayArtistOnScreen();
	DisplayGenreOnScreen();
	DisplaySongNumberOnScreen();
}

void ItemType::SetNameFromKB() {
	printf("\tSongName    : ");
	cin >> m_SongName;
}

void ItemType::SetComposerFromKB() {
	printf("\tComposer    : ");
	cin >> m_Composer;
}

void ItemType::SetArtistFromKB() {
	printf("\tArtist    : ");
	cin >> m_Artist;
}

void ItemType::SetGenreFromKB() {
	printf("\tGenre    : ");
	cin >> m_Genre;
}

void ItemType::SetSongNumberFromKB() {
	printf("\tSongNumber    : ");
	cin >> m_SongNumber;
}

void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetComposerFromKB();
	SetArtistFromKB();
	SetGenreFromKB();
	SetSongNumberFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_SongName;
	fin >> m_Composer;
	fin >> m_Artist;
	fin >> m_Genre;
	fin >> m_SongNumber;
	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_SongName;
	fout << m_Composer;
	fout << m_Artist;
	fout << m_Genre;
	fout << m_SongNumber;
	return 1;
}

RelationType ItemType::CompareBySongNumber(ItemType data) {
	if (this->m_SongNumber < data.m_SongNumber) return LESS;
	else if (this->m_SongNumber > data.m_SongNumber) return GREATER;
	else return EQUAL;
}
#include "ItemType.h"
#include <string>
using namespace std;

// 곡명을 return하는 함수
string ItemType::GetName() { 
	return this->m_SongName;
}

// 작곡가를 return하는 함수
string ItemType::GetComposer() {
	return this->m_Composer;
}

// 아티스트를 return하는 함수
string ItemType::GetArtist() {
	return this->m_Artist;
}

// 장르를 return하는 함수
int ItemType::GetGenre() {
	return this->m_Genre;
}

// 곡번호를 return하는 함수
int ItemType::GetSongNumber() {
	return this->m_SongNumber;
}

// 곡명을 set하는 함수
void ItemType::SetName(string inName) {
	this->m_SongName = inName;
}

// 작곡가를 set하는 함수
void ItemType::SetComposer(string inComposer) {
	this->m_Composer = inComposer;
}

// 아티스트를 set하는 함수
void ItemType::SetArtist(string inArtist) {
	this->m_Artist = inArtist;
}

// 장르를 set하는 함수
void ItemType::SetGenre(int inGenre) {
	this->m_Genre = inGenre;
}

// 곡번호를 set하는 함수
void ItemType::SetSongNumber(int inSongNumber) {
	this->m_SongNumber = inSongNumber;
}

// Itemtype의 모든 멤버변수를 Set하는 함수
void ItemType::SetRecord(string inName, string inComposer, string inArtist, int inGenre, int inSongNumber) {
	SetName(inName);
	SetComposer(inComposer);
	SetArtist(inArtist);
	SetGenre(inGenre);
	SetSongNumber(inSongNumber);
}

//곡명 출력 함수
void ItemType::DisplayNameOnScreen() {
	cout << "\tSongName    : " << m_SongName << endl;
}

//작곡가 출력 함수
void ItemType::DisplayComposerOnScreen() {
	cout << "\tComposer    : " << m_Composer << endl;
}

//아티스트 출력 함수
void ItemType::DisplayArtistOnScreen() {
	cout << "\tArtist    : " << m_Artist << endl;
}

//장르 출력 함수
void ItemType::DisplayGenreOnScreen() {
	printf("\tGenre    : %d\n", m_Genre);
}

//곡번호 출력 함수
void ItemType::DisplaySongNumberOnScreen() {
	printf("\tSongNumber    : %d\n", m_SongNumber);
}

//모든 멤버변수 출력 함수
void ItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayNameOnScreen();
	DisplayComposerOnScreen();
	DisplayArtistOnScreen();
	DisplayGenreOnScreen();
	DisplaySongNumberOnScreen();
}

//곡명 입력받는 함수
void ItemType::SetNameFromKB() {
	printf("\tSongName    : ");
	cin >> m_SongName;
}

//작곡가 입력받는 함수
void ItemType::SetComposerFromKB() {
	printf("\tComposer    : ");
	cin >> m_Composer;
}

//아티스트 입력받는 함수
void ItemType::SetArtistFromKB() {
	printf("\tArtist    : ");
	cin >> m_Artist;
}

//장르 입력받는 함수
void ItemType::SetGenreFromKB() {
	printf("\tGenre    : ");
	cin >> m_Genre;
}

//곡번호 입력받는 함수
void ItemType::SetSongNumberFromKB() {
	printf("\tSongNumber    : ");
	cin >> m_SongNumber;
}

//모든 멤버변수 입력받는 함수
void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetComposerFromKB();
	SetArtistFromKB();
	SetGenreFromKB();
	SetSongNumberFromKB();
}

//파일로부터 입력받는 함수
int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_SongName;
	fin >> m_Composer;
	fin >> m_Artist;
	fin >> m_Genre;
	fin >> m_SongNumber;
	return 1;
}

//파일로 출력하는 함수
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_SongName;
	fout << m_Composer;
	fout << m_Artist;
	fout << m_Genre;
	fout << m_SongNumber;
	return 1;
}

//연산자 정의를 안할 시 Primary key로 Itemtype을 비교하기 위해 정의한 함수
RelationType ItemType::CompareBySongNumber(ItemType data) {
	if (this->m_SongNumber < data.m_SongNumber) return LESS;
	else if (this->m_SongNumber > data.m_SongNumber) return GREATER;
	else return EQUAL;
}
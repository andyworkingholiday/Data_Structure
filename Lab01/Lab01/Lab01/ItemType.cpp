#include "ItemType.h"
#include <string>
using namespace std;

// ����� return�ϴ� �Լ�
string ItemType::GetName() { 
	return this->m_SongName;
}

// �۰�� return�ϴ� �Լ�
string ItemType::GetComposer() {
	return this->m_Composer;
}

// ��Ƽ��Ʈ�� return�ϴ� �Լ�
string ItemType::GetArtist() {
	return this->m_Artist;
}

// �帣�� return�ϴ� �Լ�
int ItemType::GetGenre() {
	return this->m_Genre;
}

// ���ȣ�� return�ϴ� �Լ�
int ItemType::GetSongNumber() {
	return this->m_SongNumber;
}

// ����� set�ϴ� �Լ�
void ItemType::SetName(string inName) {
	this->m_SongName = inName;
}

// �۰�� set�ϴ� �Լ�
void ItemType::SetComposer(string inComposer) {
	this->m_Composer = inComposer;
}

// ��Ƽ��Ʈ�� set�ϴ� �Լ�
void ItemType::SetArtist(string inArtist) {
	this->m_Artist = inArtist;
}

// �帣�� set�ϴ� �Լ�
void ItemType::SetGenre(int inGenre) {
	this->m_Genre = inGenre;
}

// ���ȣ�� set�ϴ� �Լ�
void ItemType::SetSongNumber(int inSongNumber) {
	this->m_SongNumber = inSongNumber;
}

// Itemtype�� ��� ��������� Set�ϴ� �Լ�
void ItemType::SetRecord(string inName, string inComposer, string inArtist, int inGenre, int inSongNumber) {
	SetName(inName);
	SetComposer(inComposer);
	SetArtist(inArtist);
	SetGenre(inGenre);
	SetSongNumber(inSongNumber);
}

//��� ��� �Լ�
void ItemType::DisplayNameOnScreen() {
	cout << "\tSongName    : " << m_SongName << endl;
}

//�۰ ��� �Լ�
void ItemType::DisplayComposerOnScreen() {
	cout << "\tComposer    : " << m_Composer << endl;
}

//��Ƽ��Ʈ ��� �Լ�
void ItemType::DisplayArtistOnScreen() {
	cout << "\tArtist    : " << m_Artist << endl;
}

//�帣 ��� �Լ�
void ItemType::DisplayGenreOnScreen() {
	printf("\tGenre    : %d\n", m_Genre);
}

//���ȣ ��� �Լ�
void ItemType::DisplaySongNumberOnScreen() {
	printf("\tSongNumber    : %d\n", m_SongNumber);
}

//��� ������� ��� �Լ�
void ItemType::DisplayRecordOnScreen() {
	printf("\n");
	DisplayNameOnScreen();
	DisplayComposerOnScreen();
	DisplayArtistOnScreen();
	DisplayGenreOnScreen();
	DisplaySongNumberOnScreen();
}

//��� �Է¹޴� �Լ�
void ItemType::SetNameFromKB() {
	printf("\tSongName    : ");
	cin >> m_SongName;
}

//�۰ �Է¹޴� �Լ�
void ItemType::SetComposerFromKB() {
	printf("\tComposer    : ");
	cin >> m_Composer;
}

//��Ƽ��Ʈ �Է¹޴� �Լ�
void ItemType::SetArtistFromKB() {
	printf("\tArtist    : ");
	cin >> m_Artist;
}

//�帣 �Է¹޴� �Լ�
void ItemType::SetGenreFromKB() {
	printf("\tGenre    : ");
	cin >> m_Genre;
}

//���ȣ �Է¹޴� �Լ�
void ItemType::SetSongNumberFromKB() {
	printf("\tSongNumber    : ");
	cin >> m_SongNumber;
}

//��� ������� �Է¹޴� �Լ�
void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetComposerFromKB();
	SetArtistFromKB();
	SetGenreFromKB();
	SetSongNumberFromKB();
}

//���Ϸκ��� �Է¹޴� �Լ�
int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_SongName;
	fin >> m_Composer;
	fin >> m_Artist;
	fin >> m_Genre;
	fin >> m_SongNumber;
	return 1;
}

//���Ϸ� ����ϴ� �Լ�
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_SongName;
	fout << m_Composer;
	fout << m_Artist;
	fout << m_Genre;
	fout << m_SongNumber;
	return 1;
}

//������ ���Ǹ� ���� �� Primary key�� Itemtype�� ���ϱ� ���� ������ �Լ�
RelationType ItemType::CompareBySongNumber(ItemType data) {
	if (this->m_SongNumber < data.m_SongNumber) return LESS;
	else if (this->m_SongNumber > data.m_SongNumber) return GREATER;
	else return EQUAL;
}
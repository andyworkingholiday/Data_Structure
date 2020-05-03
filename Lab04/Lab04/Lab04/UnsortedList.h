#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#define MAXSIZE 5
using namespace std;

/**
*	array based simple unsorted list.
*/
template<typename T>
class UnsortedList {
public:
	void operator=(const UnsortedList& data) {
		delete[] m_Array;
		m_Length = data.m_Length;
		m_Array = new T[MAXSIZE];
		for (int i = 0; i < m_Length; i++) {
			m_Array[i] = data.m_Array[i];
		}
	}

	friend ostream& operator<<(ostream& os, const UnsortedList& _item) {
		for (int i = 0; i < _item.m_Length; i++){
			os << _item.m_Array[i] << endl;
		}
		return os;
	}

	/**
	*	default constructor.
	*/
	UnsortedList();

	/**
	*	constructor with size max.
	*/
	UnsortedList(int max);

	/**
	*	destructor.
	*/
	~UnsortedList();

	/**
	*	@brief	resize the list
	*	@pre	none.
	*	@post	list resized
	*/
	void resize(int max);

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	Check capacity of list is Empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the lower bound, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 data값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 data값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T& data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 data값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T& data);

	/**
	*	@brief	Print all the items in the list on screen
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	Print all the strings in the list on screen
	*	@pre	list has been initialized.
	*	@post	None.
	*/
	void Printstring();

private:
	T* m_Array; // list array.
	int m_Length; // number of elements in list.
	int m_CurPointer; // iterator pointer.
	int m_Maxsize; // Max size.
};


template<typename T>
UnsortedList<T>::UnsortedList() {
	m_Maxsize = MAXSIZE;
	m_Length = 0;
	ResetList(); //멤버 변수들을 초기화시켜준다.
	m_Array = new T[m_Maxsize]; //m_Array에 크기가 MAXSIZE인 배열을 만든다.
}

template<typename T>
UnsortedList<T>::UnsortedList(int max) {
	m_Maxsize = max; // parameter로 받은 max 값으로 maxsize를 설정한다.
	m_Length = 0;
	ResetList(); //멤버 변수들을 초기화시켜준다.
	m_Array = new T[m_Maxsize];  //m_Array에 크기가 max인 배열을 만든다.
}

template<typename T>
UnsortedList<T>::~UnsortedList() {
	delete[] m_Array; //동적할당했던 메모리를 해제해준다.
}

// 크기를 재설정 합니다.
template<typename T>
void UnsortedList<T>::resize(int max) {
	delete[] m_Array;
	m_Maxsize = max; // parameter로 받은 max 값으로 maxsize를 재설정한다.
	m_Length = 0;
	ResetList(); //멤버 변수들을 다시 초기화시켜준다.
	m_Array = new T[m_Maxsize];  //m_Array에 크기가 max인 배열을 새로 만든다.
}

// Make list empty.
template<typename T>
void UnsortedList<T>::MakeEmpty() {
	m_Length = 0;
}

// Get a number of records in current list.
template<typename T>
int UnsortedList<T>::GetLength() {
	return m_Length;
}

// List가 MAXSIZE 만큼 채워져있을 시 true, 아닐 시 false
template<typename T>
bool UnsortedList<T>::IsFull() {
	if (m_Length == MAXSIZE) {
		printf("\tList is Full!\n");
		return true;
	}
	return false;
}

// List가 아예 비워져있을 시 true, 아닐 시 false
template<typename T>
bool UnsortedList<T>::IsEmpty() {
	if (!m_Length) {
		printf("\tList is Empty!\n");
		return true;
	}
	return false;
}

// List에 순차적으로 Item 추가 동일한 primary key가 있으면 추가를 못한다.
template<typename T>
int UnsortedList<T>::Add(T data) {
	if (!IsFull()) {
		if (Get(data) == -1) {
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		else printf("\n\t Same data has found.\n");
		return 0;
	}
	return 0;
}

// 검색 Iterator를  초기화
template<typename T>
void UnsortedList<T>::ResetList() {
	m_CurPointer = -1;
}

// Pointer의 위치를 한 칸 이동하여 그 때의 인덱스를 반환한다.
// 그리고 함수의 parameter인 data에는 그 인덱스의 변수가 복사된다.
// 만일 List가 Full 일 시 -1을 반환한다.
template<typename T>
int UnsortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// parameter data의 primary key와 일치하는 것이 있는지 List를 처음부터 순차적으로 돌면서 확인한다.
// 있을 때는 그때의 index를 반환하고 없을 시 -1을 반환한다.
template<typename T>
int UnsortedList<T>::Get(T& data) {
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (data == m_Array[m_CurPointer]) {
			data = m_Array[m_CurPointer];
			return m_CurPointer;
		}
	}
	return -1;
}

// parameter data의 primary key와 일치하는 것이 있는지 List를 처음부터 순차적으로 돌면서 확인한다.
// 있을 때는 그 list의 data를 삭제하고 뒤에 있는 data들을 한칸 앞으로 땡긴다.
// 없을 시 0을 반환한다.
template<typename T>
int UnsortedList<T>::Delete(T& data) {
	ResetList();
	m_CurPointer++;
	bool flag = false;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (data == m_Array[m_CurPointer]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		if (m_CurPointer != m_Length - 1) {
			for (m_CurPointer; m_CurPointer < m_Length - 1; m_CurPointer++) {
				m_Array[m_CurPointer] = m_Array[m_CurPointer + 1];
			}
		}
		m_Length--;
		return 1;
	}
	else return 0;
}

// parameter data의 primary key와 일치하는 것이 있는지 List를 처음부터 순차적으로 돌면서 확인한다.
// 있을 때 함수의 parameter data를 List 해당 인덱스로 대체시킨다.
template <typename T>
int UnsortedList<T>::Replace(T& data) {
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++) {
		if (data == m_Array[m_CurPointer]) {
			m_Array[m_CurPointer] = data;
			return 1;
		}
	}
	return 0;
}

// Print all the items in the stack on screen
template<typename T>
void UnsortedList<T>::Print() {
	ResetList();
	T item;
	int len = GetLength(); // 리스트에 담긴 아이템의 갯수
	while (len--) { // 아이템의 갯수만큼 data 출력
		if (GetNextItem(item) >= 0)
			cout << item << endl;
	}
}

// Print all the strings in the stack on screen
template<typename T>
void UnsortedList<T>::Printstring() {
	ResetList();
	T item;
	int len = GetLength(); // 리스트에 담긴 아이템의 갯수
	while (len--) { // 아이템의 갯수만큼 data 출력
		if (GetNextItem(item) >= 0)
			cout << "\t" << item << endl;
	}
}
#endif	// _UNSORTEDLIST_H
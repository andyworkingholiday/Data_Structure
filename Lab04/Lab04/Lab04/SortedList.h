#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#define MAXSIZE 6
using namespace std;

/**
*	array based simple sorted list.
*/
template<typename T>
class SortedList {
public:

	/**
	*	default constructor.
	*/
	SortedList();

	/**
*	@brief	Allocate dynamic array whose size is max.
*	@pre	none.
*	@post	Member of items points the allocated array.
*/
	SortedList(int max);

	/**
	*	destructor.
	*/
	~SortedList();

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
	*	@brief	Check capacity of list is empty.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the lower bound, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	Print all the items in the List on screen
	*	@pre	List has been initialized.
	*	@post	None.
	*/
	void Print();

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
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T& data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Retrieve_SeqS(T& data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 index 값, 실패시 -1을 리턴한다.
	*/
	int RetrieveByBS(T& data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값.
	*	@return	성공(발견)시 index 값, 실패시 -1을 리턴한다.
	*/
	int RetrieveByBS_noCopy(T& data);

private:
	T* m_Array; // list array.
	int m_Length; // number of elements in list.
	int m_CurPointer; // iterator pointer.
	int m_Maxsize; // Max size.
};

template<typename T>
SortedList<T>::SortedList() {
	m_Maxsize = MAXSIZE;
	m_Length = 0;
	ResetList(); //멤버 변수들을 초기화시켜준다.
	m_Array = new T[m_Maxsize]; //m_Array에 크기가 MAXSIZE인 배열을 만든다.
}

template<typename T>
SortedList<T>::SortedList(int max) {
	m_Maxsize = max; // parameter로 받은 max 값으로 maxsize를 설정한다.
	m_Length = 0;
	ResetList(); //멤버 변수들을 초기화시켜준다.
	m_Array = new T[m_Maxsize];  //m_Array에 크기가 max인 배열을 만든다.
}

template<typename T>
SortedList<T>::~SortedList() {
	delete[] m_Array; //동적할당했던 메모리를 해제해준다.
}

// 크기를 재설정한다.
template<typename T>
void SortedList<T>::resize(int max) {
	delete[] m_Array;
	m_Maxsize = max; // parameter로 받은 max 값으로 maxsize를 설정한다.
	m_Length = 0;
	ResetList(); //멤버 변수들을 초기화시켜준다.
	m_Array = new T[m_Maxsize];  //m_Array에 크기가 max인 배열을 만든다.
}

// Make list empty.
template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}

// Get a number of records in current list.
template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}

// Check capacity of list is full.
template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length == m_Maxsize)
		return true;
	return false;
}

// Check capacity of list is Empty
template<typename T>
bool SortedList<T>::IsEmpty() {
	if (!m_Length)
		return true;
	return false;
}

// Add data to list
template<typename T>
int SortedList<T>::Add(T& data) {
	if (IsEmpty()) { // 리스트가 비어있을 시 첫번 째 인덱스에 추가
		m_Array[0] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull()) return 0; // 리스트 가득 찼을 시 0 return


	else if (data > m_Array[m_Length - 1]) { // 가장 끝의 인덱스보다 값이 클경우
		if (RetrieveByBS(data) == -1) { //만일 이진탐색 시 해당 데이터가 없어야 add가 됩니다.
			m_Array[m_Length] = data;
			m_Length++;
			return 1;
		}
		printf("\n\t Same KeyNumber has found.\n"); // 이진탐색으로 인해 발견을 할 시 add가 되지 않습니다.
		return 0;
	}

	else {
		ResetList();
		T CurItem;
		GetNextItem(CurItem); // 인덱스를 하나씩 더해가면서 param data와 비교합니다.
		while (m_CurPointer < m_Length) {
			if (CurItem < data) // param data가 더 클 시 다음 인덱스와 비교
				GetNextItem(CurItem);
			else if (CurItem > data) { // 해당 인덱스의 primary number가 더 클 시 뒤에 있는 데이터를 한칸 뒤로 땡긴다.
				for (int idx = m_Length - 1; idx >= m_CurPointer; idx--)
					m_Array[idx + 1] = m_Array[idx];
				m_Array[m_CurPointer] = data;
				m_Length++;
				return 1;
			}
			else {  // 동일한 데이터가 발견될 시 add하지 않고 return 0
				printf("\n\t Same KeyNumber has found.\n");
				return 0;
			}

		}
		m_Array[m_CurPointer] = data;
		m_Length++;
		return 1;
	}
}

//Print All the data
template<typename T>
void SortedList<T>::Print() {
	T item;
	ResetList();
	int len = m_Length;
	// Stack 내의 모든 element 출력.
	while (len--) {
		if (GetNextItem(item) >= 0)
			cout << item << endl;
		else break;
	}
}

// Initialize list iterator.
template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

// move list iterator to the next item in list and get that item.
template<typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == m_Maxsize) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// sorted list를 인덱스 0부터 순차적으로 탐색합니다.
template<typename T>
int SortedList<T>::Retrieve_SeqS(T& data) {
	T CurItem;
	ResetList();
	GetNextItem(CurItem);
	while (CurItem < data && m_CurPointer < m_Length) {
		GetNextItem(CurItem);
	}

	if (CurItem == data) { // primary number가 같을 경우 1 return
		data = CurItem;
		return 1;
	}
	else return 0;
}

// Delete data using binary search
template<typename T>
int SortedList<T>::Delete(T& data) {
	int index = RetrieveByBS(data); //이진탐색을 사용하여 해당 index 받아옴
	if (index != -1) { // 동일한 primary number 발견 시 그 뒤에 있는 data를 한칸 뒤로 땡긴다.
		if (index != m_Length - 1) {
			for (int idx = index; idx < m_Length - 1; idx++)
				m_Array[idx] = m_Array[idx + 1];
		}
		m_Length--;
		return 1;
	}

	return 0; // 동일한 primary number 없을 시 즉 index가 -1 일시 return 0
}

// Replace data using binary search
template<typename T>
int SortedList<T>::Replace(T& data) {
	int index = RetrieveByBS_noCopy(data); //이진탐색을 사용하여 해당 index 받아옴
	if (index != -1) { // 동일한 primary number 발견 시 param data를 해당 index에 카피한다.
		m_Array[index] = data;
		return 1;
	}
	else return 0; // 동일한 primary number 없을 시 즉 index가 -1 일시 return 0
}

// Binary search
template<typename T>
int SortedList<T>::RetrieveByBS(T& data) {
	int start = 0, end = m_Length - 1, mid; //start= 0, end = 리스트의 끝, mid= 그 중간
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (m_Array[mid] == data) { // 동일한 primary number 발견 시 해당 index를 return
			data = m_Array[mid];
			return mid;
		}
		else if (m_Array[mid] > data) end = mid - 1; // param data가 mid의 data보다 작다는 것은 0과 mid 사이에 data가 있을 수 있다는 것
		else start = mid + 1; // param data가 mid의 data보다 크다는 것은 mid과 end 사이에 data가 있을 수 있다는 것
	}
	return -1; // 발견 못할 시 -1 return
}

// Binary search
template<typename T>
int SortedList<T>::RetrieveByBS_noCopy(T& data) {
	int start = 0, end = m_Length - 1, mid; //start= 0, end = 리스트의 끝, mid= 그 중간
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (m_Array[mid] == data) { // 동일한 primary number 발견 시 해당 index를 return
			return mid;
		}
		else if (m_Array[mid] > data) end = mid - 1; // param data가 mid의 data보다 작다는 것은 0과 mid 사이에 data가 있을 수 있다는 것
		else start = mid + 1; // param data가 mid의 data보다 크다는 것은 mid과 end 사이에 data가 있을 수 있다는 것
	}
	return -1; // 발견 못할 시 -1 return
}


#endif	// _SORTEDLIST_H
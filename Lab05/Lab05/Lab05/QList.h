#ifndef _QLIST_H
#define _QLIST_H

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/

class FullQueue {
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

/**
*	@brief	Queue class.
*	@details	This class processes as First In, First Out (FIFO), 템플릿을 적용해 다양한 변수 타입을 저장할 수 있다.
*/
template<typename T>
class QList {
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	QList();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	QList(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~QList();

	/**
	*	@brief	resize the queue
	*	@pre	none.
	*	@post	queue resized
	*/
	void resize(int max);

	/**
	*	@brief	Get a number of records in queue.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current queue.
	*/
	int GetLength();

	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront와 m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	void EnQueue(T item);

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	void DeQueue(T &item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	Reset QueueTypelist
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void ResetList();

	/**
	*	@brief	Reset the m_CurPointer
	*	@pre	m_CurPointer has been initialized.
	*	@post	None.
	*/
	void ResetCurrentPointer();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T &item);

	/**
	*	@brief	move list iterator to the next item and search the data
	*	@pre	Queue has been initialized.
	*	@post	search item
	*	@param	data	the data want to find it does not need to be initialized.
	*	@return	if find the item return 1,  oterwise return 0.
	*/
	int Search(T &item);

	/**
	*	@brief	move list iterator to the next item and Delete the data
	*	@pre	Queue has been initialized.
	*	@post	search item
	*	@param	data	the data want to delete it does not need to be initialized.
	*	@return	if delete the item return 1,  oterwise return 0.
	*/
	int Delete(T& item);

	/**
	*	@brief	move list iterator to the next item and Replace the data
	*	@pre	Queue has been initialized.
	*	@post	search item
	*	@param	data	the data want to Replace it has to be initialized.
	*	@return	if Replace the item return 1,  oterwise return 0.
	*/
	int Replace(T item);


private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	int m_Length;
	T* m_pItems;	//pointer for dynamic allocation.
	int m_CurPointer;	// iterator pointer.

};

template<typename T>
QList<T>::QList() {
	m_nMaxQueue = maxQueue;
	m_pItems = new T[maxQueue]; //m_pItems에 크기가 max인 배열을 만든다.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; //멤버 변수들을 초기화시켜준다.
	m_CurPointer = m_nMaxQueue - 1;
	m_Length = 0;
}

template<typename T>
QList<T>::QList(int max) {
	m_nMaxQueue = max;
	m_pItems = new T[max]; //m_pItems에 크기가 max인 배열을 만든다.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront;  //멤버 변수들을 초기화시켜준다.
	m_CurPointer = m_nMaxQueue - 1;
	m_Length = 0;
}

template<typename T>
QList<T>::~QList() {
	delete[] m_pItems; //동적할당했던 메모리를 해제해준다.
}

// 크기를 재설정한다.
template<typename T>
void QList<T>::resize(int max) {
	delete[] m_pItems;
	m_nMaxQueue = max;
	m_pItems = new T[max]; //m_pItems에 크기가 max인 배열을 만든다.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront;  //멤버 변수들을 초기화시켜준다.
	m_CurPointer = m_nMaxQueue - 1;
	m_Length = 0;
}

template<typename T>
int QList<T>::GetLength() {
	return m_Length; // 현재 큐에 담긴 사이즈를 return
}

template<typename T>
bool QList<T>::IsFull() {
	return !((m_iRear + 1 - m_iFront) % m_nMaxQueue);
	// Rear+1 = Front 일 때, Rear=max-1, Front=0 일 때 return 1 아닐 시 0 return
}

template<typename T>
bool QList<T>::IsEmpty() {
	return (m_iRear == m_iFront);
	// 처음시작 일때 이거나 Front가 Rear로 올 때 1 return 아닐 시 0
}

template<typename T>
void QList<T>::MakeEmpty() {
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; // 생성자와 같은 값으로 멤버 변수를 초기화해준다.
	m_Length = 0;
}

template<typename T>
void QList<T>::EnQueue(T item) {
	if (IsFull()) throw FullQueue(); // isFull일 시 Fullqueue를 throw한다.
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item; //m_iRear를 1 증가시키고 그 index에 item을 넣는다.
	m_Length++;
}

template<typename T>
void QList<T>::DeQueue(T& item) {
	if (IsEmpty()) throw EmptyQueue(); // isEmpty일 시 Emptyqueue를 throw한다.
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront]; //m_iFront를 1 증가시키고 그 index에 item을 넣는다.
	m_Length--;
}

template<typename T>
void QList<T>::Print() {
	if (m_iFront > m_iRear) { //m_iFront가 m_iRear보다 클때
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++) cout << m_pItems[i] << endl;
		//m_iFront 다음 항목부터 배열의 끝까지 출력한다.			
		for (int i = 0; i <= m_iRear; i++) cout << m_pItems[i] << endl;
		//배열의 처음부터 m_iRear까지 출력해준다.

	}

	else { //m_iRear가 m_iFront보다 클때
		for (int i = m_iFront + 1; i <= m_iRear; i++) cout << m_pItems[i] << endl;
		//m_iFront+1에서부터 m_iRear까지 출력
	}
	cout << endl;
}

template<typename T>
void QList<T>::ResetList() {
	delete[] m_pItems; //동적할당했던 메모리를 해제해준다.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; //생성자와 같은 값으로 m_iFront와 m_iRear를 변경해준다.
	m_pItems = new T[m_nMaxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
	m_Length = 0;
}

template<typename T>
void QList<T>::ResetCurrentPointer() {
	m_CurPointer = m_iFront; // 포인터를 m_ifront로 초기화 해준다.
}

template<typename T>
int QList<T>::GetNextItem(T& item) {
	if (IsEmpty()) {
		return -1;
	}

	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	item = m_pItems[m_CurPointer];	//m_iFront에서 1 증가된 index의 m_pItem을 item에 복사해준다.
	if (m_CurPointer == m_iRear) {
		this->ResetCurrentPointer();
		return 0;
	}
	return 1;
}

template<typename T>
int QList<T>::Search(T &item) {
	T CurItem;
	ResetCurrentPointer();
	while (GetNextItem(CurItem)) { // CurItem이 QLIST안에 있을 때
		if (CurItem == item) {
			item = CurItem; //일치하는 Primary key발견되면 item에 복사 후 return 1
			return 1;
		}
	}
	if (CurItem == item) { // QLIST맨 끝에 있을 때
		item = CurItem;
		return 1;
	}
	else return 0; // 찾지 못했을 시 return 0
}


template<typename T>
int QList<T>::Delete(T& item) {
	if (Search(item)) { // Search item을 통해 찾았을 때
		if (m_CurPointer != m_iFront) { // item이 끝이 아닌 중간에 있을 때
			if (m_CurPointer < m_iRear) {
				for (int i = m_CurPointer; i < m_iRear; i++) { // rear보다 발견된 포인터가 작다면 포인터부터 rear 까지 땡긴다.
					m_pItems[i] = m_pItems[i + 1];
				}
				m_iRear = (m_iRear + (m_nMaxQueue - 1)) % m_nMaxQueue; // 하나가 빠지므로 rear도 하나 줄어든다 0일땐 maxqueue-1로 나머지 연산
				m_Length--;
				return 1;
			}
			else {
				int x = m_iRear + m_nMaxQueue;
				for (int i = m_CurPointer; i < x; i++) { // rear보다 발견된 포인터가 rear부터 포인터까지 땡긴다.
					m_pItems[i%m_nMaxQueue] = m_pItems[(i + 1) % m_nMaxQueue]; // 중간에 0이 있으므로 나머지 연산
				}
				m_iRear = (m_iRear + (m_nMaxQueue - 1)) % m_nMaxQueue; // 하나가 빠지므로 rear도 하나 줄어든다 0일땐 maxqueue-1로 나머지 연산
				m_Length--;
				return 1;
			}
		}

		else {
			m_iRear = (m_iRear + (m_nMaxQueue - 1)) % m_nMaxQueue; // 하나가 빠지므로 rear도 하나 줄어든다 0일땐 maxqueue-1로 나머지 연산
			m_Length--;
			return 1;
		}
	}

	return 0;
}

template<typename T>
int QList<T>::Replace(T item) {
	T dummy = item; // dummy로 item복사
	if (IsEmpty()) {
		return -1;
	}

	ResetCurrentPointer();
	while (1) {
		m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
		if (m_pItems[m_CurPointer] == dummy) {
			m_pItems[m_CurPointer] = dummy; // dummy의 primary number와 일치할 시 Queue안에 dummy data삽입
			return 1;
		}
		if (m_CurPointer == m_iRear) break; // 끝에 도달할 시 반복문 탈출
	}
	return 0; // 발견 못했을 시 return 0
}

#endif	// _QLIST_H
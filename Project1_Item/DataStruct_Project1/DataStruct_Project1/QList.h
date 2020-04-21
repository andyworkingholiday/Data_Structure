#include <iostream>
#define maxQueue 6
using namespace std;

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
*	@details	This class processes as First In, First Out (FIFO), ���ø��� ������ �پ��� ���� Ÿ���� ������ �� �ִ�.
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
	*	@post	m_iFront�� m_iRear is set same value as Constructer.
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
	m_pItems = new T[maxQueue]; //m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; //��� �������� �ʱ�ȭ�����ش�.
	m_CurPointer = m_nMaxQueue - 1;
	m_Length = 0;
}

template<typename T>
QList<T>::QList(int max) {
	m_nMaxQueue = max;
	m_pItems = new T[max]; //m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront;  //��� �������� �ʱ�ȭ�����ش�.
	m_CurPointer = m_nMaxQueue - 1;
	m_Length = 0;
}

template<typename T>
QList<T>::~QList() {
	delete[] m_pItems; //�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

// ũ�⸦ �缳���Ѵ�.
template<typename T>
void QList<T>::resize(int max) {
	delete[] m_pItems;
	m_nMaxQueue = max;
	m_pItems = new T[max]; //m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront;  //��� �������� �ʱ�ȭ�����ش�.
	m_CurPointer = m_nMaxQueue - 1;
	m_Length = 0;
}

template<typename T>
int QList<T>::GetLength() {
	return m_Length; // ���� ť�� ��� ����� return
}

template<typename T>
bool QList<T>::IsFull() {
	return !((m_iRear + 1 - m_iFront) % m_nMaxQueue);
	// Rear+1 = Front �� ��, Rear=max-1, Front=0 �� �� return 1 �ƴ� �� 0 return
}

template<typename T>
bool QList<T>::IsEmpty() {
	return (m_iRear == m_iFront);
	// ó������ �϶� �̰ų� Front�� Rear�� �� �� 1 return �ƴ� �� 0
}

template<typename T>
void QList<T>::MakeEmpty() {
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; // �����ڿ� ���� ������ ��� ������ �ʱ�ȭ���ش�.
	m_Length = 0;
}

template<typename T>
void QList<T>::EnQueue(T item) {
	if (IsFull()) throw FullQueue(); // isFull�� �� Fullqueue�� throw�Ѵ�.
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item; //m_iRear�� 1 ������Ű�� �� index�� item�� �ִ´�.
	m_Length++;
}

template<typename T>
void QList<T>::DeQueue(T& item) {
	if (IsEmpty()) throw EmptyQueue(); // isEmpty�� �� Emptyqueue�� throw�Ѵ�.
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront]; //m_iFront�� 1 ������Ű�� �� index�� item�� �ִ´�.
	m_Length--;
}

template<typename T>
void QList<T>::Print() {
	if (m_iFront > m_iRear) { //m_iFront�� m_iRear���� Ŭ��
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++) cout << m_pItems[i] << endl;
		//m_iFront ���� �׸���� �迭�� ������ ����Ѵ�.			
		for (int i = 0; i <= m_iRear; i++) cout << m_pItems[i] << endl;
		//�迭�� ó������ m_iRear���� ������ش�.

	}

	else { //m_iRear�� m_iFront���� Ŭ��
		for (int i = m_iFront + 1; i <= m_iRear; i++) cout << m_pItems[i] << endl;
		//m_iFront+1�������� m_iRear���� ���
	}
	cout << endl;
}

template<typename T>
void QList<T>::ResetList() {
	delete[] m_pItems; //�����Ҵ��ߴ� �޸𸮸� �������ش�.
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; //�����ڿ� ���� ������ m_iFront�� m_iRear�� �������ش�.
	m_pItems = new T[m_nMaxQueue];	//m_pItems�� ũ�Ⱑ maxQueue�� �迭�� �����.
	m_Length = 0;
}

template<typename T>
void QList<T>::ResetCurrentPointer(){
	m_CurPointer = m_iFront; // �����͸� m_ifront�� �ʱ�ȭ ���ش�.
}

template<typename T>
int QList<T>::GetNextItem(T& item){
	if (IsEmpty()) {
		return -1;
	}

	m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
	item = m_pItems[m_CurPointer];	//m_iFront���� 1 ������ index�� m_pItem�� item�� �������ش�.
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
	while (GetNextItem(CurItem)) { // CurItem�� QLIST�ȿ� ���� ��
		if (CurItem == item) { 
			item = CurItem; //��ġ�ϴ� Primary key�߰ߵǸ� item�� ���� �� return 1
			return 1;
		}
	}
	if (CurItem == item) { // QLIST�� ���� ���� ��
		item = CurItem;
		return 1;
	}
	else return 0; // ã�� ������ �� return 0
}


template<typename T>
int QList<T>::Delete(T& item) {
	if (Search(item)) { // Search item�� ���� ã���� ��
		if (m_CurPointer != m_iFront) { // item�� ���� �ƴ� �߰��� ���� ��
			if (m_CurPointer < m_iRear) { 
				for (int i = m_CurPointer; i < m_iRear; i++) { // rear���� �߰ߵ� �����Ͱ� �۴ٸ� �����ͺ��� rear ���� �����.
					m_pItems[i] = m_pItems[i + 1];
				}
				m_iRear = (m_iRear + (m_nMaxQueue - 1)) % m_nMaxQueue; // �ϳ��� �����Ƿ� rear�� �ϳ� �پ��� 0�϶� maxqueue-1�� ������ ����
				m_Length--;
				return 1;
			}
			else {
				int x = m_iRear + m_nMaxQueue;
				for (int i = m_CurPointer; i < x; i++) { // rear���� �߰ߵ� �����Ͱ� rear���� �����ͱ��� �����.
					m_pItems[i%m_nMaxQueue] = m_pItems[(i + 1) % m_nMaxQueue]; // �߰��� 0�� �����Ƿ� ������ ����
				}
				m_iRear = (m_iRear + (m_nMaxQueue - 1)) % m_nMaxQueue; // �ϳ��� �����Ƿ� rear�� �ϳ� �پ��� 0�϶� maxqueue-1�� ������ ����
				m_Length--;
				return 1;
			}
		}

		else {
			m_iRear = (m_iRear + (m_nMaxQueue - 1)) % m_nMaxQueue; // �ϳ��� �����Ƿ� rear�� �ϳ� �پ��� 0�϶� maxqueue-1�� ������ ����
			m_Length--;
			return 1;
		}
	}

	return 0;
}

template<typename T>
int QList<T>::Replace(T item) {
	T dummy = item; // dummy�� item����
	if (IsEmpty()) {
		return -1;
	}

	ResetCurrentPointer();
	while (1) {
		m_CurPointer = (m_CurPointer + 1) % m_nMaxQueue;
		if (m_pItems[m_CurPointer] == dummy) {
			m_pItems[m_CurPointer] = dummy; // dummy�� primary number�� ��ġ�� �� Queue�ȿ� dummy data����
			return 1;
		}
		if (m_CurPointer == m_iRear) break; // ���� ������ �� �ݺ��� Ż��
	}
	return 0; // �߰� ������ �� return 0
}
#include <iostream>
#include "ItemType.h"
#define maxQueue 10
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
class CircularQueueType {
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	CircularQueueType(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueueType();


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

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
};

template<typename T> 
CircularQueueType<T>::CircularQueueType() {
	m_pItems = new T[maxQueue]; //m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_nMaxQueue = maxQueue;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; //��� �������� �ʱ�ȭ�����ش�.
}

template<typename T>
CircularQueueType<T>::CircularQueueType(int max) {
	m_pItems = new T[max]; //m_pItems�� ũ�Ⱑ max�� �迭�� �����.
	m_nMaxQueue = max;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront;  //��� �������� �ʱ�ȭ�����ش�.
}

template<typename T>
CircularQueueType<T>::~CircularQueueType() {
	delete[] m_pItems; //�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

template<typename T>
bool CircularQueueType<T>::IsFull() {
	return !((m_iRear + 1 - m_iFront) % m_nMaxQueue);
	// Rear+1 = Front �� ��, Rear=max-1, Front=0 �� �� return 1 �ƴ� �� 0 return
}

template<typename T>
bool CircularQueueType<T>::IsEmpty() {
	return (m_iRear == m_iFront);
	// ó������ �϶� �̰ų� Front�� Rear�� �� �� 1 return �ƴ� �� 0
}

template<typename T>
void CircularQueueType<T>::MakeEmpty() {
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; // �����ڿ� ���� ������ ��� ������ �ʱ�ȭ���ش�.
}

template<typename T>
void CircularQueueType<T>::EnQueue(T item) {
	if (IsFull()) throw FullQueue(); // isFull�� �� Fullqueue�� throw�Ѵ�.
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item; //m_iRear�� 1 ������Ű�� �� index�� item�� �ִ´�.
}

template<typename T>
void CircularQueueType<T>::DeQueue(T& item) {
	if (IsEmpty()) throw EmptyQueue(); // isEmpty�� �� Emptyqueue�� throw�Ѵ�.
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront]; //m_iFront�� 1 ������Ű�� �� index�� item�� �ִ´�.
}

template<typename T>
void CircularQueueType<T>::Print() {
	cout << "\n\t========= Current List ========" << endl;
	if (m_iFront > m_iRear)	{ //m_iFront�� m_iRear���� Ŭ��
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++) cout << m_pItems[i] << " - ";
		//m_iFront ���� �׸���� �迭�� ������ ����Ѵ�.			
		for (int i = 0; i <= m_iRear; i++) cout << m_pItems[i] << " - "; 
		//�迭�� ó������ m_iRear���� ������ش�.
			
	}

	else { //m_iRear�� m_iFront���� Ŭ��
		for (int i = m_iFront + 1; i <= m_iRear; i++) cout << m_pItems[i] << " - ";
			//m_iFront+1�������� m_iRear���� ���
	}
	cout << endl;
}

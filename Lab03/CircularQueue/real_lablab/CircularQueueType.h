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
*	@details	This class processes as First In, First Out (FIFO), 템플릿을 적용해 다양한 변수 타입을 저장할 수 있다.
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

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
};

template<typename T> 
CircularQueueType<T>::CircularQueueType() {
	m_pItems = new T[maxQueue]; //m_pItems에 크기가 max인 배열을 만든다.
	m_nMaxQueue = maxQueue;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; //멤버 변수들을 초기화시켜준다.
}

template<typename T>
CircularQueueType<T>::CircularQueueType(int max) {
	m_pItems = new T[max]; //m_pItems에 크기가 max인 배열을 만든다.
	m_nMaxQueue = max;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront;  //멤버 변수들을 초기화시켜준다.
}

template<typename T>
CircularQueueType<T>::~CircularQueueType() {
	delete[] m_pItems; //동적할당했던 메모리를 해제해준다.
}

template<typename T>
bool CircularQueueType<T>::IsFull() {
	return !((m_iRear + 1 - m_iFront) % m_nMaxQueue);
	// Rear+1 = Front 일 때, Rear=max-1, Front=0 일 때 return 1 아닐 시 0 return
}

template<typename T>
bool CircularQueueType<T>::IsEmpty() {
	return (m_iRear == m_iFront);
	// 처음시작 일때 이거나 Front가 Rear로 올 때 1 return 아닐 시 0
}

template<typename T>
void CircularQueueType<T>::MakeEmpty() {
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_iFront; // 생성자와 같은 값으로 멤버 변수를 초기화해준다.
}

template<typename T>
void CircularQueueType<T>::EnQueue(T item) {
	if (IsFull()) throw FullQueue(); // isFull일 시 Fullqueue를 throw한다.
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item; //m_iRear를 1 증가시키고 그 index에 item을 넣는다.
}

template<typename T>
void CircularQueueType<T>::DeQueue(T& item) {
	if (IsEmpty()) throw EmptyQueue(); // isEmpty일 시 Emptyqueue를 throw한다.
	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront]; //m_iFront를 1 증가시키고 그 index에 item을 넣는다.
}

template<typename T>
void CircularQueueType<T>::Print() {
	cout << "\n\t========= Current List ========" << endl;
	if (m_iFront > m_iRear)	{ //m_iFront가 m_iRear보다 클때
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++) cout << m_pItems[i] << " - ";
		//m_iFront 다음 항목부터 배열의 끝까지 출력한다.			
		for (int i = 0; i <= m_iRear; i++) cout << m_pItems[i] << " - "; 
		//배열의 처음부터 m_iRear까지 출력해준다.
			
	}

	else { //m_iRear가 m_iFront보다 클때
		for (int i = m_iFront + 1; i <= m_iRear; i++) cout << m_pItems[i] << " - ";
			//m_iFront+1에서부터 m_iRear까지 출력
	}
	cout << endl;
}

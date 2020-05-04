#ifndef _STACK_H
#define _STACK_H

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/

class FullStack {
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print() {
		cout << "FullStack exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyStack {
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print() {
		cout << "EmtpyStack exception thrown." << endl;
	}
};

/**
*	@brief	Stack class.
*	@details	This class processes as Last In, First Out (LIFO), 템플릿을 적용해 다양한 변수 타입을 저장할 수 있다.
*/
template <typename T>
class Stack {

public:
	/**
	*	@brief	Allocate dynamic array whose size is maxStack.
	*	@pre	The maxStack is defined
	*	@post	Member of items points the allocated array.
	*/
	Stack();

	/**
*	@brief	Allocate dynamic array whose size is max.
*	@pre	none.
*	@post	Member of items points the allocated array.
*/
	Stack(int max);

	/**
*	@brief	Destruct the object. Free the array dynamically allocated.
*	@pre	Release memory for queue pointer.
*	@post	none.
*/
	~Stack();

	/**
	*	@brief	resize the stack
	*	@pre	none.
	*	@post	stack resized
	*/
	void resize(int max);

	/**
	*	@brief	Determines whether the stack is full.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is full)
	*/
	bool IsFull() const;

	/**
	*	@brief	Determines whether the stack is empty.
	*	@pre	Stack has been initialized.
	*	@post	Function value = (stack is empty)
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Adds newItem to the top of the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is full), FullStack exception is thrown; otherwise, newItem is at the top of the stack.
	*/
	void Push(T item);

	/**
	*	@brief	Removes top item from the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	void Pop(T& item);

	/**
	*	@brief	Returns a copy of top item on the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, copy the element of top.
	*/
	void Top(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();

	/**
	*	@brief	Get a number of records in Stack.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current Stack.
	*/
	int GetLength();

	/**
	*	@brief	Reset Stack
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void ResetList();

	/**
	*	@brief	Reset m_CurPointer.
	*	@pre	none.
	*	@post	m_CurPointer가 m_iFront 값으로 초기화된다.
	*/
	void ResetCurrentPointer();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& item);

	/**
	*	@brief	move list iterator to the next item and search the data
	*	@pre	Stack has been initialized.
	*	@post	search item
	*	@param	data	the data want to find it does not need to be initialized.
	*	@return	if find the item return 1,  oterwise return 0.
	*/
	int Search(T& item);

	/**
	*	@brief	move list iterator to the next item and Delete the data
	*	@pre	Stack has been initialized.
	*	@post	search item
	*	@param	data	the data want to delete it does not need to be initialized.
	*	@return	if delete the item return 1,  oterwise return 0.
	*/
	int Delete(T& item);

	/**
	*	@brief	move list iterator to the next item and Replace the data
	*	@pre	Stack has been initialized.
	*	@post	search item
	*	@param	data	the data want to Replace it has to be initialized.
	*	@return	if Replace the item return 1,  oterwise return 0.
	*/
	int Replace(T item);

private:
	int m_iTop;			// Number of elements.
	int m_nMaxStack;	// max size of the stack.
	int m_CurPointer;	// iterator pointer.
	T* m_pItems;		// Stack List
};

// Allocate dynamic array whose size is maxStack.
template<typename T>
Stack<T>::Stack() {
	m_nMaxStack = maxStack;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
	m_CurPointer = -1;
}

// Allocate dynamic array whose size is max.
template<typename T>
Stack<T>::Stack(int max) {
	m_nMaxStack = max;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
}

// Destruct the object. Free the array dynamically allocated.
template<typename T>
Stack<T>::~Stack() {
	delete[] m_pItems;
}

//크기를 재설정 합니다.
template<typename T>
void Stack<T>::resize(int max) {
	delete[] m_pItems;
	m_nMaxStack = max;
	m_pItems = new T[m_nMaxStack];
	m_iTop = -1;
}

// Determines whether the stack is full.
template<typename T>
bool Stack<T>::IsFull() const {
	return (m_iTop == m_nMaxStack - 1);
}

// Determines whether the stack is empty.
template<typename T>
bool Stack<T>::IsEmpty() const {
	return (m_iTop == -1);
}

// Adds newItem to the top of the stack.
template<typename T>
void Stack<T>::Push(T item) {
	if (IsFull()) throw FullStack();
	else {
		m_iTop++;
		m_pItems[m_iTop] = item;
	}
}

// Removes top item from the stack.
template<typename T>
void Stack<T>::Pop(T& item) {
	if (IsEmpty()) throw EmptyStack();
	else {
		item = m_pItems[m_iTop];
		m_iTop--;
	}
}

// Gets top item from the stack.
template<typename T>
void Stack<T>::Top(T& item) {
	if (IsEmpty())throw EmptyStack();
	else item = m_pItems[m_iTop];
}

// Print all the items in the stack on screen
template<typename T>
void Stack<T>::Print() {
	// Stack 내의 모든 element 출력.
	for (int i = m_iTop; i >= 0; i--) {
		cout << m_pItems[i] << endl;
	}
	cout << endl;
}

template<typename T>
int Stack<T>::GetLength() {
	return (m_iTop + 1);
}

template<typename T>
void Stack<T>::ResetList() {
	delete[] m_pItems; //동적할당했던 메모리를 해제해준다.
	m_iTop = -1; //생성자와 같은 값으로 m_iTop를 변경해준다.
	m_CurPointer = -1;
	m_pItems = new T[m_nMaxStack];	//m_pItems에 크기가 maxStack인 배열을 만든다.
}

template<typename T>
void Stack<T>::ResetCurrentPointer() {
	m_CurPointer = -1; // 포인터를 -1로 초기화 해준다.
}

template<typename T>
int Stack<T>::GetNextItem(T& item) {
	m_CurPointer++;
	if (m_CurPointer == m_iTop + 1)
		return -1;
	item = m_pItems[m_CurPointer]; //m_CurPointer에서 1 증가된 index의 m_pItem을 item에 복사해준다.

	return m_CurPointer;
}

template<typename T>
int Stack<T>::Search(T& item) {
	T CurItem;
	ResetCurrentPointer();
	while (GetNextItem(CurItem) >= 0) { // CurItem이 Stack안에 있을 때
		if (CurItem == item) {
			item = CurItem; //일치하는 Primary key발견되면 item에 복사 후 return 1
			return 1;
		}
	}
	return 0; // 발견 못하면 return 0
}

template<typename T>
int Stack<T>::Delete(T& item) {
	if (Search(item)) { //Search를 통해 Primary key일치하는 item 찾았을 시
		if (m_CurPointer != m_iTop) { //Stack의 맨위에 있는게 아니라면
			for (int i = m_CurPointer; i < m_iTop; i++) {
				m_pItems[i] = m_pItems[i + 1]; // 찾은 값부터 맨위까지의 data를 한칸 씩 땡긴다.
			}
			m_iTop--; // 총 갯수 줄이고 return 1
			return 1;
		}
		else {
			m_iTop--; // 맨 위에서 삭제할 땐 땡길 필요 없이 return 1
			return 1;
		}
	}
	else return 0; //못찾을시 return 0
}

template<typename T>
int Stack<T>::Replace(T item) {
	T dummy = item; // dummy로 item복사
	if (IsEmpty()) {
		return -1;
	}

	ResetCurrentPointer();
	while (1) {
		m_CurPointer++;
		if (m_pItems[m_CurPointer] == dummy) {
			m_pItems[m_CurPointer] = dummy; // dummy의 primary number와 일치할 시 Stack안에 dummy data삽입
			return 1;
		}
		if (m_CurPointer == m_iTop) break; // 끝에 도달할 시 반복문 탈출
	}
	return 0;
}

#endif	// _STACK_H
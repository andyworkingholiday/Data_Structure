#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� data��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� data��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T& data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� data��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
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
	ResetList(); //��� �������� �ʱ�ȭ�����ش�.
	m_Array = new T[m_Maxsize]; //m_Array�� ũ�Ⱑ MAXSIZE�� �迭�� �����.
}

template<typename T>
UnsortedList<T>::UnsortedList(int max) {
	m_Maxsize = max; // parameter�� ���� max ������ maxsize�� �����Ѵ�.
	m_Length = 0;
	ResetList(); //��� �������� �ʱ�ȭ�����ش�.
	m_Array = new T[m_Maxsize];  //m_Array�� ũ�Ⱑ max�� �迭�� �����.
}

template<typename T>
UnsortedList<T>::~UnsortedList() {
	delete[] m_Array; //�����Ҵ��ߴ� �޸𸮸� �������ش�.
}

// ũ�⸦ �缳�� �մϴ�.
template<typename T>
void UnsortedList<T>::resize(int max) {
	delete[] m_Array;
	m_Maxsize = max; // parameter�� ���� max ������ maxsize�� �缳���Ѵ�.
	m_Length = 0;
	ResetList(); //��� �������� �ٽ� �ʱ�ȭ�����ش�.
	m_Array = new T[m_Maxsize];  //m_Array�� ũ�Ⱑ max�� �迭�� ���� �����.
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

// List�� MAXSIZE ��ŭ ä�������� �� true, �ƴ� �� false
template<typename T>
bool UnsortedList<T>::IsFull() {
	if (m_Length == MAXSIZE) {
		printf("\tList is Full!\n");
		return true;
	}
	return false;
}

// List�� �ƿ� ��������� �� true, �ƴ� �� false
template<typename T>
bool UnsortedList<T>::IsEmpty() {
	if (!m_Length) {
		return true;
	}
	return false;
}

// List�� ���������� Item �߰� ������ primary key�� ������ �߰��� ���Ѵ�.
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

// �˻� Iterator��  �ʱ�ȭ
template<typename T>
void UnsortedList<T>::ResetList() {
	m_CurPointer = -1;
}

// Pointer�� ��ġ�� �� ĭ �̵��Ͽ� �� ���� �ε����� ��ȯ�Ѵ�.
// �׸��� �Լ��� parameter�� data���� �� �ε����� ������ ����ȴ�.
// ���� List�� Full �� �� -1�� ��ȯ�Ѵ�.
template<typename T>
int UnsortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) return -1;
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}

// parameter data�� primary key�� ��ġ�ϴ� ���� �ִ��� List�� ó������ ���������� ���鼭 Ȯ���Ѵ�.
// ���� ���� �׶��� index�� ��ȯ�ϰ� ���� �� -1�� ��ȯ�Ѵ�.
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

// parameter data�� primary key�� ��ġ�ϴ� ���� �ִ��� List�� ó������ ���������� ���鼭 Ȯ���Ѵ�.
// ���� ���� �� list�� data�� �����ϰ� �ڿ� �ִ� data���� ��ĭ ������ �����.
// ���� �� 0�� ��ȯ�Ѵ�.
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

// parameter data�� primary key�� ��ġ�ϴ� ���� �ִ��� List�� ó������ ���������� ���鼭 Ȯ���Ѵ�.
// ���� �� �Լ��� parameter data�� List �ش� �ε����� ��ü��Ų��.
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
	int len = GetLength(); // ����Ʈ�� ��� �������� ����
	while (len--) { // �������� ������ŭ data ���
		if (GetNextItem(item) >= 0)
			cout << item << endl;
	}
}

// Print all the strings in the stack on screen
template<typename T>
void UnsortedList<T>::Printstring() {
	ResetList();
	T item;
	int len = GetLength(); // ����Ʈ�� ��� �������� ����
	while (len--) { // �������� ������ŭ data ���
		if (GetNextItem(item) >= 0)
			cout << "\t" << item << endl;
	}
}
#endif	// _UNSORTEDLIST_H
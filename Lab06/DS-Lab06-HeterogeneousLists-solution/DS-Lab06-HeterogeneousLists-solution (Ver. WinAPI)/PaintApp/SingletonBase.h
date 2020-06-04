#pragma once
//=====================================================
//		## SingletonBase ## (�� ���̽��� �̱����� �����)
//=====================================================

template <typename T>
class SingletonBase
{
protected:
	//�̱��� �ν��Ͻ� ����
	static T* singleton;

	SingletonBase() {};
	~SingletonBase() {};

public:
	//�̱��� ��ü ��������
	static T* getSingleton();
	//�̱��� ��ü �޸𸮿��� �����ϱ�
	void releaseSingleton();
};

//�̱��� �ν��Ͻ� ����
template <typename T>
T* SingletonBase<T>::singleton = 0;

//�̱��� ��ü ��������
template <typename T>
T* SingletonBase<T>::getSingleton()
{
	//�̱��� ��ü�� ������ ���� �����ϱ�
	if (!singleton) singleton = new T;

	return singleton;
}

//�̱��� ��ü �޸𸮿��� �����ϱ�
template <typename T>
void SingletonBase<T>::releaseSingleton()
{
	//�̱��� ��ü�� �ִٸ� �޸𸮿��� ����
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}

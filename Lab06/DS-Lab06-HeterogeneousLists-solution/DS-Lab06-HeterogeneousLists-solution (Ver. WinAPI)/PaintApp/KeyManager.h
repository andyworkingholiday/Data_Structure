#pragma once
#include "SingletonBase.h"
#include <bitset>

using namespace std;
//=====================================================
//		## KeyManager ## (Ű �Ŵ���)
//=====================================================

#define KEYMAX 256

class KeyManager : public SingletonBase <KeyManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	KeyManager();
	~KeyManager();

	HRESULT init();
	void release();

	//Ű�� �ѹ��� ���ǳ�?
	bool isOnceKeyDown(int key);
	//Ű�� �ѹ� ������ �����?
	bool isOnceKeyUp(int key);
	//Ű�� ��� �����ֳ�?
	bool isStayKeyDown(int key);
	//���Ű��?(ĸ����,�ѹ���)
	bool isToggleKey(int key);
};
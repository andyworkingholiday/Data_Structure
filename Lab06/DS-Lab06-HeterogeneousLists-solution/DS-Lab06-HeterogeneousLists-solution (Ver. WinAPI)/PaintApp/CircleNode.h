#pragma once
#include "BaseNode.h"
/**
*	@brief	���׶�� ���� Class
*	@author	������
*/
class CircleNode : public BaseNode
{
private:
	float radius;
	POINT center;

public:
	CircleNode(POINT center, int size, bool isEmpty, COLORREF color);
	~CircleNode();

	void update();
	void display(HDC hdc);
};
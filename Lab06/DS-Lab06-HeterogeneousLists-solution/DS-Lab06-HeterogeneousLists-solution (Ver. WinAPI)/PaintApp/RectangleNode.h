#pragma once
#include "BaseNode.h"
/**
*	@brief	���簢�� Class
*	@author	������
*/
class RectangleNode : public BaseNode
{
private:
	POINT pt[2];

public:
	RectangleNode();
	RectangleNode(POINT pt, int size, bool isEmpty, COLORREF color);
	~RectangleNode();

	void update();
	void display(HDC hdc);
};
#pragma once
#include "BaseNode.h"
/**
*	@brief	�ٰ��� Class
*	@author	������
*/
#define MAXPOLYPOINTS 500
class PolygonNode : public BaseNode
{
private:
	POINT vertex[MAXPOLYPOINTS];
	int curIndex;

public:
	PolygonNode(int size, bool isEmpty, COLORREF color);
	~PolygonNode();

	void update();
	void display(HDC hdc);
};


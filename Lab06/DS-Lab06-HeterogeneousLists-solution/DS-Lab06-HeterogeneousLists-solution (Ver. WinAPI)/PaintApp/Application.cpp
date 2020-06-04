#include "stdafx.h"


Application::Application()
{
	srand(time(NULL));
	color = 0x000000;
	penSize = 1;
	isEmpty = false;
}


Application::~Application()
{
}

HRESULT Application::Init()
{
	AppBase::Init();
	shape = NONE;
	draw = IDLE;
	return S_OK;
}

void Application::Release()
{
	AppBase::Release();
}

void Application::Update()
{
	AppBase::Update();
	list.UpdateLast();

	if (KEYMANAGER->isOnceKeyDown('K')) {
		penSize -= 1;
		if (penSize < 1) penSize = 1;
	}
	if (KEYMANAGER->isOnceKeyDown('L')) {
		penSize += 1;
		if (penSize > 10) penSize = 10;
	}

	if (KEYMANAGER->isOnceKeyDown('P')) {
		int randRGB[3];
		for (int i = 0; i < 3; ++i) randRGB[i] = rand() % 256;
		color = RGB(randRGB[0], randRGB[1], randRGB[2]);
	}
	if (KEYMANAGER->isOnceKeyDown('O')) {
		isEmpty = !isEmpty;
	}
	
	if (draw == IDLE) {
		if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
			if (shape == POLYGON) shape = NONE;
			else shape = (eShapeState)((int)shape + 1);
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			switch (shape)
			{
			case NONE:
				break;
			case RECTANGLE: {
				RectangleNode * newNode = new RectangleNode(GetMousePos(), penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			case CIRCLE: {
				CircleNode * newNode = new CircleNode(GetMousePos(), penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			case CIRCLE_PASSIVE: {
				CircleNode * newNode = new CircleNode(GetMousePos(), penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			case POLYGON: {
				PolygonNode* newNode = new PolygonNode(penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			}
		}
	}
}

void Application::Render(HDC hdc)
{
	list.DisplayAll(hdc);

	string mode;
	mode = "���� ����: ";
	switch (shape)
	{
	case NONE:
		mode += "NONE";
		break;
	case RECTANGLE:
		mode += "RECTANGLE";
		break;
	case CIRCLE:
		mode += "CIRCLE";
		break;
	case CIRCLE_PASSIVE:
		mode += "CIRCLE_PASSIVE";
		break;
	case POLYGON:
		mode += "POLYGON";
		break;
	}
	TextOutA(hdc, 10, 10, mode.c_str(), strlen(mode.c_str()));

	string HowTo;
	HowTo = "!����! Tab: ��������, K: ����������̱�, L: �������Ű���, P: �� ����(����), O: �� ä��� Toggle";
	TextOutA(hdc, 210, 10, HowTo.c_str(), strlen(HowTo.c_str()));
	HowTo = "�ٰ����� �׸� �ÿ� �������� ��Ŭ������ ������ �� �� �ֽ��ϴ�.";
	TextOutA(hdc, 210, 30, HowTo.c_str(), strlen(HowTo.c_str()));
}

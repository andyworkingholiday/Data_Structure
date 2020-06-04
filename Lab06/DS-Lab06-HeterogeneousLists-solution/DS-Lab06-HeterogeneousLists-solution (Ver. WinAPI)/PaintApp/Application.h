#pragma once
#include "AppBase.h"

class Application : public AppBase
{
private:
	HeterogeneousList list;		//���� List

	COLORREF	color;			//��
	int			penSize;		//�� ������
	bool		isEmpty;		//ä���� �׸� ������ �Ǵ�

public:
	Application();
	~Application();

	HRESULT Init();				//App�� ����
	void Release();				//App�� ������ ��
	void Update();
	void Render(HDC hdc);
};

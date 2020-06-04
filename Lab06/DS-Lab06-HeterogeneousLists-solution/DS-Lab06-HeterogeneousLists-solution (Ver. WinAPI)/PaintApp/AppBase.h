#pragma once
//=====================================================
//		## AppBase ## (�� ���̽��� ���� �����)
//=====================================================
class AppBase
{
public:
	AppBase();
	virtual ~AppBase();

	//�ʱ�ȭ
	virtual HRESULT Init();
	//����
	virtual void Release();
	//������Ʈ
	virtual void Update();
	//�׸���
	virtual void Render(HDC hdc);

	//WndProc
	LRESULT MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
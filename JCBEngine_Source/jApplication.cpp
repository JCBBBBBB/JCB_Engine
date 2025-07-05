#include "jApplication.h"

namespace JCB
{
	Application::Application()
		: mHWnd(nullptr),
		  mHdc(nullptr),
		  mX(0),
		  mY(0)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd)
	{
		mHWnd = hwnd; // �޾ƿ� �ڵ��� ��������� �ִ´�
		mHdc = GetDC(mHWnd); // ��� �ڵ��� ��� DC�� �ִ´�
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		HBRUSH blueBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255)); // ���귯�� ����
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush); // �� �귯�� �־���� ���� ���귯���� ����

		HPEN greenPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); // greenPen ����
		HPEN oldPen = (HPEN)SelectObject(mHdc, greenPen); // �� �귯�� �־���� ���� greenPen���� ����

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); // �簢�� ����

		SelectObject(mHdc, oldBrush);
		SelectObject(mHdc, oldPen);

		DeleteObject(blueBrush);
		DeleteObject(greenPen);
	}
}
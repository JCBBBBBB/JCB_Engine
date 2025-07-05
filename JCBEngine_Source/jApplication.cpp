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
		mHWnd = hwnd; // 받아온 핸들을 멤버변수에 넣는다
		mHdc = GetDC(mHWnd); // 멤버 핸들을 멤버 DC에 넣는다
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
		HBRUSH blueBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255)); // 블루브러쉬 생성
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush); // 전 브러쉬 넣어놓고 현재 블루브러쉬로 변경

		HPEN greenPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); // greenPen 생성
		HPEN oldPen = (HPEN)SelectObject(mHdc, greenPen); // 전 브러쉬 넣어놓고 현재 greenPen으로 변경

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY); // 사각형 생성

		SelectObject(mHdc, oldBrush);
		SelectObject(mHdc, oldPen);

		DeleteObject(blueBrush);
		DeleteObject(greenPen);
	}
}
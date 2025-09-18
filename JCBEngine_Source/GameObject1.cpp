#include "GameObject1.h"

namespace JCB
{
	GameObject1::GameObject1() : mX(0), mY(0)
	{

	}

	GameObject1::~GameObject1()
	{

	}

	void GameObject1::Update()
	{ 
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}

		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
	}

	void GameObject1::LateUpdate()
	{

	}

	void GameObject1::Render(HDC hdc)
	{
		HBRUSH blueBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255)); // 喉风宏矾浆 积己

		HPEN greenPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0)); // greenPen 积己


		Ellipse(hdc, 400 + mX, 400 + mY, 500 + mX, 500 + mY);

		SelectObject(hdc, blueBrush);
		SelectObject(hdc, greenPen);

		DeleteObject(blueBrush);
		DeleteObject(greenPen);
	}
}
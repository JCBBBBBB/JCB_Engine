#include "GameObject.h"
#include "Input.h"
#include "DeltaTime.h"

namespace JCB
{
	GameObject::GameObject() : mX(0), mY(0)
	{

	}


	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		float speed = 100.0f;

		if(Input::GetKey(KeyCode::A))
		{
			mX -= speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(KeyCode::D))
		{
			mX += speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(KeyCode::W))
		{
			mY -= speed * Time::GetDeltaTime();
		}

		if (Input::GetKey(KeyCode::S))
		{
			mY += speed * Time::GetDeltaTime();
		}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	mY -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	mY += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	mX -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	mX += 0.01f;
		//}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0)); // 喉风宏矾浆 积己

		HPEN bluePen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0 , 255)); // greenPen 积己


		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, redBrush);
		SelectObject(hdc, bluePen);

		DeleteObject(redBrush);
		DeleteObject(bluePen);
	}
}
#pragma once
#include "pch.h"

namespace JCB
{
	class GameObject1
	{
	public:
		GameObject1();

		~GameObject1();

		void SetPos(int x, int y)
		{
			mX = x;
			mY = y;
		}

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		float mX, mY;
	};
}

#pragma once
#include "pch.h"

namespace JCB
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPos(float x, float y)
		{
			mX = x;
			mY = y;
		}

	private:
		float mX, mY;
	};
}
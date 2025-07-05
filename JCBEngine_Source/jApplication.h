#pragma once

#include "pch.h"

namespace JCB
{
	class Application
	{
	public:
		Application();
		~Application();

		void Init(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHWnd;
		HDC mHdc;
		float mX,mY;
	};
}

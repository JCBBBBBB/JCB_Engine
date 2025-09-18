#pragma once

#include "pch.h"
#include "GameObject.h"
#include "GameObject1.h"

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
		
		GameObject mPlayer;
		GameObject1 mPlayer1;
	};
}

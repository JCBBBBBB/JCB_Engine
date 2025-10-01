#pragma once

#include "pch.h"
#include "GameObject.h"


namespace JCB
{
	class Application
	{
	public:
		Application();
		~Application();

		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void InitializeEtc();

		void Init(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHWnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBuffer;

		GameObject mPlayer;

		float mWidth;
		float mHeight;
	};
}

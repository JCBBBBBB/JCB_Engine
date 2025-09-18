#include "jApplication.h"

namespace JCB
{
	Application::Application()
		: mHWnd(nullptr),
		  mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd) // 핸들은 포인터
	{
		mHWnd = hwnd;
		mHdc = GetDC(mHWnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() // 로직 업데이트 하는거
	{
		mPlayer.Update();
		mPlayer1.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render() // 그려주는 거
	{
		mPlayer.Render(mHdc);
		mPlayer1.Render(mHdc);
	}
}
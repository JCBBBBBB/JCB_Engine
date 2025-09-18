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

	void Application::Init(HWND hwnd) // �ڵ��� ������
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

	void Application::Update() // ���� ������Ʈ �ϴ°�
	{
		mPlayer.Update();
		mPlayer1.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render() // �׷��ִ� ��
	{
		mPlayer.Render(mHdc);
		mPlayer1.Render(mHdc);
	}
}
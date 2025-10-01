#include "jApplication.h"
#include "Input.h"
#include "DeltaTime.h"
#include "SceneManager.h"

namespace JCB
{
	Application::Application()
		: mHWnd(nullptr), mHdc(nullptr), mBackHdc(nullptr), mBackBuffer(NULL), mWidth(0), mHeight(0)
	{

	}

	Application::~Application()
	{

	}


	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHWnd = hwnd;
		mHdc = GetDC(mHWnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHWnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHWnd, true);
	}
	
	void Application::CreateBuffer(UINT width, UINT height)
	{
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼 담당할 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 기존 원본버퍼 지워주고 새로 생성한 백버퍼로 교체
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::InitializeEtc()
	{
		
	}

	void Application::Init(HWND hwnd, UINT width, UINT height) // 핸들은 포인터
	{
		adjustWindowRect(hwnd, width, height);
		CreateBuffer(width, height);

		Input::Init();
		Time::Init();
		SceneManager::Init();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() // 로직 업데이트 하는거
	{
		Input::Update();
		Time::Update();
		mPlayer.Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render() // 그려주는 거
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		
		// 백버퍼에 있는 것을 원본 버퍼에 그려준다
		copyRenderTarget(mHdc, mBackHdc);

	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
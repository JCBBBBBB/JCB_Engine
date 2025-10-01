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

		// ����� ����� DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ���� �������� �����ְ� ���� ������ ����۷� ��ü
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::InitializeEtc()
	{
		
	}

	void Application::Init(HWND hwnd, UINT width, UINT height) // �ڵ��� ������
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

	void Application::Update() // ���� ������Ʈ �ϴ°�
	{
		Input::Update();
		Time::Update();
		mPlayer.Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render() // �׷��ִ� ��
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		
		// ����ۿ� �ִ� ���� ���� ���ۿ� �׷��ش�
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
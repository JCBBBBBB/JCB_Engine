#pragma once
#include "pch.h"

namespace JCB
{
	class Time
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC hdc);
		static float GetDeltaTime() { return DeltaTime; }

	private:
		static LARGE_INTEGER CpuFrequency; // cpu 고유진동수
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTime;
	};

}
#pragma once
#include "pch.h"

namespace JCB
{
	enum class KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		LEFT, RIGHT, DOWN, UP,
		End,
	};

	enum class KeyState
	{
		None,
		Pressed,
		Down,
		Up,
	};

	class Input
	{
	public:
		struct Key
		{
			KeyCode keyCode;
			KeyState state;
			bool isPressed;
		};

		Input() {};
		~Input() {};

		static void Init();
		static void Update();


		static bool GetKeyDown(KeyCode code) { return Keys[(UINT)code].state == KeyState::Down; }
		static bool GetKeyUp(KeyCode code) { return Keys[(UINT)code].state == KeyState::Up; }
		static bool GetKey(KeyCode code) { return Keys[(UINT)code].state == KeyState::Pressed; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);

		static bool isKeyDown(KeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Key& key);

	private:
		static std::vector<Key> Keys;
	};
}
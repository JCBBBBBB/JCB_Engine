#include "Input.h"

namespace JCB
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)KeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Init()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)KeyCode::End; i++)
		{
			Key key = {};
			key.isPressed = false;
			key.keyCode = (KeyCode)i;
			key.state = KeyState::None;

			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(), [](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}

	bool Input::isKeyDown(KeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.isPressed == true)
		{
			key.state = KeyState::Pressed;
		}
		else
		{
			key.state = KeyState::Down;
		}

		key.isPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.isPressed == true)
		{
			key.state = KeyState::Down;
		}
		else
		{
			key.state = KeyState::None;
		}

		key.isPressed = false;
	}
		
}

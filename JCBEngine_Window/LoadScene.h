#pragma once
#include "..\\JCBEngine_Source\\SceneManager.h"
#include "PlayScene.h"

namespace JCB
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}
#pragma once
#include "pch.h"
#include "Scene.h"

namespace JCB
{
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Init();

			mScene.insert(std::make_pair(name, scene));
		}

		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}
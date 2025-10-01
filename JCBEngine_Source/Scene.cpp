#include "Scene.h"

namespace JCB
{
	Scene::Scene() : mGameObjects{}
	{
	}
	Scene::~Scene()
	{
	}

	void Scene::Init()
	{

	}

	void Scene::Update()
	{
		for (GameObject* go : mGameObjects)
		{
			go->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* go : mGameObjects)
		{
			go->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* go : mGameObjects)
		{
			go->Render(hdc);
		}
	}
}

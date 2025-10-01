#pragma once
#include "pch.h"
#include "Entity.h"
#include "GameObject.h"

namespace JCB
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Init();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}


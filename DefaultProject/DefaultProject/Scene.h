#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

namespace wg
{
	class GameObject;

	class Scene
	{
	public:
		explicit Scene();
		~Scene();
		virtual void Update(float elapsedSec);
		virtual void Draw(RenderWindow* pWindow);
		void AddChild(GameObject* child);
		void RootUpdate(float elapsedSec);
		void RootDraw(RenderWindow* pWindow);
	protected:
		vector<GameObject*> m_pGameObjects;

	private:


	};
}




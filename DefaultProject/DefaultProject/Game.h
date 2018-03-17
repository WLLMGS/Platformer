#pragma once
#include "SFML/Graphics.hpp"
#include "LevelLoader.h"

class Entity;

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	//functions
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();

	
	//members
	RenderWindow* m_pWindow = nullptr;

	//entity
	Entity* m_pPlayerDemo = nullptr;

	LevelLoader m_LevelLoader;
};


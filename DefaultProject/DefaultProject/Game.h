#pragma once
#include "SFML/Graphics.hpp"

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
	Entity* m_pGround = nullptr;
	Entity* m_pPlayerDemo = nullptr;
};


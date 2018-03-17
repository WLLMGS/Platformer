
#include "Game.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "WorldManager.h"
#include "Entity.h"
#include "Player.h"


using namespace std;
using namespace sf;

Game::Game() 
{
	m_pWindow = new RenderWindow(VideoMode(1920, 1080), "Default Project");

	//m_pWindow->setVerticalSyncEnabled(true);

	//create ground
	m_pPlayerDemo = new Player(32, { 100, 0 });

	//level loader test
	
	m_LevelLoader.LoadLevel("Resources/Levels/test.csv");
}

Game::~Game()
{
	delete m_pPlayerDemo;
	m_pPlayerDemo = nullptr;
}

void Game::Run()
{
	Clock clock;
	float deltaTime{};
	
	while (m_pWindow->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
		Draw();
	}
}

void Game::ProcessEvents()
{
	Event event{};
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == Event::Closed) m_pWindow->close();
	}
}
void Game::Update(float deltaTime)
{
	//testing contacts
	//for (b2Contact* c = m_pWorld->GetContactList(); c; c->GetNext())
	//{
	//	int uid = int(c->GetFixtureB()->GetBody()->GetUserData());

	//	if(uid == 12)
	//	{
	//		
	//		break;
	//	}
	//	else if (uid == 13)
	//	{
	//		c->GetFixtureB()->GetBody()->SetActive(false);
	//		//apply force to other obj later
	//		break;
	//	}
	//	break;
	//}


	//update world
	WorldManager::GetInstance().GetWorld()->Step(deltaTime, 20, 20);

	m_pPlayerDemo->Update(deltaTime);

	for(Entity* p : m_LevelLoader.m_pEntities)
	{
		p->Update(deltaTime);
	}
}

void Game::Draw()
{
	m_pWindow->clear();
	m_pPlayerDemo->Draw(m_pWindow);
	for (Entity* p : m_LevelLoader.m_pEntities)
	{
		p->Draw(m_pWindow);
	}
	m_pWindow->display();
}
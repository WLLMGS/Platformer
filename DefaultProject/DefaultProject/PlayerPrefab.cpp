#include "PlayerPrefab.h"
#include "RectangleComponent.h"
#include <iostream>

PlayerPrefab::PlayerPrefab(const Vector2f& startPos) :
GameObject(false)
{
	AddComponent(new RectangleComponent());

	GetTransform()->Translate(startPos.x, startPos.y);
}

void PlayerPrefab::Update(float elapsedSec)
{
	float dx{};
	if(Keyboard::isKeyPressed(Keyboard::D))
	{
		dx = 500.f * elapsedSec;
	}
	if(Keyboard::isKeyPressed(Keyboard::Q))
	{
		dx = -500.f * elapsedSec;
	}

	GetTransform()->Translate(dx, 0.f);
}

void PlayerPrefab::Draw(sf::RenderWindow* pWindow)
{
}



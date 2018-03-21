#pragma once
#include "GameObject.h"

class PlayerPrefab : public wg::GameObject
{
public:
	PlayerPrefab(const Vector2f& startPos);
	~PlayerPrefab() = default;
protected:
	virtual void Update(float elapsedSec) override;
	virtual void Draw(sf::RenderWindow* pWindow) override;

};


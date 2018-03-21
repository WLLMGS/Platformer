#include "TestScene.h"
#include "GameObject.h"
#include "RectangleComponent.h"
#include "RigidBodyComponent.h"
#include "WorldManager.h"
#include "PlayerPrefab.h"
#include "TilePrefab.h"
#include "LevelLoader.h"

TestScene::TestScene()
{
	auto player = new PlayerPrefab({ 500, 500 });
	AddChild(player);

	
	LevelLoader loader{};
	loader.LoadLevel("Resources/Levels/test.csv", this);

}


TestScene::~TestScene()
{
}

void TestScene::Update(float elapsedSec)
{
	WorldManager::GetInstance().GetWorld()->Step(elapsedSec, 10, 10);
	
}

void TestScene::Draw(RenderWindow* pWindow)
{

}

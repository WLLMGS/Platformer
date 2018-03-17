#pragma once
#include <string>
#include "Entity.h"

class LevelLoader
{
public:
	LevelLoader() = default;
	~LevelLoader();
	void LoadLevel(const std::string path);

	vector<Entity*> m_pEntities;
private:
	
};


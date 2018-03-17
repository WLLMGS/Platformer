#include "LevelLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

LevelLoader::~LevelLoader()
{
	for(Entity* e : m_pEntities)
	{
		delete e;
		e = nullptr;
	}
}

void LevelLoader::LoadLevel(const std::string path)
{
	//csv
	ifstream file;
	
	file.open(path);

	string line{};
	
	int x{}, y{};

	const float tilesize = 64.0f;

	while(file.good())
	{
		while (getline(file, line))
		{
			stringstream stream(line);
			string element;

			while(getline(stream, element, ','))
			{
				if(element == "E")
				{
					cout << "E";
				}
				else if (element == "P")
				{
					cout << "P";
					auto e = new Entity(tilesize / 2.0f, { x * tilesize, y * tilesize }, 1, true);
					m_pEntities.push_back(e);
				}
				++x;
			}
			x = 0;
			++y;
			cout << endl;
		}
	}

}

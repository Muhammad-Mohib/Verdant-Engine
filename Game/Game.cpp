#include "Application.h"
#include<iostream>
#include <GameObject.h>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

std::vector<float> plant_verts = {
	// position     // UV
	-0.1f, -0.1f,   0.0f, 0.0f,
	 0.1f, -0.1f,   1.0f, 0.0f,
	 0.1f,  0.2f,   1.0f, 1.0f,
	-0.1f,  0.2f,   0.0f, 1.0f
};

std::vector<unsigned int> plant_indices = {
	0, 1, 2,
	2, 3, 0
};

class Game : public Application
{
	GameObject plant1 = GameObject(plant_verts, plant_indices, "sunflower.png");
	GameObject plant2 = GameObject(plant_verts, plant_indices, "peashooter.png");
	//GameObject plant2 = GameObject(vertices, indices);
	//GameObject plant3 = GameObject(vertices, indices);
	//GameObject plant4 = GameObject(vertices, indices);

protected:	
	void OnStart() override
	{
	}

	void OnUpdate(float deltaTime) override
	{
		plant1.Draw();
		plant2.Draw();
		//plant3.Draw();
		//plant4.Draw();

		plant1.setPosition(glm::vec2(deltaTime * 0.0001, deltaTime * 0.15));
		plant2.setPosition(glm::vec2(deltaTime * 0.03, deltaTime * 0.05));
		//plant3.setPosition(glm::vec2(deltaTime * 0.05, deltaTime * 0.15));
	}
};

void setConfig()
{
	GameObject::setTextureDirectory("C:\\Users\\mohib\\source\\repos\\Muhammad-Mohib\\Verdant-Engine\\Game\\Textures\\");
}

int main()
{
	setConfig();

	Game game;
	game.Run();

	return 0;
}

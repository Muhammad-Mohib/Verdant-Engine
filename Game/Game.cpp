#include "Application.h"
#include<iostream>
#include <GameObject.h>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shooter.h"
#include<format>
#include "SeedBank.h"
std::vector<float> plant_verts = {
	// Position     // UV
	 0.0f,  0.0f,   0.0f, 0.0f,
	50.0f,  0.0f,   1.0f, 0.0f,
	50.0f, 50.0f,   1.0f, 1.0f,
	 0.0f, 50.0f,   0.0f, 1.0f
};

std::vector<unsigned int> plant_indices = {
	0, 1, 2,
	2, 3, 0
};

std::vector<float> background_verts = {
	// Position        // UV
	   0.0f,   0.0f,   0.0f, 0.0f,
	1400.0f,   0.0f,   1.0f, 0.0f,
	1400.0f, 600.0f,   1.0f, 1.0f,
	   0.0f, 600.0f,   0.0f, 1.0f
};
std::vector<unsigned int> background_indices = {
	0, 1, 2,
	2, 3, 0
};


class Game : public Application
{
	std::vector<glm::vec2> Grid;

	std::vector<std::unique_ptr<GameObject>> plants;

	std::vector<std::unique_ptr<Shooter>> shooters;

protected:	
	void OnStart() override
	{
		GameObject* background = CreateGameObject(
			background_verts, background_indices, "background1.jpg"
		);
		background->setPosition(glm::vec2(-220.0f, 0.0f));

		shooters.push_back(std::make_unique<Shooter>(
			plant_verts, plant_indices, "snow_pal.png", *this
		));

		SeedBank seedBank = SeedBank(*this);

		const int columns = 9;
		const int plantCount = 45; // Two rows; use 45 for five rows

		const glm::vec2 gridOrigin(210.0f, 160.0f);
		const glm::vec2 cellSize(65.0f, 80.0f);

		for (int i = 0; i < plantCount; i++)
		{
			int column = i % columns;
			int row = i / columns;

			glm::vec2 position = gridOrigin + glm::vec2(
				column * cellSize.x,
				row * cellSize.y
			);

			auto plant = std::make_unique<GameObject>(
				plant_verts, plant_indices, "transparent_plant_slot.png"
			);

			plant->setPosition(position);
			plants.push_back(std::move(plant));
		}


	}

	void OnUpdate(float deltaTime) override
	{

		glm::vec2 cursorPosition = GetCursorPos();

		//for (const auto& plant : plants)
		//{
		//	if ((cursorPosition.x - 50) <= plant->position.x &&
		//		(cursorPosition.x + 5) >= plant->position.x &&
		//		(cursorPosition.y + 10) >= plant->position.y && 
		//		(cursorPosition.y - 40) <= plant->position.y)
		//	{
		//		plant2.setPosition(plant->position);
		//	}
		//}

		//if (cursorPosition.x > 600)
		//{
		//	std::cout << "TRIGE";
		//	shooters[0]->StartShooting();
		//}

		for (const auto& shooter : shooters)
		{
			shooter->UpdateBulletsPos(deltaTime);
		}
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

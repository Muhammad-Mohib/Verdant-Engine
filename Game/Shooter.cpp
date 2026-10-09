#include "Shooter.h"


std::vector<float> plant_verts22 = {
	// Position     // UV
	 0.0f,  0.0f,   0.0f, 0.0f,
	50.0f,  0.0f,   1.0f, 0.0f,
	50.0f, 50.0f,   1.0f, 1.0f,
	 0.0f, 50.0f,   0.0f, 1.0f
};

std::vector<unsigned int> plant_indices22 = {
	0, 1, 2,
	2, 3, 0
};
Shooter::Shooter(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName) : Plant(std::move(Vertices),
    std::move(Indices),
    std::move(TextureImageName))
{
	StartShooting();
}

GameObject* Shooter::GetGameObject()
{
	return &gameObject;
}

void Shooter::StartShooting()
{
	isShooting = true;
    GameObject bullet_gameObject = GameObject(plant_verts22, plant_indices22, "repeater.png");
}

void Shooter::StopShooting()
{
	isShooting = false;
}
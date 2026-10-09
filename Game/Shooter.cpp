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

Shooter::Shooter(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName, Application& Application) : 
	Plant(
	std::move(Vertices),
    std::move(Indices),
    std::move(TextureImageName), 
	Application), application(Application)
{
	ShooterBulletOffset = glm::vec2(40, -13);
	StartShooting();
}

GameObject* Shooter::GetGameObject()
{
	return gameObject;
}
int timer = 0;
void Shooter::StartShooting()
{
	timer = 0;
	ShootingOrigin = gameObject->position + ShooterBulletOffset;
	isShooting = true;
	
	GameObject* bullet = application.CreateGameObject(plant_verts22, plant_indices22, "pea.png");
	bullet->setPosition(ShootingOrigin);

	bullets.push_back(bullet);

	std::cout << "Shooter: " << this
		<< " | Bullet: " << bullet
		<< " | Count: " << bullets.size()
		<< '\n';
	std::cout << "Spawn position: "
		<< ShootingOrigin.x << ", "
		<< ShootingOrigin.y << '\n';

}

void Shooter::StopShooting()
{
	isShooting = false;
}

void Shooter::UpdateBulletsPos(float DeltaTime)
{
	for (const auto& bullet : bullets)
	{
		bullet->setPosition(bullet->position + glm::vec2(bulletSpeed * DeltaTime, 0));
	}
}

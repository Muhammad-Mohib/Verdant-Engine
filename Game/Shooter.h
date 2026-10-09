#include "Plant.h"
//#include <Application.h>
#include<string>
#include<vector>

class Shooter : public Plant
{
public:
	Shooter(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName, Application& Application);
	GameObject* GetGameObject();

	void UpdateBulletsPos(float deltaTime);
	void StartShooting();

protected:
	void StopShooting();
	Application& application;

private:
	bool isShooting;
	glm::vec2 ShootingOrigin;
	glm::vec2 ShooterBulletOffset;
	std::vector<GameObject*> bullets;
	float bulletSpeed = 100.0f;
};


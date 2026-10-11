#include "Plant.h"
//#include <Application.h>
#include<string>
#include<vector>

struct ShooterConfig
{
	std::string TextureImageName;
	int FiringInterval;
	// Add health, cost, firing interval, etc. here.
};

class Shooter : public Plant
{
public:
	Shooter(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName, Application& Application);	
	
	using Config = ShooterConfig;
	Shooter(const Config& configuration, Application& application);

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


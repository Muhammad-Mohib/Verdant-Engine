#include "Plant.h"

class Shooter : public Plant
{
public:
	Shooter(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName);
	GameObject* GetGameObject();

protected:
	void StartShooting();
	void StopShooting();
private:
	bool isShooting;
};


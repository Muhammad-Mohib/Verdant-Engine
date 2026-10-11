#pragma once
#include<GameObject.h>
#include <Application.h>

class Plant
{
public:
	Plant(std::vector<float> vertices, std::vector<unsigned int> indices, std::string texture_filename, Application& application);

	virtual ~Plant() = default;
protected:
	GameObject* gameObject;
private:
	float Health;
	float Cooldown;
	int Cost;

};


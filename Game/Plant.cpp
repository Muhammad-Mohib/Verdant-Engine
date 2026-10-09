#include "Plant.h"

Plant::Plant(std::vector<float> vertices, std::vector<unsigned int> indices, std::string texture_filename, Application& application)
{
	gameObject = application.CreateGameObject(vertices, indices, texture_filename);
	gameObject->setPosition(glm::vec2(200,400));
}

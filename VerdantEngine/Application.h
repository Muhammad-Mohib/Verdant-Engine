#pragma once
#include <glm/glm.hpp>
#include <string>
#include<vector>
#include "GameObject.h"

class Window;


class Application
{
public:
	Application();
	virtual ~Application();
	
	void Run();
	void Shutdown();

	GameObject* CreateGameObject(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::string& textureName);

protected:
	virtual void OnStart() {}
	virtual void OnUpdate(float deltaTime) = 0;
	glm::vec2 GetCursorPos();

private:
	Window* window = nullptr;

	std::vector<std::unique_ptr<GameObject>> gameObjects;

	void DrawGameObjects();
};
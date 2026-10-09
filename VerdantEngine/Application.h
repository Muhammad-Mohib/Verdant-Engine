#pragma once
#include <glm/glm.hpp>

class Window;


class Application
{
public:
	Application();
	virtual ~Application();
	
	void Run();
	void Shutdown();

protected:
	virtual void OnStart() {}
	virtual void OnUpdate(float deltaTime) = 0;
	glm::vec2 GetCursorPos();

private:
	Window* window = nullptr;
};
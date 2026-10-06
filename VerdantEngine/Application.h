#pragma once

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

private:
	Window* window = nullptr;
};
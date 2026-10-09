#pragma once

class Window
{
public:
	Window(int width, int height, const char* title);
	~Window();

	bool ShouldClose();
	void Update();

	GLFWwindow* m_Window;

private:
};


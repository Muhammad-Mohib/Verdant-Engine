#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>
#include<iostream>
#include "Window.h"
#include "Application.h"

int main()
{
	Application app;
	app.Run();
	return 0;
}

void Application::Run()
{
	while (!window->ShouldClose())
	{
		glClearColor(0.1f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window->Update();
	}
}

Application::Application()
{
	const char* WindowTitle = "Verdant Engine";
	window = new Window(400, 400, WindowTitle);
}

Application::~Application()
{
	glfwTerminate();
}

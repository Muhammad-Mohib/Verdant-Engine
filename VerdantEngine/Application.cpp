#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>
#include<iostream>
#include "Window.h"
#include "Application.h"
#include "Shader.h"
#include "GameObject.h";
#include "Texture.h"

void Application::Run()
{
	OnStart();

	double previousTime = glfwGetTime();
	
	while (!window->ShouldClose())
	{
		double currentTime = glfwGetTime();
		float deltaTime =
		static_cast<float>(currentTime - previousTime);	

		glClearColor(0.1f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		OnUpdate(deltaTime);

		glDrawElements(
			GL_TRIANGLES,
			12,
			GL_UNSIGNED_INT,
			nullptr
		);

		

		window->Update();
	}
}

Application::Application()
{
	const char* WindowTitle = "Verdant Engine";
	window = new Window(800, 600, WindowTitle);
}

Application::~Application()
{
	glfwTerminate();
}

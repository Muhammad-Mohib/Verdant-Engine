#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>
#include<iostream>
#include "Window.h"
#include "Application.h"
#include "Shader.h"

//int main()
//{
//	//Application app;
//	//app.Run();
//	return 0;
//}

void Application::Run()
{
	OnStart();

	double previousTime = glfwGetTime();

	float vertices[] = {
		-0.5, -0.5, 0.0f,
		0.5, -0.5, 0.0f,
		0.0, 0.5, 0.0f,
	};

	Shader sh = Shader("", "");

	unsigned int VAO, VBO;

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	

	while (!window->ShouldClose())
	{
		double currentTime = glfwGetTime();
		float deltaTime =
		static_cast<float>(currentTime - previousTime);

		glClearColor(0.1f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		OnUpdate(deltaTime);

		window->Update();
	}
}

Application::Application()
{
	const char* WindowTitle = "Verdant Engine";
	window = new Window(800, 800, WindowTitle);
}

Application::~Application()
{
	glfwTerminate();
}

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<GLM/glm.hpp>
#include<iostream>
#include "Window.h"
#include "Application.h"
#include "Shader.h"
#include "Texture.h"

void Application::Run()
{
	OnStart();


	//SceneGameObjects = std::make_unique<GameObject>();

	double previousTime = glfwGetTime();
	
	while (!window->ShouldClose())
	{
		//std::cout << 
		double currentTime = glfwGetTime();
		float deltaTime =
		static_cast<float>(currentTime - previousTime);
		previousTime = currentTime;

		glClearColor(0.1f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		OnUpdate(deltaTime);

		DrawGameObjects();

		//glDrawElements(
		//	GL_TRIANGLES,
		//	6,
		//	GL_UNSIGNED_INT,
		//	nullptr
		//);

		window->Update();
	}
}

GameObject* Application::CreateGameObject(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::string& textureName)
{
	auto object = std::make_unique<GameObject>(
		vertices, indices, textureName
	);

	GameObject* pointer = object.get();

	gameObjects.push_back(std::move(object));
	return pointer;
}

glm::vec2 Application::GetCursorPos()
{
	double xpos, ypos;
	glfwGetCursorPos(window->m_Window, &xpos, &ypos);
	return glm::vec2(xpos, ypos);
}
void Application::DrawGameObjects()
{
	for (const auto& object : gameObjects)
	{
		object->Draw();
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

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include<iostream>


Window::Window(int width, int height, const char* title)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

	glfwMakeContextCurrent(m_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD init failed\n";
	}

	glViewport(0, 0, width, height);
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(m_Window);
}

void Window::Update()
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}




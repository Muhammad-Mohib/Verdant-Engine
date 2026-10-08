#include "Application.h"
#include<iostream>
#include <GameObject.h>
#include <vector>

std::vector<float> vertices = {
	// Left quad
	// position       // UV
	-0.9f, -0.5f,     0.0f, 0.0f,
	-0.1f, -0.5f,     1.0f, 0.0f,
	-0.1f,  0.5f,     1.0f, 1.0f,
	-0.9f,  0.5f,     0.0f, 1.0f,

	// Right quad
	 0.1f, -0.5f,     0.0f, 0.0f,
	 0.9f, -0.5f,     1.0f, 0.0f,
	 0.9f,  0.5f,     1.0f, 1.0f,
	 0.1f,  0.5f,     0.0f, 1.0f
};

std::vector<unsigned int> indices = {
	// Left quad
	0, 1, 2,
	2, 3, 0,

	// Right quad
	4, 5, 6,
	6, 7, 4
};

class Game : public Application
{

	GameObject tri = GameObject(vertices, indices);

protected:
	void OnStart() override
	{
	}

	void OnUpdate(float deltaTime) override
	{
		tri.shader.Activate();
		tri.texture.Bind();
		tri.texture.ActivateTexture(0);

		glUniform1i(
			glGetUniformLocation(tri.shader.ID, "tex"),
			GL_TEXTURE0
		);


		tri.Bind();
	}
};

int main()
{
	Game game;
	game.Run();

	return 0;
}
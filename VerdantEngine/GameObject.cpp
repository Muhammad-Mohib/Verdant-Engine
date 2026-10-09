#include "GameObject.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

std::string GameObject::textureDirectory = "";

GameObject::GameObject(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName) : shader("C:\\Users\\mohib\\source\\repos\\Muhammad-Mohib\\Verdant-Engine\\VerdantEngine\\default.vert", "C:\\Users\\mohib\\source\\repos\\Muhammad-Mohib\\Verdant-Engine\\VerdantEngine\\default.frag"), texture((textureDirectory+TextureImageName))
{
	texture.ActivateTexture(shader.ID);

	vertices = Vertices;
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		Indices.size() * sizeof(unsigned int),
		Indices.data(),
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Draw();

}

void GameObject::setPosition(glm::vec2 newPosition)
{
	position = newPosition;
}

void GameObject::Draw()
{

	const float WINDOW_WIDTH = 800;
	const float WINDOW_HEIGHT = 600;

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(position, 0.0f));
	model = glm::scale(model, glm::vec3(1.0f));
	shader.Activate();

	glm::mat4 projection = glm::ortho(
		0.0f, WINDOW_WIDTH,    // Left, right
		WINDOW_HEIGHT, 0.0f,    // Bottom, top: Y increases downward
		-1.0f, 1.0f     // Near, far
	);

	glUniformMatrix4fv(
		glGetUniformLocation(shader.ID, "projection"),
		1, GL_FALSE, glm::value_ptr(projection)
	);


	glUniformMatrix4fv(
		glGetUniformLocation(shader.ID, "model"),
		1,
		GL_FALSE,
		glm::value_ptr(model)
	);


	texture.ActivateTexture(0);
	texture.Bind();

	glUniform1i(
		glGetUniformLocation(shader.ID, "tex"),
		0
	);

	Bind();

	glDrawElements(
		GL_TRIANGLES,
		6,
		GL_UNSIGNED_INT,
		nullptr
	);
}

void GameObject::Bind()
{
	shader.Activate();
	glBindVertexArray(VAO);
}

void GameObject::setTextureDirectory(std::string directory)
{
	GameObject::textureDirectory = directory;
}
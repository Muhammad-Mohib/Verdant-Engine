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

	//glm::mat4 model = glm::mat4(1.0f);

	//model = glm::translate(model, glm::vec3(position, 0.0f));

	//int modelLoc = glGetUniformLocation(shader.ID, "model");

	//shader.Activate();

	//glUniformMatrix4fv(
	//	modelLoc,
	//	1,
	//	GL_FALSE,
	//	glm::value_ptr(model)
	//);


	//texture.ActivateTexture(0);
	//texture.Bind();

	//glUniform1i(
	//	glGetUniformLocation(shader.ID, "tex"),
	//	0
	//);

	//Bind();

	//glDrawElements(
	//	GL_TRIANGLES,
	//	6,
	//	GL_UNSIGNED_INT,
	//	nullptr
	//);

	Draw();

}

void GameObject::setPosition(glm::vec2 newPosition)
{
	position = newPosition;
}

void GameObject::Draw()
{
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(position, 0.0f));

	shader.Activate();

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
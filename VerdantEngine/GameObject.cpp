#include "GameObject.h"

GameObject::GameObject(std::vector<float> Vertices, std::vector<unsigned int> Indices) : shader("C:\\Users\\mohib\\source\\repos\\Muhammad-Mohib\\Verdant-Engine\\VerdantEngine\\default.vert","C:\\Users\\mohib\\source\\repos\\Muhammad-Mohib\\Verdant-Engine\\VerdantEngine\\default.frag"), texture("C:\\Users\\mohib\\source\\repos\\Muhammad-Mohib\\Verdant-Engine\\VerdantEngine\\sunflower.png")
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

}

void GameObject::Bind()
{
	shader.Activate();
	glBindVertexArray(VAO);
}
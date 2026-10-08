#pragma once
#include<vector>
#include "Shader.h"
#include "Texture.h"

struct Vertex
{
	float x, y, z;
	float u, v;
};

class GameObject
{
public:
	GameObject(std::vector<float> Vertices, std::vector<unsigned int> Indices);
	unsigned int VAO, VBO, EBO;
	std::vector<float> vertices;
	Shader shader;
	Texture texture;

	void Bind();

};


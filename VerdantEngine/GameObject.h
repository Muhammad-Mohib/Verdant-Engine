#pragma once
#include<vector>
#include "Shader.h"
#include "Texture.h"
#include<GLM/glm.hpp>

struct Vertex
{
	float x, y, z;
	float u, v;
};

class GameObject
{
public:
	GameObject(std::vector<float> Vertices, std::vector<unsigned int> Indices, std::string TextureImageName);
	static void setTextureDirectory(std::string directory);
	unsigned int VAO, VBO, EBO;
	std::vector<float> vertices;
	Shader shader;
	Texture texture;
	glm::vec2 position = glm::vec2(0.0f);
	void setPosition(glm::vec2);
	void Draw();

	void Bind();
private:
	static std::string textureDirectory;

};


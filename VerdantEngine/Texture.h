#include<stb/stb_image.h>
#include<glad/glad.h>
#include<iostream>

#pragma once
class Texture
{
public:
	Texture(std::string filename);
	unsigned int ID;

	void ActivateTexture(unsigned int unit);

	void Bind();
private:
	int imageWidth;
	int imageHeight;
	int numberOfChannels;

};


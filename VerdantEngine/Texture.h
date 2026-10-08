#include<stb/stb_image.h>
#include<glad/glad.h>

#pragma once
class Texture
{
public:
	Texture(char const* filename);
	unsigned int ID;

	void ActivateTexture(unsigned int unit);

	void Bind();
private:
	int imageWidth;
	int imageHeight;
	int numberOfChannels;

};


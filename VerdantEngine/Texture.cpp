#include "Texture.h"

Texture::Texture(char const* filename)
{
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename, &imageWidth, &imageHeight, &numberOfChannels, 0);
	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0);
	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::ActivateTexture(unsigned int unit)
{
	glActiveTexture(GL_TEXTURE0 + unit);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

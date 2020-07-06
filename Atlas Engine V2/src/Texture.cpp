#include "Texture.h"
#include "stb_image.h"
#include <string>
#include <iostream>

Atlas::Texture::Texture()
	: textureID(0)
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	stbi_set_flip_vertically_on_load(1);

	int width, height, nrChannels;
	std::string texDirAndNameAbsolute = "res/textures/cow.png";
	unsigned char* data = stbi_load(texDirAndNameAbsolute.c_str(), &width, &height, &nrChannels, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Failed to load texture\n");
	}
}

Atlas::Texture::~Texture()
{
}

void Atlas::Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Atlas::Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

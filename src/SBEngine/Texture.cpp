#include "Texture.h"

Texture::~Texture()
{
}

void Texture::SetPixel(unsigned int _x, unsigned int _y, glm::vec4 _colour)
{
}

std::shared_ptr<Texture> Texture::Create(unsigned int _width, unsigned int _height)
{
	return std::shared_ptr<Texture>();
}

std::shared_ptr<Texture> Texture::Load(std::string _filepath)
{
	return std::shared_ptr<Texture>();
}

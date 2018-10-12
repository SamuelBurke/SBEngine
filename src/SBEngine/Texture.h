#pragma once
#include "Resource.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

class Texture : public Resource
{
public:
	~Texture();

	//void SetPixel(unsigned int _x, unsigned int _y, glm::vec3 _colour);  // vec3 colour
	void SetPixel(unsigned int _x, unsigned int _y, glm::vec4 _colour);    // vec4 colour

	GLuint getId() { return m_id; }

private:
	std::shared_ptr<Texture> Create(unsigned int _width, unsigned int _height);
	std::shared_ptr<Texture> Load(std::string _filepath);

	GLuint m_id;
	//int m_type;
	//bool dirty;
};


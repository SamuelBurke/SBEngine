#include "Triangle.h"

#include <exception>

void Triangle::tick()
{
	const GLfloat positions[] = {
					0.0f, 0.5f, 0.0f,
					-0.5f, -0.5f, 0.0f,
					0.5f, -0.5f,0.0f
				};

	positionsVboID = 0;

	//create a new VBO on the GPU and bind it
	glGenBuffers(1, &positionsVboID);

	if (!positionsVboID)
	{
		throw std::exception();
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionsVboID);
	//upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	vaoID = 0;

	//create a new VAO on the CPU and bind it
	glGenVertexArrays(1, &vaoID);

	if (!vaoID)
	{
		throw std::exception();
	}

	glBindVertexArray(vaoID);

	//bind the position VBO, assign it to a position 0 on the bound VAO and flag it to be used
	glBindBuffer(GL_ARRAY_BUFFER, positionsVboID);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);

	glEnableVertexAttribArray(0);

	//reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	VShader();
	FShader();
}

void Triangle::VShader()
{
	const GLchar *vertexShaderSrc =
		"attribute vec3 in_Position;            " \
		"                                       " \
		"void main()                            " \
		"{                                      " \
		"  gl_Position = vec4(in_Position, 1.0);" \
}

void Triangle::FShader()
{

}
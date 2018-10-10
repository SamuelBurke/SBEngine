#include "Triangle.h"
#include "Shader.h"


#include  <exception>

void Triangle::SetUp()
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


	{
		//const GLchar *vertexShaderSrc =
		//	"attribute vec3 in_Position;            " \
		//	"                                       " \
		//	"void main()                            " \
		//	"{                                      " \
		//	"  gl_Position = vec4(in_Position, 1.0);" \
		//	"}										";

		////create new vertex shader, attach source code, compile it and check for errors
		//GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		//glShaderSource(vertexShaderID, 1, &vertexShaderSrc, NULL);
		//glCompileShader(vertexShaderID);
		//GLint success = 0;
		//glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

		//if (!success)
		//{
		//	throw std::exception();
		//}

		//const GLchar *fragmentShaderSrc =
		//	"void main()                           " \
		//	"{                                     " \
		//	"	gl_FragColor = vec4(0, 1, 1, 1);   " \
		//	"}                                     ";

		////create a new fragment shader, attach source code, compile it and check for errors
		//GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		//glShaderSource(fragmentShaderID, 1, &fragmentShaderSrc, NULL);
		//glCompileShader(fragmentShaderID);
		//glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

		//if (!success)
		//{
		//	throw std::exception();
		//}
	}

	//vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//programID = glCreateProgram();
	//glAttachShader(programID, vertexShaderID);
	//glAttachShader(programID, fragmentShaderID);

	////ensure the VAO "position" attribute stream gets set as the first position during the link
	//glBindAttribLocation(programID, 0, "in_Position");

	////perform the link and check for failure
	//glLinkProgram(programID);
	//glGetProgramiv(programID, GL_LINK_STATUS, &success);

	//if (!success)
	//{
	//	throw std::exception();
	//}

	////detach and destroy the shader objects. These are no longer needed because we now have a complete shader program.
	//glDetachShader(programID, vertexShaderID);
	//glDeleteShader(vertexShaderID);
	//glDetachShader(programID, fragmentShaderID);
	//glDeleteShader(fragmentShaderID);
}


void Triangle::Draw()
{
	//glUseProgram(programID);
	Shader thisShader("resources / simple.vert", "resources / simple.frag");
	thisShader.Use();
	glBindVertexArray(vaoID);
	//draw 3 vertices 
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//reset the state
	glBindVertexArray(0);
	glUseProgram(0);
}



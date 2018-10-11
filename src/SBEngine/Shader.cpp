#include "Shader.h"

//Shader::Shader(const std::shared_ptr<char> _vertexPath, const std::shared_ptr<char> _fragmentPath)
//{
//
//}

Shader::Shader(const char* _vertexPath, const char* _fragmentPath)
{
	//ensure ifstream objects can throw exceptions
	m_vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	m_fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		//open files
		m_vShaderFile.open(_vertexPath);
		m_fShaderFile.open(_fragmentPath);

		//read the file's buffer contents into streams 
		// - "rdbuf" : redirects the buffer contents
		m_vShaderStream << m_vShaderFile.rdbuf();
		m_fShaderStream << m_fShaderFile.rdbuf();

		//close file handlers
		m_vShaderFile.close();
		m_fShaderFile.close();

		//convert stream into string
		m_vertexCode   = m_vShaderStream.str();
		m_fragmentCode = m_fShaderStream.str();
	}

		catch (std::ifstream::failure _e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ_SUCCESSFULLY" << std::endl;
		}

	m_vShaderCode = m_vertexCode.c_str();
	m_fShaderCode = m_fragmentCode.c_str();

	//vertex shader
	m_vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_vertex, 1, &m_vShaderCode, NULL);
	glCompileShader(m_vertex);
	CheckCompilerErrors(m_vertex, "VERTEX");
	//fragment shader
	m_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_fragment, 1, &m_fShaderCode, NULL);
	glCompileShader(m_fragment);
	CheckCompilerErrors(m_fragment, "FRAGMENT");

	//shader program
	m_ID = glCreateProgram();
	glAttachShader(m_ID, m_vertex);
	glAttachShader(m_ID, m_fragment);
	glLinkProgram(m_ID);
	CheckCompilerErrors(m_ID, "PROGRAM");

	//delete shaders as they're linked into the program and aren't necessary
	glDeleteShader(m_vertex);
	glDeleteShader(m_fragment);

}

void Shader::Use()
{
	glUseProgram(m_ID);
}

//Utility uniform function
//------------------------
void Shader::SetBool(const std::string &_name, bool _value) const
{
	glUniform1i(glGetUniformLocation(m_ID, _name.c_str()), (int)_value);
}

void Shader::SetInt(const std::string &_name, int _value) const
{
	glUniform1i(glGetUniformLocation(m_ID, _name.c_str()), _value);
}

void Shader::SetFloat(const std::string &_name, float _value) const
{
	glUniform1i(glGetUniformLocation(m_ID, _name.c_str()), _value);
}

void Shader::CheckCompilerErrors(unsigned int _shader, std::string _type)
{
	int success;
	char infoLog[1024];
	if (_type != "PROGRAM")
	{
		glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(_shader, 1024, NULL, infoLog);
			std::cout << "ERROR: SHADER COMPILATION ERROR of type:" << _type << std::endl << infoLog << "\n -- --------- --" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(_shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(_shader, 1024, NULL, infoLog);
			std::cout << "ERROR: PROGRAM LINKING ERROR of type:" << _type << std::endl << infoLog << "\n -- --------- --" << std::endl;
		}
	}
}
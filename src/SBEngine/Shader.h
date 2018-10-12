#ifndef SHADER_H_
#define SHADER_H_

#include <gl/glew.h>
//#include <memory>
#include "NonCopyable.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader : private NonCopyable
{
public:
	//Shader(const std::shared_ptr<char> _vertexPath, const std::shared_ptr<char> _fragmentPath)
	Shader(const char* _vertexPath, const char* _fragmentPath);

	unsigned int m_ID;

	void Use();
	void SetBool(const std::string &_name, bool _value) const;
	void SetInt(const std::string &_name, int _value) const;
	void SetFloat(const std::string &_name, float _value) const;

	std::string m_vertexCode;
	std::string m_fragmentCode;
	std::ifstream m_vShaderFile;
	std::ifstream m_fShaderFile;

	std::stringstream m_vShaderStream, m_fShaderStream;

	const char* m_vShaderCode;
	const char* m_fShaderCode;

	unsigned int m_vertex, m_fragment;

	//(../resources/shaders....)

private:
	void CheckCompilerErrors(unsigned int _shader, std::string _type);
};

#endif
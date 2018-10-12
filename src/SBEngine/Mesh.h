#pragma once
#include "Resource.h"

#include <memory>

class Mesh : public Resource
{
public:
	~Mesh();
private:
	static std::shared_ptr<Mesh> Create();
	std::shared_ptr<Mesh> Load(std::string _filePath);

};

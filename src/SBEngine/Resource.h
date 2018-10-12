#pragma once
#ifndef SBENGINE_RESOURCE_H_
#define SBENGINE_RESOURCE_H_
#include "NonCopyable.h"

#include <string>

class Resource : private NonCopyable
{
private:
	std::string m_path;
};

#endif

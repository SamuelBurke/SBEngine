#pragma once
#ifndef SBENGINE_COMPONENT_H_
#define SBENGINE_COMPONENT_H_

#include <memory>

namespace SBEngine
{

class Entity;
class Core;

class Component
{
public:
	virtual ~Component();

	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Core> GetCore();

private:
	std::weak_ptr<Entity> m_entity;

	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnTick();
	virtual void OnDisplay();
};

}

#endif
#include "Entity.h"

namespace SBEngine
{

std::shared_ptr<Core> Entity::GetCore()
{
	return m_core.lock(); //returns a shared pointer to a weak pointer with the data preserved.
}

void Entity::Tick()
{
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		(*it)->OnTick();
	}
}

void Entity::Display()
{
	for (auto it = m_components.begin(); it != m_components.end(); it++)
	{
		(*it)->OnDisplay();
	}
}

}
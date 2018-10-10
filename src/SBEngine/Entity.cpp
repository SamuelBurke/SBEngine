#include "Entity.h"

namespace SBEngine
{

std::shared_ptr<Core> Entity::GetCore()
{
	return core.lock(); //returns a shared pointer to a weak pointer with the data preserved.
}

void Entity::Tick()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->OnTick();
	}
}

void Entity::Display()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->
	}
}

}
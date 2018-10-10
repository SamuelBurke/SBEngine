#include "Core.h"
#include "Entity.h" // forward declaring isn't enough

namespace SBEngine
{

std::shared_ptr<Core> Core::Initialise()
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->m_running = false;
	rtn->m_self = rtn;
}

void Core::Start()
{
	running = true;

	while (running)
	{
		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Tick(); //dereferences the shared ptr, - How to use iterators with smart ptrs
		}
	}
}

void Core::Stop()
{
	running = false;
}

std::shared_ptr<Entity> Core::AddEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	entities.push_back(rtn);

	return rtn;
}

}
#include "Component.h"
#include "Entity.h"

namespace SBEngine
{

std::shared_ptr<Entity> Component::GetEntity()
{
	return m_entity.lock();
}

std::shared_ptr<Core> Component::GetCore()
{
	return GetEntity()->GetCore();
}


Component::~Component()
{

}

void Component::OnInit()
{

}

void Component::OnTick()
{

}


void Component::OnBegin()
{

}

void Component::OnDisplay()
{

}

}
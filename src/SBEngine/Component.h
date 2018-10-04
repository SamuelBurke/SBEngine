#pragma once
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>

class Entity;
class Core;
class Keyboard;
class Environment;

class Component
{
public:
	virtual ~Component();

	virtual void OnTick();

	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<Environment> GetEnvironment();

private:
	std::weak_ptr<Entity> entity;

	//void OnInit();
	//void OnBegin();
	//void OnTick();
	//void OnDisplay();
};

#endif
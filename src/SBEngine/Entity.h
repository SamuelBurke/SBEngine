#include <memory>
#include <vector>

class Core;
class Component;

class Entity
{
public:
	Entity();
	~Entity();

	std::shared_ptr<Core> GetCore();


private:
	std::weak_ptr<Core> core;
	std::vector <std::shared_ptr<Component>> components;

	void tick();
	void display();
};
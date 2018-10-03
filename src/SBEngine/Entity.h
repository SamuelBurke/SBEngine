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

	//template <typename T>
	//std::shared_ptr<T> AddComponent<T>()
	//{

	//}

	//template <class T>
	//std::shared_ptr<T> AddComponent<T, A>(a:A)
	//{

	//}

	//template <class T>
	//std::shared_ptr<T> AddComponent<T, A, B>(a:A, b:B)
	//{

	//}

	//template <class T>
	//std::shared_ptr<T> AddComponent<T, A, B, C>(a:A, b:B, c:C)
	//{

	//}

private:
	std::weak_ptr<Core> core;
	std::vector <std::shared_ptr<Component>> components;

	void tick();
	void display();
};
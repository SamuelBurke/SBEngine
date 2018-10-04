#include <memory>
#include <vector>

class Core;
class Component;

class Entity
{
public:
	std::shared_ptr<Core> GetCore();

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}

	//template <typename T>
	//std::shared_ptr<T> AddComponent<T, A>(a:A)
	//{

	//}

	//template <typename T>
	//std::shared_ptr<T> AddComponent<T, A, B>(a:A, b:B)
	//{

	//}

	//template <typename T>
	//std::shared_ptr<T> AddComponent<T, A, B, C>(a:A, b:B, c:C)
	//{

	//}


	void Tick();
	void Display();
private:
	std::weak_ptr<Core> core;
	std::vector <std::shared_ptr<Component>> components;
};
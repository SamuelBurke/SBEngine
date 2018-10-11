#include "Component.h"

#include <memory>
#include <vector>

namespace SBEngine
{

class Core;

class Entity
{
	friend class Core;
public:
	std::shared_ptr<Core> GetCore();

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}

	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (size_t i = 0; i < m_components.size(); i++)
		{
			std::shared_ptr temp = std::dynamic_pointer_cast<T>(m_components.at(i));

			if (temp) { return temp; }
		}

		throw std::exception();
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


private:
	std::weak_ptr<Core> m_core;
	std::weak_ptr<Entity> m_self;
	std::vector <std::shared_ptr<Component>> m_components;

	void Tick();
	void Display();
};

}
#include "Resource.h"

#include <memory>
#include <string>
#include <list>

class Resources
{
public:
	Resources();

	//template <typename T>
	//std::shared_ptr<T> Create<T>();

	//template <typename T>
	//std::shared_ptr<T> Load<T>(std::string _filePath);

private:
	std::list<std::shared_ptr<Resource>> m_resources;

};

//
//template <typename T>
//inline std::shared_ptr<T> Resources::Create()
//{
//	return std::shared_ptr<T>();
//}
//
//template <typename T>
//inline std::shared_ptr<T> Resources::Load(std::string _filePath)
//{
//	return std::shared_ptr<T>();
//}

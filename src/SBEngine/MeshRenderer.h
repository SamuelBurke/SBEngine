#include "Component.h"

#include <memory>

namespace SBEngine
{
class MeshRenderer : public Component
{
public:
	void Initialise();

	//set mesh
	//get mesh
	//get material
private:
	void Display();

	//std::weak_ptr<Mesh> m_mesh;
	//std::shared_ptr<Material> m_material;
};
}
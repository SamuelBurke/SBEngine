#include "Component.h"

#include <glm/glm.hpp>

namespace SBEngine
{
class Transform : public Component
{
public:
	void SetLocalPosition(glm::vec3 _position) { m_localPosition = _position; }
	void SetLocalRotation(glm::vec3 _rotation) { m_localRotation = _rotation; }
	void SetLocalScale(glm::vec3 _scale)       { m_localScale    = _scale;    }

	void Translate(glm::vec3 _value);
	void Rotate(glm::vec3 _value);
	void Scale(glm::vec3 _value);

private:
	glm::vec3 m_localPosition;
	glm::vec3 m_localRotation;
	glm::vec3 m_localScale;
	
};
}
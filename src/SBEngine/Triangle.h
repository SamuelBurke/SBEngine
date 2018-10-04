#include <GL/glew.h>

class Triangle
{
public:
	void tick();
private:
	//const GLfloat positions[];
	void VShader();
	void FShader();

	GLuint positionsVboID, vaoID;
};
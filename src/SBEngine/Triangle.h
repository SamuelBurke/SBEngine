#include <GL/glew.h>


class Triangle
{
public:
	void SetUp();
	void Draw();

private:
	GLuint positionsVboID, vaoID;
	GLuint programID;
};
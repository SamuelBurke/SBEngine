#include <SBEngine/SBEngine.h>

#include <SDL2/SDL.h>
#include  <GL/glew.h>
#include   <iostream>
#include  <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Player : public Component
{
public:
	//void OnTick()
	//{
	//	std::cout << "hello" << std::endl;;
	//}
};

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	SDL_Window *window = SDL_CreateWindow("Test Engine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, 
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	{
		//const GLfloat positions[] = {
		//	0.0f, 0.5f, 0.0f,
		//	-0.5f, -0.5f, 0.0f,
		//	0.5f, -0.5f,0.0f
		//};

		//GLuint positionsVboID = 0;

		////create a new VBO on the GPU and bind it
		//glGenBuffers(1, &positionsVboID);

		//if (!positionsVboID)
		//{
		//	throw std::exception();
		//}

		//glBindBuffer(GL_ARRAY_BUFFER, positionsVboID);
		////upload a copy of the data from memory into the new VBO
		//glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
		////reset the state
		//glBindBuffer(GL_ARRAY_BUFFER, 0);

		//GLuint vaoID = 0;

		////create a new VAO on the CPU and bind it
		//glGenVertexArrays(1, &vaoID);

		//if (!vaoID)
		//{
		//	throw std::exception();
		//}

		//glBindVertexArray(vaoID);

		////bind the position VBO, assign it to a position 0 on the bound VAO and flag it to be used
		//glBindBuffer(GL_ARRAY_BUFFER, positionsVboID);

		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);

		//glEnableVertexAttribArray(0);

		////reset the state
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindVertexArray(0);


		//const GLchar *vertexShaderSrc =
		//	"attribute vec3 in_Position;            " \
		//	"                                       " \
		//	"void main()                            " \
		//	"{                                      " \
		//	"  gl_Position = vec4(in_Position, 1.0);" \
		//	"}										";

		////create new vertex shader, attach source code, compile it and check for errors
		//GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		//glShaderSource(vertexShaderID, 1, &vertexShaderSrc, NULL);
		//glCompileShader(vertexShaderID);
		//GLint success = 0;
		//glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);

		//if (!success)
		//{
		//	throw std::exception();
		//}

		//const GLchar *fragmentShaderSrc =
		//	"void main()                           " \
		//	"{                                     " \
		//	"	gl_FragColor = vec4(0, 0, 1, 1);   " \
		//	"}                                     ";

		////create a new fragment shader, attach source code, compile it and check for errors
		//GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		//glShaderSource(fragmentShaderID, 1, &fragmentShaderSrc, NULL);
		//glCompileShader(fragmentShaderID);
		//glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);

		//if (!success)
		//{
		//	throw std::exception();
		//}

		//GLuint programID = glCreateProgram();
		//glAttachShader(programID, vertexShaderID);
		//glAttachShader(programID, fragmentShaderID);

		////ensure the VAO "position" attribute stream gets set as the first position during the link
		//glBindAttribLocation(programID, 0, "in_Position");

		////perform the link and check for failure
		//glLinkProgram(programID);
		//glGetProgramiv(programID, GL_LINK_STATUS, &success);

		//if (!success)
		//{
		//	throw std::exception();
		//}

		////detach and destroy the shader objects. These are no longer needed because we now have a complete shader program.
		//glDetachShader(programID, vertexShaderID);
		//glDeleteShader(vertexShaderID);
		//glDetachShader(programID, fragmentShaderID);
		//glDeleteShader(fragmentShaderID);
	}

	//Triangle myTriangle;
	//myTriangle.SetUp();

	bool quit = false;

	while (!quit)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

		}

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//myTriangle.Draw();

		std::shared_ptr<Core> core = std::make_shared<Core>();
		std::shared_ptr<Entity> player = core->AddEntity();
		player->AddComponent<Player>();

		core->Start();

		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
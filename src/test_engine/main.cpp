#include <SBEngine/SBEngine.h>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <exception>

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

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);

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

	std::shared_ptr<Core> core = std::make_shared<Core>();
	std::shared_ptr<Entity> player = core->AddEntity();
	player->AddComponent<Player>();

	core->Start();

	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
#include "Core.h"
#include "Entity.h" // forward declaring isn't enough

std::shared_ptr<Core> Core::Initialise()
{
	return std::shared_ptr<Core>();
}

void Core::Start()
{
	running = true;




	while (running)
	{
		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Tick(); //dereferences the shared ptr, - How to use iterators with smart ptrs
		}
	}

	//if (SDL_Init(SDL_INIT_VIDEO) < 0)
	//{
	//throw std::exception();
	//}

	//SDL_Window *window = SDL_CreateWindow("Test Engine",
	//SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	//WINDOW_WIDTH, WINDOW_HEIGHT,
	//SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	//if (!SDL_GL_CreateContext(window))
	//{
	//throw std::exception();
	//}

	//if (glewInit() != GLEW_OK)
	//{
	//throw std::exception();
	//}


	//bool quit = false;

	//while (!quit)
	//{
	//SDL_Event event = { 0 };

	//while (SDL_PollEvent(&event))
	//{
	//if (event.type == SDL_QUIT)
	//{
	//quit = true;
	//}
	//}
	//}

	//SDL_DestroyWindow(window);
	//SDL_Quit();
}

void Core::Stop()
{
	running = false;
}

std::shared_ptr<Entity> Core::AddEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	entities.push_back(rtn);

	return rtn;
}
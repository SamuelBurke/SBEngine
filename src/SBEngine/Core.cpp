#include "Core.h"
#include "Entity.h" // forward declaring isn't enough.

#include <GL/glew.h> 

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

namespace SBEngine
{

std::shared_ptr<Core> Core::Initialise() //called at the beginning of main().
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>(); //we want to return a shared pointer of core
	rtn->m_quit = false;								  //to the main, so we can call entity through
	rtn->m_self = rtn;									  //core, and component through entity.

	rtn->m_screen.InitWindow(); //call the initalisation  

	return rtn; //return our pointer to Core back to the main.
}

void Core::Start() //called at the end of main() - Here is where the main loop will be.
{
	m_quit = false; 
	while (!m_quit)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) //if the window is closed, the loop will end.
			{
				m_quit = true;
			}
		}

		for (auto it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick(); //dereferences the shared ptr, - How to use iterators with smart ptrs
		}

		m_screen.ClearBuffer();

		for (auto it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Display();
		}

		m_screen.SwapWindow();
	}
}

void Core::Stop()
{
	m_quit = true;
}

std::shared_ptr<Entity> Core::AddEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	m_entities.push_back(rtn);
	rtn->m_self = rtn;
	rtn->m_core = m_self;

	return rtn;
}

}
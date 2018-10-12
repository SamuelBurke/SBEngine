#include "Screen.h"

#include <GL/glew.h>
#include <exception>

using namespace SBEngine;

void Screen::InitWindow()
{
	m_width = 800;
	m_height = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) //throw an exception if SDL fails to initialise.
	{
		throw std::exception();
	}

	//create the window using SDL. This is where the game/engine will be seen through.
	m_window = SDL_CreateWindow("SBEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		m_width, m_height,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(m_window)) //if an OpenGL context cannot be created for window, throw an exception.
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK) //throw an exception if glew fails to initalise.
	{
		throw std::exception();
	}
}

void Screen::ClearBuffer() 
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::SwapWindow()
{
	SDL_GL_SwapWindow(m_window);
}
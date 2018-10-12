#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

#include <memory>

namespace SBEngine
{

class Screen
{

public:
	void InitWindow();
	void ClearBuffer();
	void SwapWindow();

	unsigned int GetWidth()  { return m_width; }
	unsigned int GetHeight() { return m_height; }

private:
	unsigned int m_width, m_height;

	std::weak_ptr<Screen> m_self;
	
	SDL_Window * m_window;
};

}

#endif // !SCREEN_H


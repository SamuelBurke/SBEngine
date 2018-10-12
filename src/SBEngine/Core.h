#include "NonCopyable.h"
#include "Screen.h"

#include <memory>
#include <vector>

namespace SBEngine
{

class Entity; // Forward declaration
class Screen;

class Core : private NonCopyable
{
public:
	static std::shared_ptr<Core> Initialise();
	std::shared_ptr<Entity> AddEntity();

	void Start();
	void Stop();

private:
	bool m_quit;
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::weak_ptr<Core> m_self;

	Screen m_screen;
	//Screen screen;

	//SDL_Window *m_window;
};

}
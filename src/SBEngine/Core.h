#include <memory>
#include <vector>

class Entity; // Forward declaration
class Environment;
class Keyboard;

class Core
{
public:
	std::shared_ptr<Core> Initialise();
	std::shared_ptr<Entity> AddEntity();

	void Start();
	void Stop();
private:
	std::vector<std::shared_ptr<Entity>> entities;

	std::shared_ptr<Environment> environment;
	std::shared_ptr<Keyboard> keyboard;
	bool running;
};
#include <memory>

class Entity;
class Environment;

class Core
{
public:
	std::shared_ptr<Core> Initialise();

	std::shared_ptr<Entity> AddEntity();

	void Start();
	void Stop();

private:
	std::shared_ptr<Environment> environment;
};
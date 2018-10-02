

class Environment
{
public:
	Environment();
	~Environment();

	float getDeltaTime() { return deltaTime; }

private:
	float deltaTime;
};
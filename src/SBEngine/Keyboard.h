#include <vector>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

private:
	std::vector<int> keyCodes;
};
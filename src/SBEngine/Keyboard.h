#include <vector>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	//bool getKey(keyCode:int);

private:
	std::vector<int> keyCodes;
};
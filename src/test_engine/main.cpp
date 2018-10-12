#include <SBEngine/SBEngine.h>

#include <iostream>

class TestScreen : public SBEngine::Component
{
public:
	//void OnTick()
	//{
	//	std::cout << "hello" << std::endl;;
	//}
};

int main()
{
	std::shared_ptr<SBEngine::Core> core = SBEngine::Core::Initialise(); //call the initialisation of Core.

	std::shared_ptr<SBEngine::Entity> entity = core->AddEntity(); //creates our first entity, for use on the following lines.

	//std::shared_ptr<SBEngine::Audio> audio = std::make_shared<SBEngine::Audio>("../resources/sounds/dixie_horn.ogg");
	//audio->Play();

	core->Start();

	return 0;
}
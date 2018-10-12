#include <SBEngine/SBEngine.h>

#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>

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
	//ALCdevice* dev = NULL;
	//ALCcontext* con = NULL;

	//dev = alcOpenDevice(NULL);
	//con = alcCreateContext(dev, NULL);
	//alcMakeContextCurrent(con);

	//make context null, then destroy the context, then close the device.

	std::shared_ptr<SBEngine::Core> core = SBEngine::Core::Initialise(); //call the initialisation of Core.

	std::shared_ptr<SBEngine::Entity> entity = core->AddEntity(); //creates our first entity, for use on the following lines.

	std::shared_ptr<SBEngine::Audio> audio = std::make_shared<SBEngine::Audio>("../resources/sounds/dixie_horn.ogg");
	audio->Play();

	core->Start();

	return 0;
}
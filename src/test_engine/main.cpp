#include <SBEngine/SBEngine.h>

#include <iostream>

class Player : public Component
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

	//CORE->START


	bool quit = false;

	while (!quit)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

		}

		//myTriangle.Draw();

		std::shared_ptr<Core> core = std::make_shared<Core>();
		std::shared_ptr<Entity> player = core->AddEntity();
		player->AddComponent<Player>();

		core->Start();

		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
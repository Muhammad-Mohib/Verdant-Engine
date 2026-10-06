#include "Application.h"
#include<iostream>

class Game : public Application
{
protected:
	void OnStart() override
	{

	}

	void OnUpdate(float deltaTime) override
	{
		std::cout << "Hello Game From Game" << deltaTime << std::endl;
	}
};

int main()
{
	Game game;
	game.Run();

	return 0;
}
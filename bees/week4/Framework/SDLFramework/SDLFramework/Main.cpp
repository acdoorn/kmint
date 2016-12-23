#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "MovingEntity.h"
#include "Vector2D.h"
#include "GameWorld.h"

int main(int args[])
{
	

	try{
	const int screenwidth = 1000;
	const int screenheight = 700;

	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication(100,100,screenwidth,screenheight);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	
	SDL_Texture* m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/arrow.png");


	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	
	//used to check time between updates
	int oldTime = SDL_GetTicks();
	GameWorld game;

	game.addObject();


	Vector2D v1 = Vector2D(2, 4);
	Vector2D v2 = Vector2D(3, 5);

	std::cout << "Vector 1: "<< v1 << std::endl;
	std::cout << "Vector 2: " << v2 << std::endl;
	std::cout << "Opposite Vector 2: " << v2.opposite() << std::endl;
	std::cout << "Distance: " << v1.distanceTo(v2) << std::endl;
	std::cout << "v1 Normalized : " << v1.normalized() << std::endl;
	std::cout << "v1 Normalized length : " << v1.normalized().getLength() << std::endl;
	

	std::cout << (v1 /4).getX() << "  " << (v1/4).getY() << std::endl; ;
	const int maxFps = 15;
	//while (true){}
	while (application->IsRunning())
	{
		double newTime = SDL_GetTicks();
		double deltaTime = newTime - oldTime;
		double timeDifference = deltaTime / 1000;

			oldTime = newTime;
			application->StartTick();

			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					application->Quit();
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_w:
						break;
					default:
						break;
					}
				}
			}



			game.update(timeDifference);
			game.draw();
			// For the background
			application->SetColor(Color(255, 255, 255, 255));

			application->UpdateGameObjects();
			


			//application->DrawText("Welcome to KMint", screenwidth / 2, screenheight / 2);
			/*
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					FWApplication::GetInstance()->DrawTexture(m_texture, x * 100, y * 100, 100, 100);
				}
			}
			*/
			application->EndTick();
		
			application->RenderGameObjects();
		
	}
	}
	catch (...) {
		std::cout << "Exception occurred";
	}
	return EXIT_SUCCESS;
}
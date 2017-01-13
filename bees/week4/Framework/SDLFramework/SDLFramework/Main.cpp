#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "MovingEntity.h"
#include "Vector2D.h"
#include "GameWorld.h"
#include "Helper.h"

int main(int args[])
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << Helper::getRandomDouble(1,100) << std::endl;
	}

	try{
	const int screenwidth = 600;
	const int screenheight = 600;

	//om het spel sneller te laten verlopen
	double multiplier = 1;

	//window wordt niet gebruikt?
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication(100,100,screenwidth,screenheight);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	
	SDL_Texture* map_texture = FWApplication::GetInstance()->LoadTexture("../Resources/map.png");


	application->SetTargetFPS(90);
	application->SetColor(Color(255, 10, 40, 255));

	
	//used to check time between updates
	int oldTime = SDL_GetTicks();
	GameWorld game;

	game.addObject();


	
	
	while (application->IsRunning())
	{
		double newTime = SDL_GetTicks();
		double deltaTime = newTime - oldTime;
		double timeDifference = (deltaTime / 1000)*multiplier;

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
					switch (event.key.keysym.sym) 
					{
					case SDLK_w:
						break;
					default:
						break;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					switch (event.button.button)
					{
					case(SDL_BUTTON_LEFT) :
						multiplier = 1;
						break;
					case(SDL_BUTTON_RIGHT) :
						multiplier = 0;
						break;
					default:
						break;
					}
					break;
				case SDL_MOUSEWHEEL:
					if (event.wheel.y > 0)
					{

						multiplier += 0.1;
					}
					else if (event.wheel.y < 0)
					{
						if (multiplier > 0.1)
						{
							multiplier -= 0.1;
						}
					}
					

				}
			}

			application->DrawTexture(map_texture, 0, 0);

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
	catch (const std::exception &exc)
	{
		// catch anything thrown within try block that derives from std::exception
		std::cout << exc.what();
	}
	catch (...) {
		std::cout << "Exception occurred";
	}
	return EXIT_SUCCESS;
}
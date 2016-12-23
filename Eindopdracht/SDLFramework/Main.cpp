#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "Graph.h"
#include "Bee.h"
#include "Beekeeper.h"


int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	auto graph = new Graph();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 255, 255, 255));


	// Dancing Bee
	Bee *bee = new Bee();

	Beekeeper *beekeeper = new Beekeeper(graph, bee);


	application->AddRenderable(bee);
	application->AddRenderable(beekeeper);
	//while (true){}
	while (application->IsRunning())
	{
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
				switch (event.key.keysym.sym){

				default:
					break;
				}
			}
		}
		
		// This is example code, replace with your own!

		// Draw background
		SDL_Texture *background = application->LoadTexture("map.png");
		application->DrawTexture(background, 0, 0);
		
		// Text drawing
		/*application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to KMint", 400, 300);*/
		

		// For the background
		//application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
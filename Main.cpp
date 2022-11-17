//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <ostream>
#include <SDL_ttf.h>

#include "App.h"

//Screen dimension constants
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 680;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	SDL_Renderer* renderer = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		TTF_Init();
		//Create window
		window = SDL_CreateWindow("Baby App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			renderer = SDL_CreateRenderer(window, 1, SDL_RENDERER_SOFTWARE);
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);
		}
	}

	//init app
	App* app = new App(renderer);

	//Test sector
	app->Milk.changeItemQuantity(1000); //add 1000 Milk to Milk
	app->list.addToList(app->Milk); //Push milk in shoppingList
	cout << app->stock.getStockQuantity(); //Display on console mill quantity in stock (should be 0 at the begining)

	//CREATE ALL RECT AND BUTTON
	app->createContainer(renderer, 0, "", 0, 0, 840, 680, 0, 0, 0, false, false);
	app->createContainer(renderer, 0, "Liste de course", 0, 0, 230, 40, 255, 255, 255, false, true);
	app->createContainer(renderer, 1, "", 0, 0, 230, 680, 0, 0, 0, false, false);
	app->createContainer(renderer, 2, "Valider", 10, 635, 210, 30, 0, 0, 0, true, false);
	app->createContainer(renderer, 3, "Prendre Biberon", 240, 635, 300, 30, 0, 0, 0, true, false);
	app->createContainer(renderer, 4, "Biberon Vomit", 550, 635, 280, 30, 0, 0, 0, true, false);
	app->createContainer(renderer, 5, "Remplir Biberon", 240, 595, 300, 30, 0, 0, 0, true, false);
	app->createContainer(renderer, 6, "Vider Biberon", 550, 595, 280, 30, 0, 0, 0, true, false);
	
	//MAIN WHILE
	while (app->running)
	{
		app->handleEvent(); //Check for event
		app->update(); //Update everything
		app->render(); //Render everything
	}

	//Destroy window and renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	TTF_Quit();
	SDL_Quit();

	return 0;
}

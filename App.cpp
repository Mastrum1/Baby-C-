#include <iostream>
#include "App.h"

App::App(SDL_Renderer* renderer){
	this->renderer = renderer;
}

App::~App()
{
}

// CHECK FOR EVENT
void App::handleEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			this->running = false; //SDL quit window
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&this->mouseX, &this->mouseY); //Mouse pose
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) this->lClick = true; //Mouse left click pressed
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT) this->lClick = false; //Mouse left click unpressed
			break;
		}
	}
	for (auto i = 0; i < this->containerList.size(); i++)
	{
		this->containerList[i].handleEvent(); //Check if in button
	}
}

void App::update()
{
	if (lClick)
	{
		//cout << "x: " << this->mouseX << endl; //Mouse X position in console
		//cout << "y: " << this->mouseY << endl; //Mouse y position in console
		//cout << "lClick: " << this->lClick << endl; //Left button click in console
		cout << "bib quant" << this->bottle.getFilledAt() << endl; // Milk quantity in bottle
		cout << "stock" << this->stock.getStockQuantity() << endl; // QIantity of milk in stock
	}
}

void App::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	for (auto i = 0; i < this->containerList.size(); i++)
	{
		this->containerList[i].render();
	}
	SDL_RenderPresent(renderer);
}

void App::createContainer(SDL_Renderer* renderer,int id, const char* title, int x, int y, int w, int h, int r, int g, int b, bool isButton, bool isFilled)
{
	this->containerList.push_back(Container::Container(this, renderer, id, title, x, y, w, h, r, g, b, isButton, isFilled));
}
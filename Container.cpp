#include "Container.h"
#include "App.h"

Container::Container(App* app, SDL_Renderer* renderer, int x, int y, int w, int h)
{
	this->app = app;

	this->rect.x = x;
	this->rect.y = y;
	this->rect.w = w;
	this->rect.h = h;

	this->renderer = renderer;
}

Container::~Container()
{

}

void Container::handleEvent()
{
	// POUR BOUTTON
	if (this->app->mouseX > this->rect.x && this->app->mouseX < this->rect.x + this->rect.w  // VERIFY IF IS IN COORDINATES
		&& this->app->mouseY > this->rect.y && this->app->mouseY < this->rect.y + this->rect.h  // VERIFY IF IS IN COORDINATES
		&& this->app->lClick) // VERIFY IF LEFT IS CLICK
		cout << "JE SUIS DEDANS" << endl;
}

void Container::render()
{
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(this->renderer, &this->rect);
}
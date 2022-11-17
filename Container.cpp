#include <SDL_ttf.h>
#include <vector>

#include "Container.h"
#include "App.h"


Container::Container(App* app, SDL_Renderer* renderer,int id, const char* title, int x, int y, int w, int h, int r, int g, int b, bool isButton, bool isFilled)
{
	this->app = app;

	this->rect.x = x;
	this->rect.y = y;
	this->rect.w = w;
	this->rect.h = h;

	this->tRect = this->rect;

	this->id = id;
	this->r = r;
	this->g = g;
	this->b = b;
	this->isButton = isButton;
	this->isFilled = isFilled;

	this->renderer = renderer;

	this->updateTRect();

	this->font = TTF_OpenFont("Milky.ttf", 25);
	this->surface = TTF_RenderText_Blended(this->font, title, this->textColor);
	this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);

}

Container::~Container()
{

}

void Container::updateTRect()
{
	this->tRect.x = (this->rect.x + this->rect.w / 2) - this->tRect.w / 2;
	this->tRect.y = (this->rect.y + this->rect.h / 2) - this->tRect.h / 2;
}

void Container::handleEvent()
{
	// FOR BUTTON
	if (this->app->mouseX > this->rect.x && this->app->mouseX < this->rect.x + this->rect.w  // VERIFY IF IS IN COORDINATES
		&& this->app->mouseY > this->rect.y && this->app->mouseY < this->rect.y + this->rect.h  // VERIFY IF IS IN COORDINATES
		&& this->app->lClick && this->isButton == true) { // VERIFY IF LEFT IS CLICK
		switch (this->id){
			case(2) :
				this->app->list.clearList();
				break;
			case(3) :
				this->app->bottle.drinked(this->app->bottle.getCapacity());
				break;
			case(4) : 

				break;
		}

	} 
		

}

void Container::render()
{
	SDL_SetRenderDrawColor(this->renderer, this->r, this->g, this->b, 255);

	if (isFilled){
		SDL_RenderFillRect(this->renderer, &this->rect);
	} else {
		SDL_RenderDrawRect(this->renderer, &this->rect);
	}

	SDL_QueryTexture(texture, NULL, NULL, &tRect.w, &tRect.h);
	SDL_RenderCopy(this->renderer, texture, NULL, &this->tRect);
	updateTRect();
}
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

Container::~Container(){

}

void Container::updateTRect() // TO CENTER THE TEXT IN BOXES
{
	this->tRect.x = (this->rect.x + this->rect.w / 2) - this->tRect.w / 2; //center text on x
	this->tRect.y = (this->rect.y + this->rect.h / 2) - this->tRect.h / 2; // center text on y
}

void Container::handleEvent()
{
	// FOR BUTTON
	if (this->app->mouseX > this->rect.x && this->app->mouseX < this->rect.x + this->rect.w  // VERIFY IF IS IN COORDINATES
		&& this->app->mouseY > this->rect.y && this->app->mouseY < this->rect.y + this->rect.h  // VERIFY IF IS IN COORDINATES
		&& this->app->lClick && this->isButton == true) { // VERIFY IF LEFT IS CLICK
		switch (this->id){
			case(2) : // CHECK IF "VALIDER" BUTTON IS PRESSED
				this->app->stock.addMilkQuantity(this->app->list.shoppingList[0].getItemQuantity()); //add to stock x amount of milk
				this->app->list.clearList(); //clear list
				this->app->list.addToList(app->Milk); //reset item Milk on list
				this->app->Milk.changeItemQuantity(0); //reset quantity of milk to add
				break;
			case(3) : // CHECK IF "BIBERON PRIT" BUTTON IS PRESSED
				this->app->bottle.drinked(this->app->bottle.getCapacity()); //reset milk quantity in bottle to 0
				break;
			case(4) : // CHECK IF "BIBERON VOMIT" BUTTON IS PRESSED
				//not implemented
				break;
			case(5) : // CHECK IF "REMPLIR BIBERON" BUTTON IS PRESSED
				if (this->app->bottle.getIsEmpty()){
					this->app->bottle.filler(this->app->bottle.getCapacity()); //refill bottle if empty
				}
				break;
			case(6) :// CHECK IF "VIDER BIBERON" BUTTON IS PRESSED
				this->app->bottle.drinked(this->app->bottle.getCapacity()); //reset milk quantity in bottle to 0
				break;
		}
	} 	
}

void Container::render(){ //BUILD RECT WITH THE CHOSED COLOR AND CHECK FOR FILL THE RECT AND DISPLAY THE TEXT
	SDL_SetRenderDrawColor(this->renderer, this->r, this->g, this->b, 255);//Color

	if (isFilled){
		SDL_RenderFillRect(this->renderer, &this->rect); //fill the rect
	} else {
		SDL_RenderDrawRect(this->renderer, &this->rect); //don't fill the rect
	}

	SDL_QueryTexture(texture, NULL, NULL, &tRect.w, &tRect.h); //set the texture for text
	SDL_RenderCopy(this->renderer, texture, NULL, &this->tRect); //render the texture and display the text
	updateTRect();
}
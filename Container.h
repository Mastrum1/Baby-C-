#pragma once
#include <SDL_ttf.h>
#include <SDL.h>

#include "List.h"


class App;

class Container
{
public:
	Container(App* app, SDL_Renderer* renderer,int id, const char* title, int x, int y, int w, int h, int r, int g, int b, bool isButton, bool isFilled);
	~Container();

	void updateTRect();

	void handleEvent();
	void render();

	App* app;
private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
	SDL_Texture* texture;
	SDL_Surface* surface;
	TTF_Font* font;
	SDL_Color textColor = { 0, 0, 0, 255 };
	SDL_Rect tRect;
	int id;
	int r;
	int g;
	int b;
	bool isButton;
	bool isFilled;
};
#pragma once

#include <SDL.h>


class App;

class Container
{
public:
	Container(App* app, SDL_Renderer* renderer, int x, int y, int w, int h);
	~Container();

	void handleEvent();
	void render();

	App* app;
private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
};
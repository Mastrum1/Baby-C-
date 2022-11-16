#pragma once

#include <SDL.h>


class App;

class Container
{
public:
	Container(App* app, SDL_Renderer* renderer, int x, int y, int w, int h, int r, int g, int b, bool isButton);
	~Container();

	void handleEvent();
	void render();

	App* app;
private:
	SDL_Renderer* renderer;
	SDL_Rect rect;
	int r;
	int g;
	int b;
	bool isButton;
};
#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Container.h"

class App
{
public:
	App(SDL_Renderer* renderer);
	~App();

	void handleEvent();
	void update();
	void render();

	void createContainer(SDL_Renderer* renderer, int x, int y, int w, int h, int r, int g, int b, bool isButton);

	bool running = true;
	int mouseX, mouseY;
	bool lClick;
private:
	SDL_Renderer* renderer;


	vector<Container> containerList;
};
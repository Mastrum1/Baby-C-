#pragma once
#include <iostream>
#include <vector>

#include "Container.h"
#include "List.h"
#include "Bottle.h"

using namespace std;

class App
{
public:
	App(SDL_Renderer* renderer);
	~App();

	void handleEvent();
	void update();
	void render();

	void createContainer(SDL_Renderer* renderer,int id, const char* title, int x, int y, int w, int h, int r, int g, int b, bool isButton, bool isFilled);

	Bottle bottle;
	List list;
	
	bool running = true;
	int mouseX, mouseY;
	bool lClick;

private:
	bool alert;
	SDL_Renderer* renderer;
	vector<Container> containerList;
};
#pragma once
#include <iostream>

class Bottle
{
public:
	Bottle(int capacity = 250, int filledAt = 0, bool isEmpty = true, int rest = 0);
	~Bottle();
	void filler(int quantity);
	void drinked(int quantity);

private:
	int capacity;
	int filledAt;
	bool isEmpty; 
	int rest;
};
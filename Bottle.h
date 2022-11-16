#pragma once
#include <iostream>

class Bottle
{
public:
	Bottle(int capacity = 250, int filledAt = 0, bool isEmpty = true, int rest = 0);
	~Bottle();
	int getCapacity();
	int getFilledAt();
	bool getIsEmpty();
	int getRest();
	void filler(int quantity);
	void drinked(int quantity);
	void setNewCapacity(int value);
	bool checkIsEmpty();

private:
	int capacity;
	int filledAt;
	bool isEmpty; 
	int rest;
};
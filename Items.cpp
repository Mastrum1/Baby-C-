#include <iostream>
#include "Items.h"


Items::Items(int id, const char* name, int quantity = 0) {
	this->id = id; 
	this->name = name; 
	this->quantity = quantity; 
}

Items::~Items()
{
}

int Items::getItemId() {
	return this->id; 
}

const char* Items::getItemName() {
	return this->name;
}

int Items::getItemQuantity() {
	return this->quantity;
}

void Items::changeItemQuantity(int value) {
	this->quantity = value; 
}

void Items::addItemQuantity(int value) {
	this->quantity += value;
}

void Items::removeItemQuantity(int value) {
	this->quantity -= value;
}
#include <iostream>
#include "Items.h"


Items::Items() {
	this->id = 0; 
	this->name = "Milk";
	this->quantity = 0; 
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

void Items::changeItemId(int value) {
	this->id = value;
}
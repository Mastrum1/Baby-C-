#include <iostream>
#include "Bottle.h"


Bottle::Bottle(int capacity,int filledAt, bool isEmpty, int rest) {
	this->capacity = capacity;
	this->filledAt = filledAt;
	this->isEmpty = isEmpty;
	this->rest = rest;
}

Bottle::~Bottle()
{
}

int Bottle::getCapacity() {
	return this->capacity;
}

int Bottle::getFilledAt() {
	return this->filledAt;
}

bool Bottle::getIsEmpty() {
	return this->isEmpty;
}

int Bottle::getRest() {
	return this->rest;
}

void Bottle::filler(int quantity) {
	if (quantity>this->capacity){
		this->filledAt = this->capacity;
		this->isEmpty = false;
		this->rest = quantity - this->capacity;
	} else {
		this->filledAt = quantity;
		this->isEmpty = false;
	}
}

void Bottle::drinked(int quantity) {
	if (quantity>this->filledAt) {
		this->filledAt = 0;
		this->isEmpty = true;
	} else {
		this->filledAt -= quantity;
		this->rest = this->capacity - this->filledAt;
	}
}

void Bottle::setNewCapacity(int value) {
	this->capacity = value;
}

bool Bottle::checkIsEmpty() {
	if (this->filledAt <= 0) {
		this->isEmpty = true;
		this->filledAt = 0;
		return this->isEmpty;
	} else {
		this->isEmpty = false; 
		return this->isEmpty;
	}
}
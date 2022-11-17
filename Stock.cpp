#include <iostream>
#include "Stock.h"


Stock::Stock() {
	this->milkQuantity = 0;
}

Stock::~Stock()
{
}

int Stock::getStockQuantity() {
	return this->milkQuantity;
}

void Stock::setMilkQuantity(int value) {
	this->milkQuantity = value;
}

void Stock::addMilkQuantity(int value) {
	this->milkQuantity += value;
}

void Stock::removeMilkQuantity(int value) {
	if (value > this->milkQuantity){
		this->milkQuantity = 0;
	} else {
		this->milkQuantity -= value;
	}
}
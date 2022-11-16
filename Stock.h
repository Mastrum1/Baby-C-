#pragma once
#include <iostream>

class Stock
{
public:
	Stock(int milkQuantity );
	~Stock();
	int getStockQuantity();
	void setMilkQuantity(int value);
	void addMilkQuantity(int value);
	void removeMilkQuantity(int value);

private:
	int milkQuantity;
};

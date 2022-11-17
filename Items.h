#pragma once
#include <iostream>

class Items
{
public:
	Items();
	~Items();
	int getItemId();
	const char* getItemName();
	int getItemQuantity();
	void changeItemQuantity(int value);
	void addItemQuantity(int value);
	void removeItemQuantity(int value);
	void changeItemId(int value);

private:
	int id; 
	const char* name;
	int quantity;

};

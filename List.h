#pragma once
#include <iostream>
#include <vector>
#include "Items.h"

class List
{
public:
	List();
	~List();
	void addToList(Items item);
	void clearList();
	void removeFromList(int id);

private:
	int id;
	std::vector<Items> shoppingList;
};
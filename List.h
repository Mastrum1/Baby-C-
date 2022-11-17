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
	Items getItemNameFromList(int id);
	
	std::vector<Items> shoppingList;
private:
	int id;
	
};
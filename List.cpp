#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "List.h"

using namespace std; 

List::List()
{
	this->id = 0;
}

List::~List()
{
}

void List::addToList(Items item) {
	shoppingList.push_back(item);
}

void List::clearList() {
	shoppingList.clear();
}

void List::removeFromList(int id) {
	if (this->id<id){
		this->id = this->id;
	} else {
		shoppingList.erase(id);
	}
}
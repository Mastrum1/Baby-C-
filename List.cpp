#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "List.h"

using namespace std; 

List::List(){
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
	if (id < shoppingList.size()) {
		Items tmp = shoppingList[id];
		shoppingList[id] = shoppingList[shoppingList.size() - 1];
		shoppingList[id].changeItemId(id);
		shoppingList[shoppingList.size() - 1] = tmp;
		shoppingList.pop_back();
	} 
}
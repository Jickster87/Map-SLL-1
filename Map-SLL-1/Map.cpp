#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	//TODO - Implementation
	head = nullptr;
	sizeMap = 0;
}

Map::~Map() {
	//TODO - Implementation
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

TValue Map::add(TKey c, TValue v){
	//TODO - Implementation
	Node* newNode = new Node(TElem(c, v));

	if (isEmpty()) {
		head = newNode;
	}
	else {
		Node* current = head;

		while (current != nullptr) {
			if (current->elem.first == c) {
				TValue oldValue = current->elem.second;  // why is it right keep old value to return ? - fixed issue with assert s2 = 19, was s2 = 119 
				current->elem.second = v;
				delete newNode;
				return oldValue;
			}
			current = current->next;
		}

		current = head;
		while (current->next != nullptr) {   // warning here, not sure why
			current = current->next;
		}
		current->next = newNode;
	}
	
	sizeMap++;

	return NULL_TVALUE; // purpose??
}

TValue Map::search(TKey c) const{
	//TODO - Implementation
	Node* current = head;

	while (current != nullptr) {
		if (current->elem.first == c) {
			return current->elem.first;
		}
		current = current->next;
	}

	return NULL_TVALUE;
}

TValue Map::remove(TKey c) {
	//TODO - Implementation
	Node* current = head;
	Node* previous = nullptr; // is it still a SLL if I do this :) ?

	// Find node with key c
	while (current != nullptr && current->elem.first != c) {
		previous = current;
		current = current->next;
	}

	// If node not found
	if (current == nullptr) {
		return NULL_TVALUE;
	}

	// If node found at head
	if (previous == nullptr) {
		head = head->next;
	}
	else {
		previous->next = current->next;
	}

	TValue removedValue = current->elem.second; // not sure why second
	delete current;
	this->sizeMap--;

	return removedValue;

}

int Map::size() const {
	//TODO - Implementation
	return this->sizeMap; // confused about syntax with "this->" or without
}

bool Map::isEmpty() const{
	//TODO - Implementation
	return this->sizeMap == 0; 
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
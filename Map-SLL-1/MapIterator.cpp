#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	//TODO - Implementation
	this->currentPosition = map.head;
}


void MapIterator::first() {
	//TODO - Implementation
	this->currentPosition = map.head;
}
 

void MapIterator::next() {
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	if (currentPosition != nullptr) {
		currentPosition = currentPosition->next;
	}
}


TElem MapIterator::getCurrent(){
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	return this->currentPosition->elem;
}


bool MapIterator::valid() const {
	//TODO - Implementation
	return this->currentPosition != nullptr;
}




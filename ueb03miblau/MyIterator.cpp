/**
 * MyIterator.cpp: Iterator-Klasse, die ueber MyDeque-Objekte laufen kann
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include <string>
#include <iostream>
#include <vector>
#include "MyListElement.h"
#include "MyDeque.h"
#include "MyIterator.h"
using namespace std;

MyIterator::MyIterator(const MyDeque& deque){
	this->maxAnzElemente = deque.anzElemente;
	this->position = 0;
	this->current = deque.head;
}

MyListElement MyIterator::next(){
	MyListElement* aktuell = this->current;
	current = current->next;
	position++;
	return *aktuell;
}

bool MyIterator::hasNext(){
	return position < maxAnzElemente;
}

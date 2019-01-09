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

template<class T>
MyIterator<T>::MyIterator(const MyDeque<T>& deque){
	this->maxAnzElemente = deque.anzElemente;
	this->position = 0;
	this->current = deque.head;
}

template<class T>
MyListElement<T> MyIterator<T>::next(){
	MyListElement<T>* aktuell = this->current;
	current = current->next;
	position++;
	return *aktuell;
}

template<class T>
bool MyIterator<T>::hasNext(){
	return position < maxAnzElemente;
}

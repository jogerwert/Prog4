/**
 * MyIterator.c: Iterator-Klasse, die ueber MyDeque-Objekte laufen kann
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#ifndef MYITERATOR_H_
#define MYITERATOR_H_

#include <string>
#include <iostream>
#include <vector>
#include "MyListElement.h"
#include "MyDeque.h"
using namespace std;


template<typename T>
class MyDeque;

template<typename T>
class MyListElement;

template <typename T>
class MyIterator {

private:
	int maxAnzElemente;
	int position;
	MyListElement<T>* current;


public:
	MyIterator(const MyDeque<T>&); //Standard-Konstruktor
	MyListElement<T> next();
	bool hasNext();
};

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

#endif /* MYITERATOR_H_ */

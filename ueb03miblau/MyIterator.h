/**
 * MyIterator.c: Iterator-Klasse, die ueber MyDeque-Objekte laufen kann
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#ifndef MYITERATOR_H_
#define MYITERATOR_H_

#include <string>
#include <iostream>
#include "MyListElement.h"
#include "MyDeque.h"
using namespace std;

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


#endif /* MYITERATOR_H_ */

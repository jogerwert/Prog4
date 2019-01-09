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

class MyIterator{


private:
	int maxAnzElemente;
	int position;
	MyListElement* current; //--muss vom typ her nachher angepasst werden


public:
	MyIterator(const MyDeque&); //Standard-Konstruktor
	MyListElement next();
	bool hasNext();
};



#endif /* MYITERATOR_H_ */

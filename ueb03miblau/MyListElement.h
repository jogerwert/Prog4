/**
 * MyListElement.h: Klasse zur Implementation von Listen-Elementen
 * einer doppelt-verketteten Liste
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#ifndef MYLISTELEMENT_H_
#define MYLISTELEMENT_H_


#include <string>
using namespace std;

class MyListElement {
	friend class MyDeque;
	friend class MyIterator;

private:
	MyListElement* next;
	MyListElement* pre;
	string content;

public:
	MyListElement(); //Standard-Konstruktor

	string getContent();
	string toString();
	string* contentPointer();
};


#endif /* MYLISTELEMENT_H_ */

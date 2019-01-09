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

template <typename T>
class MyListElement {
	friend class MyDeque;
	friend class MyIterator;

private:
	MyListElement<T>* next;
	MyListElement<T>* pre;
	string content;

public:
	MyListElement(); //Standard-Konstruktor

	T getContent();
	T toString();
};


#endif /* MYLISTELEMENT_H_ */

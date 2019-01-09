/**
 * MyListElement.h: Klasse zur Implementation von Listen-Elementen
 * einer doppelt-verketteten Liste
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#ifndef MYLISTELEMENT_H_
#define MYLISTELEMENT_H_


#include <string>
#include "MyDeque.h"
#include "MyIterator.h"
using namespace std;

template <typename T>
class MyListElement {
	template <typename>
	friend class MyDeque;

	template <typename>
	friend class MyIterator;

private:
	MyListElement<T>* next;
	MyListElement<T>* pre;
	T content;

public:
	MyListElement(); //Standard-Konstruktor

	T getContent();
	T toString();
};

/**
 * Standard-Konstruktor
 */
template<class T>
MyListElement<T>::MyListElement(){
	this->next = {nullptr};
	this->pre = {nullptr};
}

template<class T>
T MyListElement<T>::toString(){
	return "Inhalt: " + this->content;
}

template<class T>
T MyListElement<T>::getContent(){
	return this->content;
}

#endif /* MYLISTELEMENT_H_ */

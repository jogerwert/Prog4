/**
 * MyListElement.cpp: Klasse zur Implementation von Listen-Elementen
 * einer doppelt-verketteten Liste
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include "MyListElement.h"

using namespace std;

/**
 * Standard-Konstruktor
 */
template<class T>
MyListElement<T>::MyListElement(){
	this->next = {nullptr};
	this->pre = {nullptr};
	this->content = {""};
}

template<class T>
T MyListElement<T>::toString(){
	return "Inhalt: " + this->content;
}

template<class T>
T MyListElement<T>::getContent(){
	return this->content;
}

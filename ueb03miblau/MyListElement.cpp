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
MyListElement::MyListElement(){
	this->next = {nullptr};
	this->pre = {nullptr};
	this->content = {""};
}

string MyListElement::toString(){
	return "Inhalt: " + this->content;
}

string MyListElement::getContent(){
	return this->content;
}

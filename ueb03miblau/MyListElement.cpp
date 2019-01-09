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
	this->content = {""}; //Leerer String
}

//MyListElement::MyListElement(const MyListElement& zuKopieren){
//	if(zuKopieren.next != nullptr){
//		this->next = new MyListElement();
//	}if(zuKopieren.pre != nullptr){
//		this->pre = new MyListElement();
//	}
//}

string MyListElement::toString(){
	return "Inhalt: " + this->content;
}

string* MyListElement::contentPointer(){
	return &content;
}

/**
 *
 * MyDeque.cpp: Klasse fuer Double-Ended-Queue
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include "MyDeque.h"
#include <string>

using namespace std;

MyDeque::MyDeque(){
	this->anzElemente = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

void MyDeque::push_back(const string& neuerInhalt){
	MyListElement* neuesElement = new MyListElement();
	neuesElement->content = neuerInhalt;

	if(isEmpty()){
		head = neuesElement;
		tail = head;
	}else if(hatGenauEinElement()) {
		tail = neuesElement;
		head->next = tail;
		tail->pre = head;
	}else{
		neuesElement->pre = tail;
		tail->next = neuesElement;
		tail = tail->next;
	}
	anzElemente++;
}

void MyDeque::push_front(const string& neuerInhalt){
	MyListElement* neuesElement = new MyListElement();
	neuesElement->content = neuerInhalt;

	if(isEmpty()){
		head = neuesElement;
		tail = head;
	}else if(hatGenauEinElement()) {
		tail->pre = neuesElement;
		neuesElement->next = tail;
		head = neuesElement;
	}else{
		head->pre = neuesElement;
		neuesElement->next = head;
		head = head->pre;
	}
	anzElemente++;
}

MyListElement* MyDeque::pop_back(){
	MyListElement* entfernt = tail;
	if(isEmpty()){
		cout << "Deque ist Leer!! Exception hier!!" << endl;
	}else if(hatGenauEinElement()){
		tail = nullptr;
		head = nullptr;
	}else if(hatZweiElemente()){
		tail = head;
	}else{
		tail = tail->pre;
		tail->next = nullptr;
	}
	anzElemente--;

	return entfernt;
}

MyListElement* MyDeque::pop_front(){
	MyListElement* entfernt = head;
	if(isEmpty()){
		cout << "Deque ist Leer!! Exception hier!!" << endl;
	}else if(hatGenauEinElement()){
		tail = nullptr;
		head = nullptr;
	}else if(hatZweiElemente()){
		head = tail;
	}else{
		head = head->next;
		head->pre = nullptr;
	}
	anzElemente--;

	return entfernt;
}

inline bool MyDeque::isEmpty(){
	return (anzElemente <= 0);
}

inline bool MyDeque::hatGenauEinElement(){
	return (anzElemente == 1);
}

inline bool MyDeque::hatZweiElemente(){
	return (anzElemente == 2);
}

string MyDeque::toString(){
	string ergebnis = "";
	MyListElement* cur = head; //Impliziter Aufruf des Kopierkonstr.
	for(int i = 0; i < anzElemente; i++){
		ergebnis.append(cur->content);
		cur = cur->next;
	}
	return ergebnis;
}

void MyDeque::adressenAusgeben(){
	cout << anzElemente << "<-aktuelle Anzahl Elemente" << endl;
	cout << head << "<- Adresse head | " << tail << "<- Adresse tail" << endl;
}

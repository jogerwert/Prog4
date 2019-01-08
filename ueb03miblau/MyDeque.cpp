/**
 *
 * MyDeque.cpp: Klasse fuer Double-Ended-Queue
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include "MyDeque.h"
#include "MyIterator.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

MyDeque::MyDeque(){
	this->anzElemente = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

MyDeque::MyDeque(const vector<string>& stringVector){
	this->anzElemente = 0;
	this->head = nullptr;
	this->tail = nullptr;

	for(string s : stringVector){
		push_back(s);
	}
}

MyDeque::MyDeque(const MyDeque& zuKopieren){
	MyIterator iterator(zuKopieren);
	while(iterator.hasNext()){
		//mach kopien
	}
}


MyDeque& MyDeque::operator=(MyDeque zuZuweisen){
	swap(this->anzElemente, zuZuweisen.anzElemente);
	swap(this->head, zuZuweisen.head);
	swap(this->tail, zuZuweisen.tail);

	return *this;
}

bool MyDeque::operator==(const MyDeque& a) {
	cout << "== Operator wird benutzt" << endl;
	if(this->anzElemente != a.anzElemente){
		cout << "Anzahl Elemente beider Deques ungleich!!!" << endl;
		return false;
	}
	bool ergebnis = true;
	MyIterator iteratorVergleich(a);
	MyIterator iteratorOriginal(*this);

	MyListElement vergleich = iteratorVergleich.next();
	MyListElement original = iteratorOriginal.next();

	while(iteratorVergleich.hasNext()){
		if(vergleich.content != original.content){
			ergebnis = false;
			cout << "Elemente beider Deques ungleich!!!" << endl;
		}
		vergleich = iteratorVergleich.next();
		original = iteratorOriginal.next();
	}
	return ergebnis;
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

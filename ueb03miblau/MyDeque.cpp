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

template<class T>
MyDeque<T>::MyDeque(){
	this->anzElemente = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template<class T>
MyDeque<T>::MyDeque(const vector<T>& vec){
	this->anzElemente = 0;
	this->head = nullptr;
	this->tail = nullptr;

	for(T t : vec){
		push_back(t);
	}
}

template<class T>
MyDeque<T>::MyDeque(const MyDeque<T>& zuKopieren){
	MyIterator<T> iterator(zuKopieren);
	MyDeque<T>* kopie = new MyDeque<T>();

	while(iterator.hasNext()){
		kopie->push_back(iterator.next().content);
	}
	this->head = kopie->head;
	this->tail = kopie->tail;
	this->anzElemente = kopie->anzElemente;
	cout << "MyDeque::Kopierkonstruktor" << endl;
}

template<class T>
MyDeque<T>::~MyDeque(){
	while(!isEmpty()){
		this->pop_back();
	}
	cout << "MyDeque::Destruktor" << endl;
}

template<class T>
MyDeque<T>& MyDeque<T>::operator=(MyDeque zuZuweisen){
	swap(this->anzElemente, zuZuweisen.anzElemente);
	swap(this->head, zuZuweisen.head);
	swap(this->tail, zuZuweisen.tail);
	cout << "MyDeque::Zuweisungsoperator" << endl;
	return *this;
}

template<class T>
bool MyDeque<T>::operator==(const MyDeque<T>& a) {
	if(this->anzElemente != a.anzElemente){
		return false;
	}
	bool ergebnis = true;
	MyIterator<T> iteratorVergleich(a);
	MyIterator<T> iteratorOriginal(*this);

	MyListElement<T> vergleich = iteratorVergleich.next();
	MyListElement<T> original = iteratorOriginal.next();

	while(iteratorVergleich.hasNext()){
		if(vergleich.content != original.content){
			ergebnis = false;
		}
		vergleich = iteratorVergleich.next();
		original = iteratorOriginal.next();
	}
	return ergebnis;
}


template<class T>
bool MyDeque<T>::operator!=(const MyDeque<T>& md){
	return !(*this == md);
}


template<class T>
MyDeque<T> MyDeque<T>::operator+(const MyDeque<T>& md){
	MyDeque<T> ergebnis(*this);
	MyIterator<T> iterator(md);

	while(iterator.hasNext()){
		ergebnis.push_back(iterator.next().content);
	}
	cout << "MyDeque::operator+" << endl;
	return ergebnis;
}

template<class T>
MyDeque<T>& MyDeque<T>::operator+=(const MyDeque<T>& md){
	MyIterator<T> iterator(md);

	while(iterator.hasNext()){
		this->push_back(iterator.next().content);
	}

	return *this;
}

template<class T>
void MyDeque<T>::push_back(const T& neuerInhalt){
	MyListElement<T>* neuesElement = new MyListElement<T>();
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

template<class T>
void MyDeque<T>::push_front(const T& neuerInhalt){
	MyListElement<T>* neuesElement = new MyListElement<T>();
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

template<class T>
void MyDeque<T>::pop_back(){
	MyListElement<T>* entfernt = tail;
	if(isEmpty()){
		cout << "Deque ist Leer!!" << endl;
	}else if(hatGenauEinElement()){
		delete tail;
		tail = nullptr;
		delete head;
		head = nullptr;
		anzElemente--;
	}else if(hatZweiElemente()){
		tail = head;
		anzElemente--;
	}else{
		tail = tail->pre;
		tail->next = nullptr;
		anzElemente--;
	}

	if(entfernt != nullptr){
		delete entfernt;
	}
}

template<class T>
void MyDeque<T>::pop_front(){
	MyListElement<T>* entfernt = head;
	if(isEmpty()){
		cout << "Deque ist Leer!!" << endl;
	}else if(hatGenauEinElement()){
		delete tail;
		tail = nullptr;
		delete head;
		head = nullptr;
		anzElemente--;
	}else if(hatZweiElemente()){
		head = tail;
		anzElemente--;
	}else{
		head = head->next;
		head->pre = nullptr;
		anzElemente--;
	}

	if(entfernt != nullptr){
		delete entfernt;
	}
}

template<class T>
inline bool MyDeque<T>::isEmpty(){
	return (anzElemente <= 0);
}

template<class T>
inline bool MyDeque<T>::hatGenauEinElement(){
	return (anzElemente == 1);
}

template<class T>
inline bool MyDeque<T>::hatZweiElemente(){
	return (anzElemente == 2);
}

template<class T>
string MyDeque<T>::toString(){
	string ergebnis = "";
	MyListElement<T>* cur = head; //Impliziter Aufruf des Kopierkonstr.
	for(int i = 0; i < anzElemente; i++){
		ergebnis.append(cur->content);
		ergebnis.append(" ");
		cur = cur->next;
	}
	return ergebnis;
}

template<class T>
void MyDeque<T>::adressenAusgeben(){
//	cout << anzElemente << "<-aktuelle Anzahl Elemente" << endl;
//	cout << head << "<- Adresse head | " << tail << "<- Adresse tail" << endl;
}

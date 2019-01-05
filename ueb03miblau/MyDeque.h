/**
 *
 * MyDeque.h: Klasse fuer Double-Ended-Queue
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#ifndef MYDEQUE_H_
#define MYDEQUE_H_

#include <string>
#include <iostream>
#include "MyListElement.h"
using namespace std;

class MyDeque{

private:
	int anzElemente;
	MyListElement* head; //--muss vom typ her nachher angepasst werden
	MyListElement* tail; //__|

	void adressenAusgeben();

public:
	MyDeque(); //Standard-Konstruktor
	MyDeque(const MyDeque&); //Kopierkonstruktor
	~MyDeque(); //Destruktor
	MyDeque& operator=(const MyDeque&); //Zuweisungsoperator

	void push_back(const string&); //spaeter Typ aendern
	void push_front(const string&);

	MyListElement* pop_back();
	MyListElement* pop_front();

	inline bool isEmpty();
	inline bool hatGenauEinElement();
	inline bool hatZweiElemente();

	string toString();

};

#endif /* MYDEQUE_H_ */

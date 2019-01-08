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
#include <vector>
#include "MyListElement.h"
using namespace std;

class MyDeque{
	friend class MyIterator;

private:
	int anzElemente;
	MyListElement* head; //--muss vom typ her nachher angepasst werden
	MyListElement* tail; //__|

	void adressenAusgeben();

public:
	MyDeque(); //Standard-Konstruktor
	MyDeque(const vector<string>&);
	MyDeque(const MyDeque&); //Kopierkonstruktor
	~MyDeque(); //Destruktor
	MyDeque& operator=(MyDeque); //Zuweisungsoperator
	bool operator== (const MyDeque&);
	bool operator!= (const MyDeque&);
	MyDeque operator+(const MyDeque&);

	void push_back(const string&); //spaeter Typ aendern
	void push_front(const string&);

	void pop_back();
	void pop_front();

	inline bool isEmpty();
	inline bool hatGenauEinElement();
	inline bool hatZweiElemente();

	string toString();

};

#endif /* MYDEQUE_H_ */

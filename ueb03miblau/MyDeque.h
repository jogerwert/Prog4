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

template <typename T>
class MyDeque{
	friend class MyIterator;

private:
	int anzElemente;
	MyListElement<T>* head;
	MyListElement<T>* tail;

	void adressenAusgeben();

public:
	MyDeque(); //Standard-Konstruktor
	MyDeque(const vector<T>&);
	MyDeque(const MyDeque&); //Kopierkonstruktor
	~MyDeque(); //Destruktor
	MyDeque<T>& operator=(MyDeque); //Zuweisungsoperator
	bool operator== (const MyDeque&);
	bool operator!= (const MyDeque&);
	MyDeque<T> operator+(const MyDeque&);
	MyDeque<T>& operator+=(const MyDeque&);

	void push_back(const T&);
	void push_front(const T&);

	void pop_back();
	void pop_front();

	inline bool isEmpty();
	inline bool hatGenauEinElement();
	inline bool hatZweiElemente();

	string toString();

};

#endif /* MYDEQUE_H_ */

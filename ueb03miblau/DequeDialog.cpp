/**
 * DequeDialog.cpp: Dient zum Testen der Klasse MyDeque
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include "MyDeque.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	MyDeque* testDeque = new MyDeque();
	testDeque->push_front("Hallo  ");
	testDeque->push_front("Wie  ");
	testDeque->push_front("Geht  ");
	testDeque->push_front("Denn  ");
	testDeque->push_front("C++  ");
	testDeque->push_front("eigentlich  ");
	testDeque->push_front("so  ");

	cout << testDeque->toString() << " <- Das ist der Inhalt" << endl;

	testDeque->pop_front();
	testDeque->pop_front();
	testDeque->pop_front();
	//testDeque->pop_front();
	//testDeque->pop_front();
	//testDeque->pop_front();
	//testDeque->pop_front();
	//testDeque->pop_front();


	cout << testDeque->toString() << " <- Das ist der Inhalt nach entfernen" << endl;


}

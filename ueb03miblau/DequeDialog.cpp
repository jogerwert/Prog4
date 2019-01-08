/**
 * DequeDialog.cpp: Dient zum Testen der Klasse MyDeque
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include "MyDeque.h"
#include "MyIterator.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){

	vector<string> stringVector;
	stringVector.push_back("Hallo ");
	stringVector.push_back("Wie ");
	stringVector.push_back("Geht ");
	stringVector.push_back("C++  ");
	stringVector.push_back("eigentlich ");

	MyDeque* testDeque = new MyDeque(stringVector);

	cout << testDeque->toString() << " <- Das ist der Inhalt" << endl;

	testDeque->pop_front();
	testDeque->pop_front();
	testDeque->pop_front();

//	stringVector.push_back("eigentlich ");
//	stringVector.push_back("eigentlich ");
//	stringVector.push_back("eigentlich ");

	MyDeque* testDeque2 = new MyDeque(stringVector);

	testDeque2->pop_front();
	testDeque2->pop_front();
	testDeque2->pop_front();


	cout << testDeque->toString() << " <- Das ist der Inhalt nach entfernen" << endl;
	cout << testDeque2->toString() << " <- Das ist der Inhalt nach entfernen" << endl;

	bool vergleich {*testDeque == *testDeque2};
	cout << boolalpha << "Vergleich == ->" << vergleich << endl;

}

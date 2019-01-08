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

void tue_nichts(MyDeque* test){

}

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

	MyDeque* testDeque2 = new MyDeque(*testDeque);

	testDeque2->pop_back();
	testDeque2->pop_back();

	testDeque2->push_back("Gandalf");



	cout << testDeque->toString() << " <- Das ist der Inhalt nach entfernen" << endl;
	cout << testDeque2->toString() << " <- Das ist der Inhalt nach entfernen" << endl;

	bool vergleich1 {*testDeque == *testDeque2};
	bool vergleich2 {*testDeque != *testDeque2};
	cout << boolalpha << "Vergleich == ->" << vergleich1 << endl;
	cout << boolalpha << "Vergleich != ->" << vergleich2 << endl;


	//tue_nichts(testDeque2);
	//cout << "Destruktor hat geklappt? " << testDeque2->toString() << endl;

	*testDeque = (*testDeque) + (*testDeque2) + (*testDeque2) ;
	cout << testDeque->toString() << " <- Ergebnis operator+" << endl;
}

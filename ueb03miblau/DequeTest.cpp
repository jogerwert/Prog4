/**
 * DequeTest.cpp: Dient zum Testen der Klasse MyDeque
 * @author Michelle Blau
 * @author Johannes Gerwert
 */

#include "MyDeque.h"
#include "MyIterator.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/**Konstanten**/
constexpr auto PROGRAMM_ENDE   = 0;
constexpr auto PUSH_BACK	   = 1;
constexpr auto PUSH_FRONT 	   = 2;
constexpr auto POP_BACK 	   = 3;
constexpr auto POP_FRONT 	   = 4;
constexpr auto KONSTRUKTION_MIT_ARRAY 	 = 5;
constexpr auto KOPIERKONST_ZUWEISUNGS_OP = 6;
constexpr auto VERGLEICHE 	  = 7;
constexpr auto ANHAENGEN 	  = 8;
constexpr auto ELEMENTZUGRIFF = 9;

/**Funktions-Prototypen**/
int auswaehlen();
void ausfuehren(int, MyDeque&, MyDeque&);
void push_back_ausfuehren(MyDeque&);
void push_front_ausfuehren(MyDeque&);
void anlegen_mittels_array(MyDeque&, MyDeque&);

/**
 * Haupt-Schleife
 */
int main(int argc, char** argv){

	MyDeque* testDeque1 = new MyDeque();
	MyDeque* testDeque2 = new MyDeque();

	int funktionsAuswahl { -1 };
	while(funktionsAuswahl != PROGRAMM_ENDE ){

		funktionsAuswahl = auswaehlen();
		ausfuehren(funktionsAuswahl, *testDeque1, *testDeque2);
	}
	return 0;
}

/**
 * Zeigt eine Auswahl an Funktionen an
 * @return zahl, die Funktion repraesentiert
 */
int auswaehlen(){
	int auswahl { 0 };

	cout << "---Funktions-Auswahl:---" << endl;
	cout << "push_back: " << PUSH_BACK << endl;
	cout << "push_front: " << PUSH_FRONT << endl;
	cout << "pop_back: " << POP_BACK << endl;
	cout << "pop_front: " << POP_FRONT << endl;
	cout << "Konstruktion mit Array von char-Strings: " << KONSTRUKTION_MIT_ARRAY << endl;
	cout << "Kopierkonstruktor, Zuweisungsoperator: " << KOPIERKONST_ZUWEISUNGS_OP << endl;
	cout << "Operator== und Operator!=: " << VERGLEICHE << endl;
	cout << "Operator+ und Operator+=: " << ANHAENGEN << endl;
	cout << "Operator[]: " << ELEMENTZUGRIFF << endl;
	cout << "Programm beenden: " << PROGRAMM_ENDE << endl;

	cin >> auswahl;
	return auswahl;
}

/**
 * Fuehrt gewaehlte Funktion auf testDeque1 und/oder testDeque2 aus
 */
void ausfuehren(int auswahl, MyDeque& testDeque1, MyDeque& testDeque2){
	switch(auswahl){
	case PUSH_BACK:
		push_back_ausfuehren(testDeque1);
		break;

	case PUSH_FRONT:
		push_front_ausfuehren(testDeque1);
		break;

	case POP_BACK:
		testDeque1.pop_back();
		break;

	case POP_FRONT:
		testDeque1.pop_front();
		break;

	case KONSTRUKTION_MIT_ARRAY:
		anlegen_mittels_array(testDeque1, testDeque2);
		break;

	case KOPIERKONST_ZUWEISUNGS_OP:
//		teste_kopierkonst_zuweisung(testDeque1, testDeque2);
		break;

	case VERGLEICHE:
//		vergleiche(testDeque1, testDeque2);
		break;

	case ANHAENGEN:
		//anhaengen(testDeque1, testDeque2);
		break;

	case ELEMENTZUGRIFF:
		//elementzugriff(testDeque1);
		break;

	case PROGRAMM_ENDE:
		cout << "Programm wurde beendet" << endl;
		break;

	default: cout << "Keine gueltige Eingabe" << endl;

	}
	cout << "\nInhalt testDeque1: " << testDeque1.toString() << endl;
	cout << "Inhalt testDeque2: " << testDeque2.toString() << endl;
}


void push_back_ausfuehren(MyDeque& testDeque1){
	string eingabe{};
	cout << "Wert eingeben: " << endl;
	cin >> eingabe;

	testDeque1.push_back(eingabe);
}

void push_front_ausfuehren(MyDeque& testDeque1){
	string eingabe{};
	cout << "Wert eingeben: " << endl;
	cin >> eingabe;

	testDeque1.push_front(eingabe);
}

void anlegen_mittels_array(MyDeque& testDeque1, MyDeque& testDeque2){
	vector<string> vector;

	MyIterator iterator(testDeque1);
	while(iterator.hasNext()){
		vector.push_back(iterator.next().getContent());
	}

	MyDeque tmpDeque(vector);
	testDeque2 = tmpDeque;
}




















//	vector<string>* stringVector = new vector<string>();
//	stringVector->push_back("Eins ");
//	stringVector->push_back("Zwei ");
//	stringVector->push_back("Drei ");
//	stringVector->push_back("Vier ");
//	stringVector->push_back("Fuenf ");
//
//
//
//
//	MyDeque* testDeque = new MyDeque(*stringVector);
//
//	cout << testDeque->toString() << " <- Das ist der Inhalt" << endl;




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
constexpr auto PROGRAMM_ENDE   = 10;
constexpr auto PUSH_BACK	   = 1;
constexpr auto PUSH_FRONT 	   = 2;
constexpr auto POP_BACK 	   = 3;
constexpr auto POP_FRONT 	   = 4;
constexpr auto KONSTRUKTION_MIT_ARRAY 	 = 5;
constexpr auto KOPIERKONST_ZUWEISUNGS_OP = 6;
constexpr auto VERGLEICHE 	  = 7;
constexpr auto ANHAENGEN 	  = 8;
constexpr auto ELEMENTZUGRIFF = 9;

constexpr auto TESTE_INT = 1;
constexpr auto TESTE_STRING = 2;

/**Funktions-Prototypen**/
int auswaehlen();

template<class T>
void ausfuehren(int, MyDeque<T>&, MyDeque<T>&);

template<class T>
void push_back_ausfuehren(MyDeque<T>&);

template<class T>
void push_front_ausfuehren(MyDeque<T>&);

template<class T>
void anlegen_mittels_array(MyDeque<T>&, MyDeque<T>&);

template<class T>
void teste_kopierkonst_zuweisung(MyDeque<T>&, MyDeque<T>&);

template<class T>
void vergleiche(MyDeque<T>&, MyDeque<T>&);

template<class T>
void anhaengen(MyDeque<T>&, MyDeque<T>&);

/**
 * Haupt-Schleife
 */
int main(int argc, char** argv){

	MyDeque<string>* testDeque1 = new MyDeque<string>();
	MyDeque<string>* testDeque2 = new MyDeque<string>();

//	int funktionsAuswahl { -1 };
//	while(funktionsAuswahl != PROGRAMM_ENDE ){
//
//		funktionsAuswahl = auswaehlen();
//		ausfuehren(funktionsAuswahl, *testDeque1, *testDeque2);
//
//	return 0;
//	}
}

/**
 * Zeigt eine Auswahl an Funktionen an
 * @return zahl, die Funktion repraesentiert
 */
int auswaehlen(){
	int auswahl { 0 };

	cout << "---Funktions-Auswahl:---" << endl;
	cout <<  PUSH_BACK << " push_back" << endl;
	cout <<  PUSH_FRONT << " push_front" << endl;
	cout <<  POP_BACK <<" pop_back" <<  endl;
	cout <<  POP_FRONT <<" pop_front" << endl;
	cout <<  KONSTRUKTION_MIT_ARRAY <<" Konstruktion mit Array von char-Strings, Zuweisungsoperator" << endl;
	cout <<  KOPIERKONST_ZUWEISUNGS_OP <<" Kopierkonstruktor, Zuweisungsoperator" << endl;
	cout <<  VERGLEICHE <<" Operator== und Operator!=" << endl;
	cout <<  ANHAENGEN << " Operator+ und Operator+=" <<endl;
	cout <<  ELEMENTZUGRIFF << " Operator[] " << endl;
	cout <<  PROGRAMM_ENDE <<" Programm beenden" << endl;

	cin >> auswahl;
	return auswahl;
}

/**
 * Fuehrt gewaehlte Funktion auf testDeque1 und/oder testDeque2 aus
 */
template<class T>
void ausfuehren(int auswahl, MyDeque<T>& testDeque1, MyDeque<T>& testDeque2){
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
		//anlegen_mittels_array(testDeque1, testDeque2);
		break;

	case KOPIERKONST_ZUWEISUNGS_OP:
		teste_kopierkonst_zuweisung(testDeque1, testDeque2);
		break;

	case VERGLEICHE:
		vergleiche(testDeque1, testDeque2);
		break;

	case ANHAENGEN:
		anhaengen(testDeque1, testDeque2);
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


/**
 * Fügt Nutzereingabe an Ende der Deque ein
 */
template<class T>
void push_back_ausfuehren(MyDeque<T>& testDeque1){
	T eingabe{};
	cout << "Wert eingeben: " << endl;
	cin >> eingabe;

	testDeque1.push_back(eingabe);
}

/**
 * Fügt Nutzereingabe an Anfang der Deque ein
 */
template<class T>
void push_front_ausfuehren(MyDeque<T>& testDeque1){
	T eingabe{};
	cout << "Wert eingeben: " << endl;
	cin >> eingabe;

	testDeque1.push_front(eingabe);
}

/**
 * Allokiert dynamisch temporäre Deque, ruft Zuweisungsoperator auf
 */
template<class T>
void anlegen_mittels_array(MyDeque<T>& testDeque1, MyDeque<T>& testDeque2){
	vector<T> vector;

	MyIterator<T> iterator(testDeque1);
	while(iterator.hasNext()){
		vector.push_back(iterator.next().getContent());
	}

	MyDeque<T>* tmpDeque = new MyDeque<T>(vector);
	testDeque2 = *tmpDeque;
}


/**
 * Fuehrt Kopierkonstruktor und dann Zuweisungsoperator aus
 */
template<class T>
void teste_kopierkonst_zuweisung(MyDeque<T>& testDeque1,MyDeque<T>& testDeque2){
	MyDeque<T>* tmpDeque = new MyDeque<T>(testDeque1);
	cout << "tmpDeque: " << tmpDeque->toString() << endl;
	testDeque2 = *tmpDeque;
}

/**
 * Fuehrt Vergleich "==" und "!=" aus
 */
template<class T>
void vergleiche(MyDeque<T>& testDeque1, MyDeque<T>& testDeque2){
	cout << boolalpha << "Vergleich == : " << (testDeque1==testDeque2) << endl;
	cout << boolalpha << "Vergleich != : " << (testDeque1!=testDeque2) << endl;
}

/**
 * Demonstiert "+" und "+="
 */
template<class T>
void anhaengen(MyDeque<T>& testDeque1, MyDeque<T>& testDeque2){
	MyDeque<T> tmpDeque = testDeque1 + testDeque2;
	cout << "testDeque1 + testDeque2: " << (tmpDeque).toString() << endl;

	testDeque2 += testDeque1;
	cout << "testDeque2 += testDeque1 " << (testDeque2).toString() << endl;

}

//template<class T>
//void start(T t){
//	MyDeque<T>* testDeque1 = new MyDeque<T>();
//	MyDeque<T>* testDeque2 = new MyDeque<T>();
//
//	int funktionsAuswahl { -1 };
//	while(funktionsAuswahl != PROGRAMM_ENDE ){
//
//		funktionsAuswahl = auswaehlen();
//		ausfuehren(funktionsAuswahl, *testDeque1, *testDeque2);
//	}
//}

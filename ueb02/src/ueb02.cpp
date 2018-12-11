/**
 * ueb02.cpp
 * Hier werden die Tests der ueb02 durchgefuehrt.
 *
 * @author Johannes Gerwert
 * @version 08.12.2018
 */

#include <iostream>
#include "utilities.h"
using namespace std;

//Funktions-Prototypen
bool testWordCount();
bool testMyStrCmp();
bool checkMyStrCmp(char* s1, char* s2, int expectedResult);
bool checkWordCount(char* charPointer, int expectedResult);

/**
 * Die Tests werden gestartet.
 * Die Testergebnisse werden zusammengefasst.
 *
 * @return 0 bei erfolgreichem Programmdurchlauf
 */
int main() {
	bool test1 { false };
	bool test2 { false };

	test1 = testWordCount();

	test2 = testMyStrCmp();

	cout << "#############################################################\n"
		 << "#                         Test-Ende                         #\n"
		 << "#############################################################\n"
		 << endl;

	if(test1){
		cout << "\nAlle wordCount Tests wurden bestanden." << endl;
	}else{
		cout << "Zumindest ein wordCount Test wurde nicht bestanden." << endl;
	}

	if(test2){
		cout << "\nAlle mystrcmp Tests wurden bestanden." << endl;
	}else{
		cout << "Zumindest ein mystrcmp Test wurde nicht bestanden." << endl;
	}

	return 0;
}

/**
 * Die Tests der Teilaufgabe a) werden gestartet.
 * Es wird fuer verschiedene Test-Saetze die Wort-Anzahl geprueft.
 *
 * @return true, wenn Tests bestanden wurden; false sonst
 */
bool testWordCount(){
	bool testPassed { true };

	//Test-Saetze
	char sEmpty[] {""};
	char s1W[] {"Test"};
	char s2W[] {"Hello World"};
	char sBlank[] {"Hello  \x09World\n!!!"};
	char s3W[] {"Hello World !!!"};


	cout << "#############################################################\n"
		 << "#                   Beginn WordCount Test                   #\n"
		 << "#############################################################\n"
		 << endl;

	testPassed = testPassed && checkWordCount(sEmpty, 0);
	testPassed = testPassed && checkWordCount(s1W, 1);
	testPassed = testPassed && checkWordCount(s2W, 2);
	testPassed = testPassed && checkWordCount(sBlank, 3);
	testPassed = testPassed && checkWordCount(s3W, 3);

	cout << endl;

	return testPassed;
}

/**
 * Einzelne Tests der Teilaugabe a) werden durchgefuehrt.
 * Das Ergebnis wird formatiert.
 *
 * @param charPointer Der zu pruefende char-String.
 * @param expectedResult Das erwartete Ergebnis.
 * @return true, wenn Test bestanden; false sonst
 */
bool checkWordCount(char* charPointer, int expectedResult){
	bool testPassed { true };
	int result { 0 };

	result = countWords(charPointer);
	cout << "Char-String: " << charPointer << " -- Anzahl Worte: " << result <<endl;
	if(result != expectedResult){
		testPassed = false;
	}

	return testPassed;
}

/**
 * Die Tests der Teilaufgabe b) werden gestartet.
 * Es werden verschiedene Test-Char-Strings auf lexikalische Gleichheit geprueft.
 *
 * @return true, wenn Tests bestanden wurden, false sonst
 */
bool testMyStrCmp(){
	bool testPassed { true };

	char sEmpty[] {""};

	char a[] {"a"};
	char A[] {"A"};
	char z[] {"z"};
	char Z[] {"Z"};
	char aBlank[] {"   \ta  "};
	char ABlank[] {" \nA\t"};

	char xyz[] {"xyz"};
	char zzz[] {"zzz"};
	char xyzBlank[] {"x y\tz"};
	char zzzBlank[] {"       zz\tz\n"};

	char helloWorld[] {"Hello World"};
	char helloWorldBlank[] {"H  ello\tWo\nrl d\t\t"};


	cout << "#############################################################\n"
		 << "#                   Beginn MyStrCmp Test                    #\n"
		 << "#############################################################\n"
		 << endl;

	testPassed = testPassed && checkMyStrCmp(sEmpty, sEmpty, 0);
	testPassed = testPassed && checkMyStrCmp(a, sEmpty, 1);
	testPassed = testPassed && checkMyStrCmp(sEmpty, helloWorld, -1);

	testPassed = testPassed && checkMyStrCmp(a, a, 0);
	testPassed = testPassed && checkMyStrCmp(a, A, 1);
	testPassed = testPassed && checkMyStrCmp(a, z, -1);
	testPassed = testPassed && checkMyStrCmp(Z, z, -1);
	testPassed = testPassed && checkMyStrCmp(Z, A, 1);

	testPassed = testPassed && checkMyStrCmp(a, aBlank, 0);
	testPassed = testPassed && checkMyStrCmp(ABlank, A, 0);
	testPassed = testPassed && checkMyStrCmp(ABlank, z, -1);

	testPassed = testPassed && checkMyStrCmp(xyz, zzz, -1);
	testPassed = testPassed && checkMyStrCmp(xyzBlank, xyz, 0);
	testPassed = testPassed && checkMyStrCmp(zzz, zzzBlank, 0);
	testPassed = testPassed && checkMyStrCmp(zzzBlank, xyzBlank, 1);

	testPassed = testPassed && checkMyStrCmp(helloWorld, helloWorldBlank, 0);
	testPassed = testPassed && checkMyStrCmp(a, helloWorldBlank, 1);
	testPassed = testPassed && checkMyStrCmp(helloWorldBlank, ABlank, 1);
	testPassed = testPassed && checkMyStrCmp(zzzBlank, helloWorld, 1);

	return testPassed;
}

/**
 * Einzelne Tests der Teilaugabe b) werden durchgefuehrt.
 * Das Ergebnis wird formatiert.
 *
 * @param s1 Der erste zu pruefende String.
 * @param s2 Der zweite zu pruefende String.
 * @param expectedResult Das erwartete Ergebnis.
 * @return true, wenn Test bestanden; false sonst
 */
bool checkMyStrCmp(char* s1, char* s2, int expectedResult){
	bool testPassed { true };
	int result { 0 };

	result = mystrcmp(s1, s2);
	cout << "String1: " << s1 << "\nString2: " << s2 << "\nErgebnis: " << result << "\n" <<endl;
	if(result != expectedResult){
		testPassed = false;
	}

	return testPassed;
}

bool testInsertionSort(){
	bool testPassed { true };

	return testPassed;
}

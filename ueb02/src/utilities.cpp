/**
 * utilities.cpp
 * Hier ist die Logik der verschiedenen Uebungsaufgaben implementiert.
 *
 * @author Johannes Gerwert
 * @version 08.12.2018
 */


#include <iostream>
#include "utilities.h"
using namespace std;

template<typename T>
void myswap(T *pointer1, T *pointer2);

/**
 * Zaehlt die Anzahl der Woerter in einem char-String.
 *
 * @param charPointer Pointer zum char-String
 * @return Die Anzahl der Woerter im char-String
 */
int countWords(char* charPointer){
	bool stringEnd { false };
	bool blank { false };
	int numberOfWords { 0 };
	int i {0};


	//Ueberpruefe, ob der String leer ist
	if(*(charPointer) == '\0'){
		stringEnd = true;
	}else{
		numberOfWords++;
	}

	//Anzahl der Woerter wird gezaehlt
	while(!stringEnd){

		//Bei einem Leerzeichen wird die Wortzahl erhoeht
		if(*(charPointer+i) == '\x20' || *(charPointer+i) == '\t' || *(charPointer+i) == '\n'){
			if(blank == false){
				numberOfWords++;
			}
			blank = true;
		}else{
			blank = false;
		}

		//Wenn das Ende des Strings erreicht wurde, wird die Schleife beendet
		if(*(charPointer+i) == '\0'){
			stringEnd = true;
		}

		i++;
	}

	return numberOfWords;
}

/**
 * Vergleich zweier char-Strings, Leerzeichen werden ignoriert.
 *
 * @param charPointer1 Pointer zum ersten char-String
 * @param charPointer2 Pointer zum zweiten char-String
 * @return -1, falls string1 < string2; 0, falls string1 == string2; 1, falls string1 > string2
 */
int mystrcmp(char* charPointer1, char* charPointer2){
	bool cmpEnd { false };

	int result { 0 };

	int i { 0 };
	int blankOffset1 { 0 };
	int blankOffset2 { 0 };

	char charCmp1 { };
	char charCmp2 { };

	while(!cmpEnd){
		charCmp1 = *(charPointer1 + i + blankOffset1);
		charCmp2 = *(charPointer2 + i + blankOffset2);

		if(charCmp1 == '\x20' || charCmp1 == '\t' || charCmp1 == '\n'){
			//Leerzeichen in string1
			blankOffset1++;
		}else if(charCmp2 == '\x20' || charCmp2 == '\t' || charCmp2 == '\n'){
			//Leerzeichen in string2
			blankOffset2++;
		}else if(charCmp1 < charCmp2){
			//string1 < string2
			result = -1;
			cmpEnd = true;
		}else if(charCmp1 > charCmp2){
			//string1 > string2
			result = 1;
			cmpEnd = true;
		}else if(charCmp1 == '\0' && charCmp2 == '\0'){
			//beide strings sind gleich
			result = 0;
			cmpEnd = true;
		}else{
			i++;
		}

	}


	return result;
}

template<typename T>
void insertionSort(T *start, T *end){
	T *cur { start };
	int offset { 0 };

	while(cur != end){
		while( (cur - offset) != start || *(cur - offset) >= *(cur - offset - 1) ){
			myswap(*(cur - offset), *(cur - offset -1));
			offset++;
		}
	}

}

template<typename T>
void myswap(T *pointer1, T *pointer2){
	T temp { *pointer1 };
	*pointer1 = *pointer2;
	*pointer2 = temp;
}

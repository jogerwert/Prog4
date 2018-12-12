/**
 * utilities.h
 * Enthaelt die Funktionsprototypen der Aufgaben von ueb02.
 *
 * @author Johannes Gerwert
 * @author Michelle Blau
 * @version 12.12.2018
 */


#ifndef UTILITIES_H_
#define UTILITIES_H_


int countWords(char* charPointer);
int mystrcmp(char* charPointer1, char* charPointer2);
template<typename T>
void insertionSort(T *start, T *end);
template<typename T>
void myswap(T *pointer1, T *pointer2);



/**
 * Ein Speicherbereich wird mithilfe des Insertion-Sort-Algorithmus sortiert.
 *
 * @param start Pointer zum Anfang des Speicherbereichs.
 * @param end Pointer zum Ende des Speicherbereichs.
 */
template<typename T>
void insertionSort(T *start, T *end){
	T *cur { start + 1 };
	int offset { 0 };

	while(cur != end){
		while( (cur - offset) != start && *(cur - offset) < *(cur - offset - 1) ){
			myswap(cur - offset, cur - offset -1);
			offset++;
		}

		cur++;
		offset = 0;
	}
}

/**
 * Die Werte von zwei Pointern werden getauscht.
 *
 * @param pointer1 Der pointer zum ersten Wert.
 * @param pointer2 Der pointer zum zweiten Wert.
 */
template<typename T>
void myswap(T *pointer1, T *pointer2){
	T temp { *pointer1 };
	*pointer1 = *pointer2;
	*pointer2 = temp;
}

#endif /* UTILITIES_H_ */

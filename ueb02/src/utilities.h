/**
 * utilities.h
 * Enthaelt die Funktionsprototypen der Aufgaben von ueb02.
 *
 * @author Johannes Gerwert
 * @version 07.12.2018
 */


#ifndef UTILITIES_H_
#define UTILITIES_H_


int countWords(char* charPointer);
int mystrcmp(char* charPointer1, char* charPointer2);
template<typename T>
void insertionSort(T *start, T *end);
template<typename T>
void myswap(T *pointer1, T *pointer2);


#endif /* UTILITIES_H_ */

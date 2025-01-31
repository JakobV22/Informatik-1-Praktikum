//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////
/**
 * Praktikum Informatik 1
 *
 *
 * @file Liste.h
 *
 * Die Definition der Klasse Liste
 */

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
	ListenElement *front;                  // Zeiger auf das erste Listenelement
	ListenElement *back;                  // Zeiger auf das letzte Listenelement

public:
	Liste();                            // Konstruktor mit Zeigerinitialisierung
	void pushBack(Student pData);
	void pushFront(Student pData); 				//
	void popFront();
	bool empty();
	Student dataFront();
	void ausgabeVorwaerts() const;
	void ausgabeRueckwaerts() const;					//
	void elementLoeschen(unsigned int wantedMatr);				//
};

#endif /*LISTE_H_*/

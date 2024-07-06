/*
 * Buch.cpp
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#include "Buch.h"

#include <string>
#include <iostream>

/**
 *
 * @brief Konstruktor mit Initialisierungsliste
 */
Buch::Buch(std::string initTitel, std::string initAutor) :
		Medium(initTitel), autor(initAutor)
{

}

//Destruktor
Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}
/**
 * @brief printed informationen über Buch
 * @param out für geerbte << op überladung
 */
void Buch::ausgabe(std::ostream &out) const
{
	Medium::ausgabe(out);
	out << "Autor: " << autor << std::endl;

}


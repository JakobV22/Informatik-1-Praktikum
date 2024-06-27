/*
 * Buch.cpp
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#include "Buch.h"


#include <string>
#include <iostream>

Buch::Buch(std::string initTitel, std::string initAutor):
Medium(initTitel), autor(initAutor)
{

}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}
void Buch::ausgabe(std::ostream& out) const
{
    Medium::ausgabe(out);
    out << "Autor: " << autor << std::endl;

}


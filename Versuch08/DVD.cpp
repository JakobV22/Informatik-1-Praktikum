/*
 * DVD.cpp
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
		Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{
	// TODO Auto-generated constructor stub

}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}
void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
	out << "Genre: " << genre << std::endl;

}
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{

	if ((ausleihdatum - person.getGeburtsdatum()) > altersfreigabe * 12 -1)
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
	else
	{
		std::cout << "Das Medium \"" << titel
				<< "\" ist altersbeschränkt! Sie sind leider zu Jung."
				<< std::endl;
		return false;
	}
}

/*
 * DVD.cpp
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#include "DVD.h"


/**
 *
 * @brief Konstruktor mit Initialisierungsliste
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
		Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{
	// TODO Auto-generated constructor stub

}
// Destruktor
DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

/**
 * @brief printed informationen über DVD
 * @param out für geerbte << op überladung
 */
void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "FSK: ab " << altersfreigabe << " Jahre" << std::endl;
	out << "Genre: " << genre << std::endl;

}

/**
 * @brief überprüft altersfreigabe. Falls ok Medium::ausleihen funktion. Sonts fehlermeldung
 * @param person für geburtstag
 * @param ausleihdatum für aktuelles datum
 * @return true wenn ausleihvorgang ok
 */
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

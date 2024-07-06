/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */

#include "Medium.h"

#include <string>
#include <iostream>

unsigned int Medium::currentID = 1;

/**
 * @brief Konstruktor mit Initialisierungsliste. Erhöht static ID counter
 * @param initTitel	Titel des Mediums
 */
Medium::Medium(std::string initTitel) :
		titel(initTitel), status(false)
{
	ID = currentID++;
}

//Destruktor
Medium::~Medium(void)
{
}

/**
 * @brief printed ID, titel und status auf die Konsole
 * @param out für überladenen << op
 */
void Medium::ausgabe(std::ostream &out) const
{
	out << "ID: " << ID << std::endl;
	out << "Titel: " << titel << std::endl;

	if (status)
	{
		out << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an "
				<< personAusgeliehen.getName() << " ausgeliehen." << std::endl;
	}
	else
	{
		out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
	}
}

/**
 * @brief Überprüft status des Mediums. Falls false (nicht ausgeliehen return false. Andernfalls: return true, neuer status true,
 * personAusgeliehen und datum ausgeliehen werden entsprechend angepasst
 * @param person ausleihende person
 * @param ausleihdatum aktuelles datum
 * @return
 */
bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
	if (status)
	{
		std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!"
				<< std::endl;
		return false;
	}
	else
	{
		status = true;
		personAusgeliehen = person;
		datumAusgeliehen = ausleihdatum;
		std::cout << "Das Medium \"" << titel << "\" wird an "
				<< person.getName() << " verliehen." << std::endl;
		return true;
	}
}
/**
 * @brief falls status==true (medium verliehen): Medium wird zurückgegeben, status nun false. AAnderfalls fehlermeldung
 */
void Medium::zurueckgeben()
{
	if (status)
	{
		status = false;
		std::cout << "Das Medium \"" << titel << "\" wurde zur�ckgegeben."
				<< std::endl;
	}
	else
	{
		std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!"
				<< std::endl;
	}
}

/**
 * @brief ermittelöt aktuelle ID (static)
 * @return aktuelle ID
 */
unsigned int Medium::getID()
{
	return ID;
}

/**
 * @brief ermittelt status des Mediums
 * @return status true (ausgeliehen), false (nicht ausgeliehen)
 */
bool Medium::getStatus()
{
	return status;
}

/**
 * @brief globale funktion zur überladung des << operators
 */
std::ostream& operator<<(std::ostream &out, const Medium &m)
{
	m.ausgabe(out);
	return out;
}

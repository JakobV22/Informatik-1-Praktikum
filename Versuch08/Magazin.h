/*
 * Magazin.h
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include <string>
#include <iostream>
#include "Medium.h"
/**
 * @brief Klasse Magazin erbt von Klasse Medium
 */
class Magazin: public Medium
{
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe,
			std::string initSparte);
	virtual ~Magazin();
	void ausgabe(std::ostream&) const;
	bool ausleihen(Person person, Datum ausleihdatum);
protected:
	std::string sparte;
	Datum erscheinungsdatum;

};

#endif /* MAGAZIN_H_ */

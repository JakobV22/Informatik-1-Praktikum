/*
 * Magazin.cpp
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
Medium(initTitel), erscheinungsdatum(initDatumAusgabe), sparte(initSparte)
{
	// TODO Auto-generated constructor stub

}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}
void Magazin::ausgabe(std::ostream& out) const{
	Medium::ausgabe(out);
	out << "Ausgabe: " << erscheinungsdatum << std::endl;
	out << "Sparte: " << sparte << std::endl;
}
bool Magazin::ausleihen(Person person, Datum ausleihdatum){


if ((ausleihdatum - erscheinungsdatum) == 0){
	std::cout << "Das Medium \"" << titel << "\" ist die neueste Ausgabe! Es kann leider nicht verliehen werden" << std::endl;
	        return false;
}
    else{
    	return Medium::ausleihen(person, ausleihdatum);

}
}

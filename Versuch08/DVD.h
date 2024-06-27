/*
 * DVD.h
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#ifndef DVD_H_
#define DVD_H_
#include <string>
#include <iostream>
#include "Medium.h"

class DVD : public Medium
{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string
			initGenre);
	virtual ~DVD();
	void ausgabe(std::ostream&) const;
	bool ausleihen(Person person, Datum ausleihdatum);

protected:
	int altersfreigabe;
	std::string genre;
};

#endif /* DVD_H_ */

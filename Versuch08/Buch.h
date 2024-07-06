/*
 * Buch.h
 *
 *  Created on: 27.06.2024
 *      Author: vogel
 */

#ifndef BUCH_H_
#define BUCH_H_

#include <string>
#include <iostream>
#include "Medium.h"

/**
 * @brief Klasse Buch erbt von Klasse Medium
 */
class Buch: public Medium
{
public:
	Buch();
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();
	void ausgabe(std::ostream&) const;
protected:
	std::string autor;
};

#endif /* BUCH_H_ */

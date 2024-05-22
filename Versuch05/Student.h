//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

/**
 * Praktikum Informatik 1
 *
 *
 * @file Student.h
 *
 * Die Definition der Klasse Student
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name, std::string geburtstag,
			std::string address);
	unsigned int getMatNr() const;
	std::string getName() const;
	std::string getGeburtstag() const;
	std::string getAdresse() const;
	void ausgabe() const;
private:
	unsigned int matNr;
	std::string name;
	std::string geburtstag;
	std::string adresse;
};

#endif

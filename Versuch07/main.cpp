/** @file main.cpp
 * @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 7: Überladung
 *
 *

 */

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <algorithm>
#include "Student.h"

std::vector<Student> studentenVektor;
Student student;

/**
 * @brief Globale Funktion für operator <<
 * @param out
 * @param student
 * @return
 */
std::ostream& operator<<(std::ostream &out, const Student &student)
{
	student.ausgabe(out);
	return out;
}

/**
 * @brief klassische push back funktion, fragt daten für neuen studenten ab
 */
void hintenHinzufuegen()
{
	unsigned int matNr = 0;
	std::string name = "";
	std::string geburtstag = "";
	std::string adresse = "";

	std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
	getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

	std::cout << "Geburtsdatum: ";
	getline(std::cin, geburtstag);

	std::cout << "Adresse: ";
	getline(std::cin, adresse);

	std::cout << "Matrikelnummer: ";
	std::cin >> matNr;
	std::cin.ignore(10, '\n');

	student = Student(matNr, name, geburtstag, adresse);

	studentenVektor.push_back(student);
}

/**
 * @brief klassische pop back funktion
 */
void hintenEntfernen()
{
	if (studentenVektor.size() != 0)
	{
		//studentenVektor.end()->ausgabe();
		std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
		std::cout << studentenVektor.back();
		studentenVektor.pop_back();
	}
	else
	{
		std::cout << "Der Vektor ist leer\n" << std::endl;
	}
}
/**
 * @brief klassische insert funktion, abfrage an welcher position eingefügt werden soll
 */
void hinzufuegenAnPosX()
{
	std::cout << "An welcher Stelle soll das Element eingefügt werden? (0 - "
			<< studentenVektor.size() << ")" << std::endl;
	int position;
	std::cin >> position;

	if (studentenVektor.size() > position)
	{
		unsigned int matNr = 0;
		std::string name = "";
		std::string geburtstag = "";
		std::string adresse = "";

		std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: "
				<< std::endl;
		std::cin.ignore(1, '\n');
		getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

		std::cout << "Geburtsdatum: ";
		getline(std::cin, geburtstag);

		std::cout << "Adresse: ";
		getline(std::cin, adresse);

		std::cout << "Matrikelnummer: ";
		std::cin >> matNr;
		std::cin.ignore(10, '\n');

		student = Student(matNr, name, geburtstag, adresse);

		studentenVektor.insert(studentenVektor.begin() + position, student);
		std::cout << "Der folgende Student ist an Position " << position
				<< " eingefügt worden:" << std::endl;
		std::cout << student;

	}
	else
	{
		std::cout << "Der Vektor besitzt nicht genügend Elemente\n"
				<< std::endl;
	}
}

/**
 * @brief löscht studenten an bestimmter position, fragt gewünschte position im terminal ab
 */
void loeschenAnPosX()
{
	std::cout << "An welcher Stelle soll das Element gelöscht werden? (0 - "
			<< studentenVektor.size() - 1 << ")" << std::endl;
	int position;
	std::cin >> position;
	if (studentenVektor.size() >= position)
	{
		std::cout << "Der folgende Student ist gelöscht worden" << std::endl;
		std::cout << studentenVektor.at(position);
		studentenVektor.erase(studentenVektor.begin() + position);

	}
	else
	{
		std::cout << "Die gewählte Position ist nicht vorhanden\n" << std::endl;
	}
}

/**
 * @brief gibt vektor vorwärts aus, nutzt überladenen << operator
 */
void vorwaertsAusgeben()
{
	if (studentenVektor.size() != 0)
	{
		std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:"
				<< std::endl;
		for (auto it = studentenVektor.begin(); it != studentenVektor.end();
				it++)
		{
			std::cout << *it;
		}
	}
	else
	{
		std::cout << "Der Vektor ist leer!\n\n";
	}
}

/**
 * @brief gibt vektor rückwärts aus, nutzt überladenen << operator
 */
void rueckwaertsAusgeben()
{
	if (studentenVektor.size() != 0)
	{
		std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:"
				<< std::endl;
		for (auto rit = studentenVektor.rbegin(); rit != studentenVektor.rend();
				rit++)
		{
			std::cout << *rit;
		}
	}
	else
	{
		std::cout << "Der Vektor ist leer!\n\n";
	}
}
/**
 * @brief pop front funktion
 */
void vorneLoeschen()
{
	if (studentenVektor.size() != 0)
	{
		std::cout << "Der folgende Student ist gelöscht worden:" << std::endl;
		std::cout << studentenVektor.front();
		studentenVektor.erase(studentenVektor.begin());

	}
	else
	{
		std::cout << "Der Vektor ist leer\n" << std::endl;
	}
}

/**
 * @brief fragt nach datei aus der gelesen werden soll. Setzt eingelesene strings zu Student-objekt zusammen und pushed dieses back auf vektor
 */
void ausDateiLesen()
{
	std::cout << "Aus welcher Datei soll eingelesen werden?" << std::endl;
	std::string dateiName;
	std::cin >> dateiName;
	studentenVektor.clear();

	std::ifstream inputDatei(dateiName);
	if (!inputDatei)
	{
		std::cout << " Fehler beim Oeffnen der Datei !";
		exit(1);
	}
	while (!inputDatei.eof())
	{
		unsigned int matNr = 0;
		std::string name = "";
		std::string geburtstag = "";
		std::string adresse = "";
		inputDatei >> matNr;
		inputDatei.ignore(1, '\n');
		std::getline(inputDatei, name);
		std::getline(inputDatei, geburtstag);
		std::getline(inputDatei, adresse);
		student = Student(matNr, name, geburtstag, adresse);
		studentenVektor.push_back(student);
	}
	inputDatei.close();
	studentenVektor.pop_back();
}

/**
 *@brief fragt nach Datei in der gespeichert werden soll.Schreibt die einzelnen Daten jedes Stundet-objektes in dei Datei.
 */

void inDateiSpeichern()
{
	std::cout << "In welche Datei soll gespeichert werden?" << std::endl;
	std::string dateiName;
	std::cin >> dateiName;

	std::ofstream outputDatei(dateiName);
	if (!outputDatei)
	{
		std::cout << " Fehler beim Oeffnen der Datei !";
		exit(1);
	}
	for (int i = 0; i < studentenVektor.size(); i++)
	{

		student = studentenVektor.at(i);

		outputDatei << student.getMatNr() << std::endl;
		outputDatei << student.getName() << std::endl;
		outputDatei << student.getGeburtstag() << std::endl;
		outputDatei << student.getAdresse() << std::endl;
	}
	outputDatei.close();
}

/**
 * @brief nutzt std::sort und überladene vergleichsoperatoren um vektor nach Matr Nr zu sortieren. Gibt sortierten vektor aus
 */
void Sortierung()
{
	std::sort(studentenVektor.begin(), studentenVektor.end());
	vorwaertsAusgeben();
}

/**
 * @brief fragt nach gesuchter Matr Nr. Geht Vektor durch und sucht mithilfe des überladenen == operators nach der Nr. std::find gibt iterator auf gesuchtes
 * element oder auf vektor.end(). Im 1. Fall: element löschen, im 2. Fall: element nicht gefunden
 */
void findeElement()
{
	std::cout << "Welche Matrikelnummer suchen Sie?" << std::endl;
	std::string eingabe;
	std::cin >> eingabe;
	int matrNr = stoi(eingabe);

	std::cout << "gesuchte MatrNr: " << matrNr << std::endl;
	Student gesucht = Student(matrNr, "xyz", "xyz", "xyz");

	std::vector<Student>::iterator element = std::find(studentenVektor.begin(),
			studentenVektor.end(), gesucht); //auch "auto" möglich --> Iterator
	if (*element == *(studentenVektor.end()))
	{
		std::cout << "Matrikelnummer wurde nicht gefunden" << std::endl;

	}
	else
	{
		std::cout << "Folgender Student wird geloescht: " << std::endl;
		std::cout << *element;
		studentenVektor.erase(element);
		std::cout << "\n Restlicher Vektor: " << std::endl;
		vorwaertsAusgeben();
	}
}

/**
 * @brief erstellt den Vektor, fragt welche Operation ausgeführt werden soll und ruft vektor member functions auf
 * @return 0 wenn Fehlerfrei
 */
int main()
{

	char abfrage;
	std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;
	std::cin.ignore(10, '\n');

	if (abfrage != 'j')
	{
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		studentenVektor.push_back(student);
		student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
		studentenVektor.push_back(student);
		student = Student(12345, "Siggi Baumeister", "23.04.1983",
				"Ahornst.55");
		studentenVektor.push_back(student);
		student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
		studentenVektor.push_back(student);
		student = Student(23456, "Walter Rodenstock", "15.10.1963",
				"W�llnerstr.9");
		studentenVektor.push_back(student);
	}

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------"
				<< std::endl << "(1): Datenelement hinten hinzufuegen"
				<< std::endl << "(2): Datenelement hinten entfernen"
				<< std::endl << "(3): Datenelement an Stelle x hinzufügen"
				<< std::endl << "(4): Datenelement an Stelle x entfernen"
				<< std::endl << "(5): Datenbank ausgeben (vorwaerts)"
				<< std::endl << "(6): Datenbank ausgeben (rueckwaerts)"
				<< std::endl << "(7): Datenelement vorne entfernen" << std::endl
				<< "(8): Daten aus einer Datei einlesen" << std::endl
				<< "(9): Daten in einer Datei sichern" << std::endl
				<< "(S): Nach Matrikelnummern Sortieren" << std::endl
				<< "(F): Student mit Matrikelnummer finden und löschen"
				<< std::endl << "(0): Beenden" << std::endl;

		std::cin >> abfrage;
		std::cin.ignore(10, '\n');

		switch (abfrage)
		{
		// Datenelement hinten hinzufuegen
		case '1':
		{
			hintenHinzufuegen();
		}
			break;

			// Datenelement hinten entfernen
		case '2':
		{
			hintenEntfernen();
		}
			break;
			// Datenelement an Stelle x hinzufügen
		case '3':
		{
			hinzufuegenAnPosX();
		}
			break;
			// Datenelement an Stelle x löschen
		case '4':
		{
			loeschenAnPosX();
		}
			break;

			// Datenbank vorwaerts ausgeben
		case '5':
		{
			vorwaertsAusgeben();
		}
			break;
			// Datenbank rueckwaerts ausgeben
		case '6':
		{
			rueckwaertsAusgeben();

		}
			break;
			//Datenelement vorne löschen
		case '7':
		{
			vorneLoeschen();
		}
			break;

			// Daten aus Datei einlesen
		case '8':
		{
			ausDateiLesen();
		}
			break;

		case '9':
		{
			inDateiSpeichern();
		}
			break;
		case 'S':
		{
			Sortierung();
		}
			break;
		case 'F':
		{
			findeElement();
		}
			break;

		case '0':

			std::cout << "Das Programm wird nun beendet";
			break;

		default:
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}
	} while (abfrage != '0');

	return 0;
}

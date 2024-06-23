/** @file main.cpp
 * @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 6: Standard Template Library
 *
 *

 */

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include "Student.h"
/**
 * @brief erstellt den Vektor, fragt welche Operation ausgeführt werden soll und ruft vektor member functions auf
 * @return 0 wenn Fehlerfrei
 */
int main()
{
	std::vector<Student> studentenVektor;
	Student student;

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
				<< "(0): Beenden" << std::endl;

		std::cin >> abfrage;
		std::cin.ignore(10, '\n');

		switch (abfrage)
		{
		// Datenelement hinten hinzufuegen
		case '1':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string geburtstag = "";
			std::string adresse = "";

			std::cout
					<< "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
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
			break;

			// Datenelement hinten entfernen
		case '2':
		{
			if (studentenVektor.size() != 0)
			{
				//studentenVektor.end()->ausgabe();
				std::cout << "Der folgende Student ist geloescht worden:"
						<< std::endl;
				studentenVektor.back().ausgabe();
				studentenVektor.pop_back();
			}
			else
			{
				std::cout << "Der Vektor ist leer\n" << std::endl;
			}
		}
			break;
			// Datenelement an Stelle x hinzufügen
		case '3':
		{
			std::cout
					<< "An welcher Stelle soll das Element eingefügt werden? (0 - "
					<< studentenVektor.size() << ")" << std::endl;
			int position;
			std::cin >> position;

			if (studentenVektor.size() > position)
			{
				unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";

				std::cout
						<< "Bitte geben sie die Daten f�r den Studenten ein.\nName: " << std::endl;
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

				studentenVektor.insert(studentenVektor.begin() + position,
						student);
				std::cout << "Der folgende Student ist an Position " << position
						<< " eingefügt worden:" << std::endl;
				student.ausgabe();

			}
			else
			{
				std::cout << "Der Vektor besitzt nicht genügend Elemente\n"
						<< std::endl;
			}
		}
			break;
			// Datenelement an Stelle x löschen
		case '4':
		{
			std::cout
					<< "An welcher Stelle soll das Element gelöscht werden? (0 - "
					<< studentenVektor.size() - 1 << ")" << std::endl;
			int position;
			std::cin >> position;
			if (studentenVektor.size() >= position)
			{
				std::cout << "Der folgende Student ist gelöscht worden"
						<< std::endl;
				studentenVektor.at(position).ausgabe();
				studentenVektor.erase(studentenVektor.begin() + position);

			}
			else
			{
				std::cout << "Die gewählte Position ist nicht vorhanden\n"
						<< std::endl;
			}
		}
			break;

			// Datenbank vorwaerts ausgeben
		case '5':
		{
			if (studentenVektor.size() != 0)
			{
				std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:"
						<< std::endl;
				for (auto it = studentenVektor.begin();
						it != studentenVektor.end(); it++)
				{
					it->ausgabe();
				}
			}
			else
			{
				std::cout << "Der Vektor ist leer!\n\n";
			}
		}
			break;
			// Datenbank rueckwaerts ausgeben
		case '6':
		{
			if (studentenVektor.size() != 0)
			{
				std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:"
						<< std::endl;
				for (auto rit = studentenVektor.rbegin();
						rit != studentenVektor.rend(); rit++)
				{
					rit->ausgabe();
				}
			}
			else
			{
				std::cout << "Der Vektor ist leer!\n\n";
			}
		}
			break;
			//Datenelement vorne löschen
		case '7':
		{
			if (studentenVektor.size() != 0)
			{
				std::cout << "Der folgende Student ist gelöscht worden:"
						<< std::endl;
				studentenVektor.front().ausgabe();
				studentenVektor.erase(studentenVektor.begin());

			}
			else
			{
				std::cout << "Der Vektor ist leer\n" << std::endl;
			}

		}
			break;

			// Daten aus Datei einlesen
		case '8':
		{
			std::cout << "Aus welcher Datei soll eingelesen werden?"
					<< std::endl;
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
			break;
		}
		case '9':
		{
			std::cout << "In welche Datei soll gespeichert werden?"
					<< std::endl;
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
			break;
		}
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

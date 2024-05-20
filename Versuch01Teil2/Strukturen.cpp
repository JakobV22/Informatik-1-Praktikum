/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	struct Person
	{
		std::string sNachname, sVorname;
		int iGeburtsjahr, iAlter;
	};

	Person nBenutzer;
	std::cout << "Name: " << std::endl;
	std::cin >> nBenutzer.sNachname;

	std::cout << "Vorname: " << std::endl;
	std::cin >> nBenutzer.sVorname;

	std::cout << "Geburtsjahr: " << std::endl;
	std::cin >> nBenutzer.iGeburtsjahr;

	std::cout << "Alter: " << std::endl;
	std::cin >> nBenutzer.iAlter;

	std::cout << "\n \n \nName: " << nBenutzer.sNachname << std::endl;

	std::cout << "Vorname: " << nBenutzer.sVorname << std::endl;

	std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;

	std::cout << "Alter: " << nBenutzer.iAlter << std::endl;

	Person nKopieEinzeln;				//1
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	Person nKopieGesamt; 			//2
	nKopieGesamt = nBenutzer;

	std::cout << "\nEinzelnd: " << nKopieEinzeln.sVorname << ", "
			<< nKopieEinzeln.sNachname << ", " << nKopieEinzeln.iGeburtsjahr
			<< ", " << nKopieEinzeln.iAlter << std::endl;


	std::cout << "\nGesamt: " << nKopieGesamt.sVorname << ", "
				<< nKopieGesamt.sNachname << ", " << nKopieGesamt.iGeburtsjahr
				<< ", " << nKopieGesamt.iAlter << std::endl;
	return 0;

}

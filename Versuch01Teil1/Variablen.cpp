//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	int iErste = 0;									// 1
	int iZweite = 0;

	// Hier folgt Ihr eigener Code
	std::cout << " Geben Sie zwei ganze Zahlen ein: \n" << std::endl;
	std::cin >> iErste;
	std::cout << "\n" << std::endl;
	std::cin >> iZweite;

	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;

	std::cout << "Die Summe der eingegebenen Zahlen beträgt: " << iSumme
			<< std::endl;
	std::cout << "Der Quotient der eingegebenen Zahlen beträgt: " << iQuotient
			<< std::endl;

	double dSumme = iErste + iZweite;					//2
	double dQuotient = iErste / iZweite;

	std::cout << "\n Ergebnisse als double:" << std::endl;
	std::cout << "Die Summe der eingegebenen Zahlen beträgt: " << dSumme
			<< std::endl;
	std::cout << "Der Quotient der eingegebenen Zahlen beträgt: " << dQuotient
			<< std::endl;

	double dSummeCast = (double) iErste + (double) iZweite; 		//3
	double dQuotientCast = (double) iErste / (double) iZweite;

	std::cout << "\n Operanden ebenfalls als double:" << std::endl;
	std::cout << "Die Summe der eingegebenen Zahlen beträgt: " << dSummeCast
			<< std::endl;
	std::cout << "Der Quotient der eingegebenen Zahlen beträgt: "
			<< dQuotientCast << std::endl;

	std::string sVorname; 						// 4
	std::string sNachname;
	std::string sVornameName;
	std::string sNameVorname;

	std::cout << "\n \n Geben Sie Ihren Vornamen ein:" << std::endl;
	std::cin >> sVorname;

	std::cout << "Geben Sie Ihren Nachnamen ein:" << std::endl;
	std::cin >> sNachname;

	sVornameName = sVorname + " " + sNachname;
	sNameVorname = sNachname + " " + sVorname;

	std::cout << sVornameName << "\n" << std::endl;
	std::cout << sNameVorname << "\n" << std::endl;

	{
		int iFeld[2] =									//5
		{ 1, 2 };
		std::cout << iFeld[0] << "\n" << iFeld[1] << std::endl;

		int Spielfeld[2][3] =
		{
		{ 1, 2, 3 },
		{ 4, 5, 6 } };
		std::cout << Spielfeld[0][0] << " " << Spielfeld[0][1] << " "
				<< Spielfeld[0][2] << "\n" << Spielfeld[1][0] << " "
				<< Spielfeld[1][1] << " " << Spielfeld[1][2] << std::endl;

		const int iZweite = 1;
		std::cout << iZweite << std::endl;
	}
	std::cout <<"\n nach Ende des Blockes: " << iZweite << std::endl;

	int iName1 = (int) sVorname[0];
	int iName2 = (int) sVorname[1];

	std::cout << "\n" << iName1 << "\n" << iName2 << std::endl;

	int PosAlphabet1 = (iName1 - 64) % 32;
	int PosAlphabet2 = (iName2 - 64) % 32;

	std::cout << "\n Position der Buchstaben im deutschen Alphabet:\n" << PosAlphabet1 << "\n" << PosAlphabet2 << std::endl;
	return 0;

}

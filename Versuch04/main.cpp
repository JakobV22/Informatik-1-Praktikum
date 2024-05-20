//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int main()
{
	Vektor vector1(1, 0, 0);
	Vektor vector2(0, 1, 0);

	vector1.ausgabe();
	vector2.ausgabe();


	Vektor vector3(1, 1, 3);
	Vektor vector4(3, 4, 0);

	std::cout << "Laenge: \n "<< vector3.laenge() << std::endl; // Test Laenge()
	std::cout << vector4.laenge() << std::endl;

	std::cout << "\nSubtraktion:\n" << std::endl;
	vector1.sub(vector2).ausgabe();				// Test Sub
	vector4.sub(vector3).ausgabe();


	std::cout <<"\nSkalaprodukt:\n" << vector4.skalarProd(vector3) << std::endl; // Test Skalarprodukt
	std::cout << vector1.skalarProd(vector2) << std::endl;

	std::cout << "\nWinkel: \n" << vector1.winkel(vector2) << std::endl; // Test Winkel
	std::cout << vector1.winkel(vector3) << std::endl;

	std::cout << "\nRotation: " << std::endl; 		// Test Rotation
	vector1.rotiereUmZ(M_PI/2);
	vector4.rotiereUmZ(M_PI);
	vector1.ausgabe();
	vector4.ausgabe();


	std::cout << "AUFGABE \n \n" << std::endl;
	double koerpergroesse = 1.7;
	double plattform = 557.7;
	double erdradius = 6371000;

	Vektor vektorZweck1(0,-1 , 0); /// HIER WEITERMACHEN
	Vektor vektorZweck2(0, 1, 0);
	for (int j = 1; j <= 180; j++){
		vektorZweck1.rotiereUmZ(M_PI/180);
		vektorZweck2.rotiereUmZ(-M_PI/180);
		if (abs(vektorZweck1.skalarProd(vektorZweck2)) < 0.1)
		{
			vektorZweck1.ausgabe();
			std::cout  << "\n " << j <<  "\n" << std::endl;
			double test = abs(vektorZweck1.skalarProd(vektorZweck2));
			std::cout  << "\n Skalarprodukt" << test << "\n" << std::endl;


			vektorZweck2.ausgabe();
			break;
		}
	}

	return 0;

}

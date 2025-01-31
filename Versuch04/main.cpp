//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
/**
 // * @brief Errechnet Sichtweite bis Horizont und gibt Ergebnisse und Zwischenschritte in der Konsole aus
 * @param erdradius Radius der Erde in Metern
 * @param plattform Höhe der Plattforom in Metern
 * @param koerpergroesse Groesse des Menschen in Metern
 */
void horizontRechner(double erdradius, double plattform, double koerpergroesse)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(10);

	Vektor vektorAuge(0, erdradius + plattform + koerpergroesse, 0);
	Vektor vektorErdradius(0, erdradius, 0);
	Vektor vektorRadial(0, erdradius, 0);

	int counter1 = 0;
	int counter2;

	std::string richtung = "vorwaerts";
	int richtungFaktor;

	double angle = M_PI / 180; // 1 °
	double firstAngle = angle;

	while (true)
	{
		if (angle > firstAngle / 1000000000)
		{
			richtung = "vorwaerts";
			richtungFaktor = 1;
		}
		else if (angle < -1 * firstAngle / 1000000000)
		{	// wenn angle präziser als 1 Milliardstel des ersten Winkels: break
			richtung = "rueckwaerts";
			richtungFaktor = -1;
		}
		else
			break;

		for (counter2 = 0;
				richtungFaktor
						* vektorRadial.winkel(vektorRadial.sub(vektorAuge))
						>= richtungFaktor * 90; counter2++)	// bis der Winkel zwischen Radialvektor und Sicht die 90 ° unterschreitet (Richtungsunabhängig)
		{
			vektorRadial.rotiereUmZ(angle);
		}

		std::cout << "Zu weit " << richtung
				<< " gedreht. Ändere Schrittweite von " << angle * (180 / M_PI)
				<< " Grad zu " << angle * (-18 / M_PI) << " Grad" << std::endl;
		std::cout << "Winkel: "
				<< vektorRadial.winkel(vektorRadial.sub(vektorAuge))
				<< std::endl;
		std::cout << "Schritte in diesem Durchlauf: " << counter2 << std::endl;

		angle /= -10;	// Winkel verkleinern für höhere Präzision + umdrehen
		counter1 += counter2;				// Zähler übertragen
	}								// erneute iterieren bis genügende Präzision

	std::cout << "\nSie können " << vektorRadial.sub(vektorAuge).laenge() / 1000
			<< " Km weit sehen." << std::endl;
	std::cout << "Sie sind " << vektorAuge.sub(vektorErdradius).laenge()
			<< " Meter hoch." << std::endl;
	std::cout << "Der Winkel beträgt " << vektorRadial.winkel(vektorErdradius)
			<< " Grad." << std::endl;
	std::cout << "Anzahl Schritte: " << counter1 << std::endl;

}

int main()
{
	/*
	 Vektor vector1(1, 0, 0);
	 Vektor vector2(0, 1, 0);

	 vector1.ausgabe();
	 vector2.ausgabe();

	 Vektor vector3(1, 1, 3);
	 Vektor vector4(3, 4, 0);

	 std::cout << "Laenge: \n " << vector3.laenge() << std::endl; // Test Laenge()
	 std::cout << vector4.laenge() << std::endl;

	 std::cout << "\nSubtraktion:\n" << std::endl;
	 vector1.sub(vector2).ausgabe();				// Test Sub
	 vector4.sub(vector3).ausgabe();

	 std::cout << "\nSkalaprodukt:\n" << vector4.skalarProd(vector3)
	 << std::endl; // Test Skalarprodukt
	 std::cout << vector1.skalarProd(vector2) << std::endl;

	 std::cout << "\nWinkel: \n" << vector1.winkel(vector2) << std::endl; // Test Winkel
	 std::cout << vector1.winkel(vector3) << std::endl;

	 std::cout << "\nRotation: " << std::endl; 		// Test Rotation
	 vector1.rotiereUmZ(M_PI / 2);
	 vector4.rotiereUmZ(M_PI);
	 vector1.ausgabe();
	 vector4.ausgabe();

	 std::cout << "AUFGABE \n \n" << std::endl;
	 */

	double koerpergroesse = 1.7;
	double plattform = 555.7;
	double erdradius = 6371000;

	horizontRechner(erdradius, plattform, koerpergroesse);

	return 0;

}

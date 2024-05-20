/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
	for (int j = 0; j < GROESSE_Y; j++)
	{
		for (int i = 0; i < GROESSE_X; i++)
		{
			spielfeld[j][i] = 0;
		}
	}
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	std::cout << "   | ";

	//Start bei ASCII 65 = A
	for (int i = 65; i < 65 + GROESSE_X; ++i)
		std::cout << ((char) i) << " | ";

	std::cout << std::endl;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			std::cout << "---+";
		}
		std::cout << "---+" << std::endl;

		std::cout << " " << j + 1 << " |";
		for (int i = 0; i < GROESSE_X; ++i)
		{
			switch (spielfeld[j][i])
			{
			case 0:
				std::cout << "   ";
				break;
			case 1:
				std::cout << " X ";
				break;
			case 2:
				std::cout << " O ";
				break;
			default:
				std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
				std::cout << "Abbruch .... " << std::endl;
				exit(0);
				break;
			}
			std::cout << "|";
		}
		;  //for i
		std::cout << std::endl;
	}  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	int zaehlerSpieler1 = 0;
	int zaehlerSpieler2 = 0;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			if (spielfeld[j][i] == 1)
			{
				++zaehlerSpieler1;
			}
			if (spielfeld[j][i] == 2)
			{
				++zaehlerSpieler2;
			}

		}
	}

	if (zaehlerSpieler1 == zaehlerSpieler2)
	{
		return 0;
	}
	if (zaehlerSpieler1 < zaehlerSpieler2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
	// Hier erfolgt jetzt Ihre Implementierung ...
	if (posX < GROESSE_X && posX >= 0 && posY < GROESSE_Y && posY >= 0) // posX und posY zwischen 0 und jeweiligem MAX-Wert?
	{
		return true;
	}
	else
		return false;
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
									   //               if aktuellerSpieler == 2 -> gegner = 1

	if (spielfeld[posY][posX] != 0) // ist das Feld leer?
	{
		return false;
	}

	// Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			// Hier erfolgt jetzt Ihre Implementierung ...
			if (spielfeld[posY + j][posX + i] == gegner) //wenn gegnerischer Stein angrenzt:
			{				// Untersuchung des nächsten Steines in der Richtung
				int y = posY + 2 * j;
				for (int x = posX + 2 * i; aufSpielfeld(y, x); x += i)
				{
					if (spielfeld[y][x] == 0)// Falls leeres Feld: Zug ist nicht zwingend gültig
					{
						break;
					}
					else if (spielfeld[y][x] == aktuellerSpieler)//falls wieder eigener Stein: Zug gültig
					{
						return true;

					}
					else// falls wieder gegnerischer Stein: nächsten Stein in Richtung prüfen
					{
						y += j;
					}
				}
			}
		}
	}
	return false;
}

/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler;			// Erkennung von Gegner-Symbol

	spielfeld[posY][posX] = aktuellerSpieler; 	// Setzen des Steines
	//Alle Richtungen bearbeiten
	for (int j = -1; j <= 1; j++)
	{							// Suche nach angrenzenden gegnerischen Steinen
		for (int i = -1; i <= 1; i++)
		{
			// aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
			// allen Richtungen in Ihre eigenen Steine umgewandelt werden
			//
			// Hier erfolgt jetzt Ihre Implementierung ...

			if (spielfeld[posY + j][posX + i] == gegner)// angrenzender gegnerischer Stein gefunden:
			{
				int y = posY + 2 * j;
				int index = 0;
				for (int x = posX + 2 * i; aufSpielfeld(y, x); x += i)//Suche nach weiteren  Steinen in selber Richtung
				{
					index++;
					if (spielfeld[y][x] == 0)		// falls leeres Feld: break
					{
						break;
					}
					else if (spielfeld[y][x] == aktuellerSpieler)// falls eigener Stein:
					{
						for (int k = index; k > 0; --k)	// Umwandlung der eingeschlossenen Steine (Zählindex k)

						{
							x -= i;
							y -= j;
							spielfeld[y][x] = aktuellerSpieler;
						}
						break;

					}
					else//falls weiterer gegnerischer Stein: nächsten Stein in Richtung betrachten, k++
					{
						y += j;
					}
				}

			}
		}
	}		//ggf Suche nach weiteren angrenzenden Steinen von bespieltem Feld
}
/**
 * @brief Überprüft die Anzahl möglicher Spielzüge
 * @param spielfeld das zu testende Spielfeld
 * @param aktuellerSpieler der aktive Spieler
 * @return Anzahl möglicher Züge als int
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler)
{
// Hier erfolgt jetzt Ihre Implementierung ...
	int counter = 0;
	for (int i = 0; i < GROESSE_Y; i++)
	{							// Teste Jedes Feld auf möglichen gültigen Zug
		for (int j = 0; j < GROESSE_X; j++)
		{
			if (zugGueltig(spielfeld, aktuellerSpieler, j, i))
			{
				counter++;
			}

		}
	}
	return counter;
}
/**
 * @brief Wartet auf gültige Eingabe des Spielers und führt Zug entsprechend aus
 * @param spielfeld aktuelles Spielfeld
 * @param aktuellerSpieler aktiver Spieler
 * @return true wenn ausgeführt
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler)
{
	if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
	{
		return false;
	}

	int posX;
	int posY;
	std::string symbolSpieler;
	if (aktuellerSpieler == 1)
	{
		symbolSpieler = "X";
	}
	else
	{
		symbolSpieler = "O";
	}

	while (true)
	{
		std::string eingabe;
		std::cout << std::endl << "Du bist " << symbolSpieler
				<< ". Dein Zug (z.B. A1, a1): ";
		std::cin >> eingabe;
		posX = (int) eingabe[0] % 32 - 1;
		posY = (int) eingabe[1] - 49;

		if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
		}
	}

	zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
	std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf "
			<< (char) (posX + 65) << (posY + 1) << std::endl;

	return true;
}
/**
 * @brief lässt abwechseln Spieler Züge ausführen, erkennt Sieger
 * @param spielerTyp Mensch gegen Mensch, Mensch gegen Computer oder Computer gegen Computer
 */
void spielen(const int spielerTyp[2])
{

	int spielfeld[GROESSE_Y][GROESSE_X];

//Erzeuge Startaufstellung
	initialisiereSpielfeld(spielfeld);

	int aktuellerSpieler = 1;
	zeigeSpielfeld(spielfeld);

// solange noch Zuege bei einem der beiden Spieler moeglich sind
//
// Hier erfolgt jetzt Ihre Implementierung ...
	for (int i = 0;
			moeglicheZuege(spielfeld, 1) != 0
					|| moeglicheZuege(spielfeld, 2) != 0; i++)
	{
		std::cout << "\n \nRunde: " << i + 1 << std::endl;
		if (i % 2 == 0)
		{
			aktuellerSpieler = 1;
		}
		else
		{
			aktuellerSpieler = 2;
		}
		if (moeglicheZuege(spielfeld, aktuellerSpieler) != 0)
		{
			if (spielerTyp[aktuellerSpieler - 1] == MENSCH)
			{
				menschlicherZug(spielfeld, aktuellerSpieler);
			}
			else
			{
				computerZug(spielfeld, aktuellerSpieler);
			}
		}
		else
		{
			std::cout << "Keine Möglichen Züge für Spieler " << aktuellerSpieler
					<< std::endl;
			std::cout << "\nSetzen Sie eine Runde aus!" << std::endl;
			continue;
		}
		zeigeSpielfeld(spielfeld);
	}

	switch (gewinner(spielfeld))
	{
// Hier erfolgt jetzt Ihre Implementierung ...
	case 0:
		std::cout << "Unentschieden" << std::endl;
		break;
	case 1:
		std::cout << "Spieler 1 gewinnt!" << std::endl;
		break;
	case 2:
		std::cout << "Spieler 2 gewinnt!" << std::endl;
		break;

	}
}
/**
 * @brief testet alle Funktionen, fragt nach Spielmodus, startet Spiel und wiederholt Spiel nach Wahl
 * @return
 */
int main()
{
	if (TEST == 1)
	{
		bool gesamtErgebnis = ganzenTestAusfuehren();
		if (gesamtErgebnis == true)
		{
			std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
		}
		else
		{
			std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
			exit(1);
		}
		std::cout << std::endl << std::endl;
	}

// Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
// implementiert haben (waeren sonst doppelt)
	char anotherRound = 'n';
	do
	{
		std::cout << "Spieltyp angeben: Mensch oder Computer \n"
				<< "Geben Sie 'm/m' oder 'm/c' oder 'c/c' ein" << std::endl;
		std::string eingabe;
		std::cin >> eingabe;

		int spielerTyp[2] =
		{ MENSCH, MENSCH };
		if (eingabe == "m/m")
		{

			spielen(spielerTyp);
		}
		else if (eingabe == "m/c")
		{

			spielerTyp[1] = COMPUTER;
			spielen(spielerTyp);
		}
		else if (eingabe == "c/c")
		{
			spielerTyp[0] = COMPUTER;
			spielerTyp[1] = COMPUTER;
			spielen(spielerTyp);
		}
		else
		{
			std::cout << "Ungueltige Eingabe" << std::endl;
		}

		std::cout << "\n \nMöchten Sie eine weitere Runde spielen? enter y/n"
				<< std::endl;
		std::cin >> anotherRound;
	} while (anotherRound == 'y');

// int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
// spielen(spielerTyp);
//
// Hier erfolgt jetzt Ihre Implementierung ...

	return 0;
}

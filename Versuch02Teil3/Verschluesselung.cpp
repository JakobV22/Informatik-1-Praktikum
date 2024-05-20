///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cppv
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	for (int i = 0; i < (int) wort.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (wort[i] == schluessel[0][j])
			{

				wort[i] = schluessel[1][j];
				break;
			}

		}
	}
	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	for (int i = 0; i < (int) wort.length(); i++) // für jeden staben in wort
		{
			for (int j = 0; j < 26; j++) 			// für jeden Eintrag im Schlüssel
			{
				if (wort[i] == schluessel[1][j]) 	//Vergleich von Buchstabe und passendem Eintrag
				{

					wort[i] = schluessel[0][j];		//alter Buchstabe wird ersetzt
					break;
				}

			}
		}
	return wort;
}

int main()
{
	// Hier folgt Ihr Code
	char lookupTable[2][26] =
	{
	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
			'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	{ 'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L',
			'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A' } };
	string modus;
	while(true){
	cout << "Verschlüsseln oder Entschlüsseln (v/e)"<< endl; // Modus: Verschlüsseln oder entschlüsseln
	cin >> modus;
	if (modus == "v" || modus == "e"){
		break;
	}
	else{
		cout << "keine Gültige Eingabe" << endl;
	}
	}
	string eingabe;
	cout << "Geben Sie ein Wort ein (Großbuchstaben): " << endl;
	cin >> eingabe;
	if (modus == "v"){
	cout << "Eingabe: " << eingabe << "\nVerschlüsselt: " << verschluesseln(lookupTable, eingabe) //Verschlüsseln
			<< endl;
	}
	if (modus == "e"){
		cout << "Eingabe: " << eingabe << "\nEntschlüsselt: " << entschluesseln(lookupTable, eingabe) //Entschlüsseln
					<< endl;
	}


	return 0;
}

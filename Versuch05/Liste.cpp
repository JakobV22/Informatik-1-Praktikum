//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////
/**
 * Praktikum Informatik 1
 *
 *
 * @file Liste.cpp
 *
 * Die Methoden der Klasse Liste
 */


#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste() :
		front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
	ListenElement *neuesElement = new ListenElement(pData, nullptr, back); //next zeigt nullptr, prev zeigt vorheriges letztes Element

	if (front == nullptr)                                       // Liste leer?
	{
		front = neuesElement;
		back = neuesElement;
	}
	else
	{
		back->setNext(neuesElement);
		back = neuesElement;
	}
}
/**
 * @brief Fügt Element am Anfang der Liste ein
 * @param pData einzufügendes Element, Zeiger auf Klasse Student
 */
void Liste::pushFront(Student pData)
{
	ListenElement *neuesElement = new ListenElement(pData, front, nullptr); //next zeigt nullptr, prev zeigt vorheriges letztes Element

	if (front == nullptr)                                       // Liste leer?
	{
		front = neuesElement;
		back = neuesElement;
	}
	else
	{
		front->setPrev(neuesElement);
		front = neuesElement;
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
	ListenElement *cursor = front;

	if (front == back)                    // Liste enth�lt nur ein Listenelement
	{
		delete front;                                   // Listenelement l�schen
		front = nullptr;
		back = nullptr;
	}
	else
	{
		front = front->getNext();
		front->setPrev(nullptr);
		delete cursor;
	}
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
	if (front == nullptr)
	{
		return true;
	}
	return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
	return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
	ListenElement *cursor = front;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getNext();
	}
}
/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Elemenet
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement *cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}

}
/**
 * @brief Loescht Listenelement mit gesuchter Matrikelnummer
 * @param wantedMatr gesuchte Matrikelnummer
 */
void Liste::elementLoeschen(unsigned int wantedMatr)
{

	ListenElement *cursor = front;

	while (cursor != nullptr)
	{
		if (cursor->getData().getMatNr() == wantedMatr)
		{							// suche nach element mit richtiger Matr.nr
			cursor->getData().ausgabe();

			if (cursor->getPrev() == nullptr && cursor->getNext() != nullptr) //falls erstes Element
			{
				front = cursor->getNext();
				cursor->getNext()->setPrev(cursor->getPrev());
				delete cursor;
				return;
			}
			else if (cursor->getNext() == nullptr		//falls letztes Element
			&& cursor->getPrev() != nullptr)
			{
				back = cursor->getPrev();
				cursor->getPrev()->setNext(cursor->getNext());
				delete cursor;
				return;

			}
			else if (cursor->getPrev() == nullptr
					&& cursor->getNext() == nullptr)
			{ //einziges element
				front = nullptr;
				back = nullptr;
				delete cursor;
				return;
			}
			else
			{													//Normmalfall
				cursor->getPrev()->setNext(cursor->getNext());
				cursor->getNext()->setPrev(cursor->getPrev());
				return;
			}

		}
		cursor = cursor->getNext();
	}
	std::cout << "Student wurde nicht gefunden" << std::endl;
	return;

}

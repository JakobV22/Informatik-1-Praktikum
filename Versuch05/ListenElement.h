//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////
/**
 * Praktikum Informatik 1
 *
 *
 * @file ListenElement.h
 *
 * Die Definition der Klasse ListenElement
 */

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
	Student data;
	ListenElement *next;
	ListenElement *prev;  //von mir

public:
	ListenElement(Student pData, ListenElement *pNext, ListenElement *pPrev);//

	void setData(Student pData);
	void setNext(ListenElement *pNext);
	void setPrev(ListenElement *pPrev);			//
	Student getData() const;
	ListenElement* getNext() const;
	ListenElement* getPrev() const;					//
};

#endif

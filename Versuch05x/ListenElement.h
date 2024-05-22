//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;

public:
    ListenElement(Student pData, ListenElement* pNext);

    void setData(Student pData);
    void setNext(ListenElement* pNext);

    Student getData() const;
    ListenElement* getNext() const;
};

#endif

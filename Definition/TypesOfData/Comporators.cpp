#include "Person.h"
#include "MyString.h"

bool cmpInt(int const & first, int const & second)
{
    return first < second;
}

bool cmpPerson(Person const & perFirst, Person const & perSecond)
{
    MyString strNameFirst = perFirst.GetFirstName(), strNameSecond = perSecond.GetFirstName();
    if(strNameFirst.GetLength() == 0)
        return true;
    if(strNameSecond.GetLength() == 0)
        return false;

    if((int)(strNameFirst.Seize()[0]) < (int)(strNameSecond.Seize()[0]))
        return true;
    
    return false;
}
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

    bool returnBool = 0;
    
    char const *tmpNameFirst = strNameFirst.Seize();
    char const *tmpNameSecond = strNameSecond.Seize();
    if((int)(tmpNameFirst[0]) < (int)(tmpNameSecond[0]))
        returnBool = true;
    
    delete tmpNameFirst;
    delete tmpNameSecond;

    return returnBool;
}

bool cmpPointerPerson(Person * const &  pperFirst, Person * const &  pperSecond)
{
    Person perFirst = *pperFirst;
    Person perSecond = *pperSecond;
        MyString strNameFirst = perFirst.GetFirstName(), strNameSecond = perSecond.GetFirstName();
    if(strNameFirst.GetLength() == 0)
        return true;
    if(strNameSecond.GetLength() == 0)
        return false;

    bool returnBool = 0;

   char const *tmpNameFirst = strNameFirst.Seize();
    char const *tmpNameSecond = strNameSecond.Seize();
    if((int)(tmpNameFirst[0]) < (int)(tmpNameSecond[0]))
        returnBool = true;

    delete tmpNameFirst;
    delete tmpNameSecond;

    return returnBool;

}
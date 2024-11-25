#include <fstream>
#include <cmath>
#include <time.h>
#include "Sequence.h"
#include "Person.h"
#include "ArraySequence.h"

// Greater C++14

Sequence<Person*>* GenerateArraySequencePerson(int const count, DynamicArray<MyString>* Names, DynamicArray<MyString>* Surnames)
{
    Sequence<Person*> *seq;
    srand(time(NULL));
    try{
        seq = new MutableArraySequence<Person*>(count);
    }
    catch(...)
    {
        throw "can not make Sequence<Person*>*";
    }
    for(int i = 0; i < count; i++)
    {
        int indexName = rand() % 736;
        int indexSurname = rand() % 14651;
        MyString name = Names->Get(indexName);
        MyString lastName = Surnames->Get(indexSurname);
        MyString middleName = Names->Get(abs(indexSurname - indexName ) % 736) + MyString("ов");

        auto SFL{ [](MyString inputStr)->MyString //makeMyStringFixLength 
        {
            MyString addedStr(MLENGTH - inputStr.GetLength()); //MLENGTH in Person.h
            MyString outputStr = inputStr + addedStr;
            return outputStr;

        }};
        MyString tmpId = SFL(MyString::IntToMyString(i));
        MyString tmpName = SFL(name);
        MyString tmpMiddleName = SFL(middleName);
        MyString tmpLastName = SFL(lastName);
        Person *tmpPerson;
        try{
            tmpPerson = new Person(tmpId, tmpName, tmpMiddleName, tmpLastName, rand() % 220 + 1800) ;
        }
        catch(...)
        {
            throw "can not make Person";
        }
        //Person tmpPerson(SFL(MyString::IntToMyString(i)), SFL(name), SFL(middleName), SFL(lastName), i);
        seq->Set(i, tmpPerson);
    }
    
    return seq;

}
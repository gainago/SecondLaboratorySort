#include <fstream>
#include <cmath>
#include <time.h>
#include "Sequence.h"
#include "Person.h"
#include "ListSequence.h"
#include "DynamicArray.h"

Sequence<Person>* GenerateListSequencePerson(int const count, DynamicArray<MyString>* Names, DynamicArray<MyString>* Surnames)
{
    Sequence<Person> *seq = new MutableListSequence<Person>(count);
    srand(time(NULL));
    for(int i = 0; i < count; i++)
    {
        int indexName = (rand() % Names->GetCapacity());
        int indexSurname = (rand() % Surnames->GetCapacity());
        Person tmpPerson(nullptr, Names->Get(indexName), Surnames->Get(abs(indexSurname - indexName )), Surnames->Get(indexSurname), i);
        seq->Set(i, tmpPerson);
    }
    
    return seq;

}
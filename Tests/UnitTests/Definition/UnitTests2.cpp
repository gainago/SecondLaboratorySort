#include <cassert>
#include "Person.h"
#include "BubbleSorter.h"
#include "InsertionSorter.h"
#include "BitonicSorter.h"
#include "ShellSorter.h"
#include "MergeSorter.h"
#include "PiramidSorter.h"
#include "QuickSorter.h"
#include "GenerateArraySequenceInt.h"
#include "GenerateArraySequencePerson.h"
#include "Comporators.h"
#include "CheckCorrectlySorted.h"
#include "DynamicArray.h"
#include "MyString.h"
#include "GetNamesAndSournamesToMyString.h"
#include "ArraySequence.h"

void UnitTestsInt2()
{
    BubbleSorter<int> bSorter(cmpInt);
    InsertionSorter<int> iSorter(cmpInt);
    BitonicSorter<int> biSorter(cmpInt);
    ShellSorter<int> sSorter(cmpInt);
    MergeSorter<int> mSorter(cmpInt);
    PiramidSorter<int> pSorter(cmpInt);
    QuickSorter<int> qSorter(cmpInt);

    Sequence<int>* seq;

    for(int i = 100; i <= 100; i+=1000)
    {
        seq = GenerateArraySequenceInt(i);
        bSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;

        seq = GenerateArraySequenceInt(i);
        iSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;

        seq = GenerateArraySequenceInt(i);
        sSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;

        seq = GenerateArraySequenceInt(i);
        mSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;

        seq = GenerateArraySequenceInt(i);
        pSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;

        seq = GenerateArraySequenceInt(i);
        qSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;

    }

    for(int i = 2; i <=10; i*=2)
    {
        seq = GenerateArraySequenceInt(i);
        biSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpIntCheck));
        delete seq;
    }
}

void UnitTestsPerson2()
{

    BubbleSorter<Person*> bSorter(cmpPointerPerson);
    InsertionSorter<Person*> iSorter(cmpPointerPerson);
    BitonicSorter<Person*> biSorter(cmpPointerPerson);
    ShellSorter<Person*> sSorter(cmpPointerPerson);
    MergeSorter<Person*> mSorter(cmpPointerPerson);
    PiramidSorter<Person*> pSorter(cmpPointerPerson);
    QuickSorter<Person*> qSorter(cmpPointerPerson);

    Sequence<Person*>* seq;

    DynamicArray<MyString>* names = GetNamesToMyString();
    DynamicArray<MyString>* surnames = GetSurnamesToMyString();
    /*Person* per1 = new Person("", "0", "1", "2", 2005);
    Person* per2 = new Person("", "0", "1", "2", 2005);
    seq->Set(0, per2);
    seq->Set(1, per1);

    bSorter.Sort(*seq);
    for(int i = 0; i < seq->GetLength(); i++)
    {
        std::cout << i << ": " << seq->Get(i)->GetFirstName() << std::endl;
    }

    //assert(CheckCorrectlySorted(seq, cmpPointerPerson));*/
    for(int i = 100; i <= 100; i+=1000)
    {
        seq = GenerateArraySequencePerson(i, names, surnames);
        bSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;

        seq = GenerateArraySequencePerson(i, names, surnames);
        iSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;

        seq = GenerateArraySequencePerson(i, names, surnames);
        sSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;

        seq = GenerateArraySequencePerson(i, names, surnames);
        mSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;

        seq = GenerateArraySequencePerson(i, names, surnames);
        pSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;

        seq = GenerateArraySequencePerson(i, names, surnames);
        qSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;

    }

    for(int i = 2; i <=100; i*=2)
    {
        seq = GenerateArraySequencePerson(i, names, surnames);
        qSorter.Sort(*seq);
        assert(CheckCorrectlySorted(seq, cmpPointerPersonCheck));
        delete seq;
    }

    delete names;
    delete surnames;


}
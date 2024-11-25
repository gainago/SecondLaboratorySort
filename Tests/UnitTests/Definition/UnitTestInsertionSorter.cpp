#include "Sequence.h"
#include "ArraySequence.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
#include "InsertionSorter.h"
#include "GenerateArraySequenceInt.h"
#include "PrintSeq.h"
#include <cassert>

void HandWrittenInsertionTests()
{
    int arr[10] = {1, 2, 3, -4, -5, -6, 0, 0, 0, 13};
    Sequence<int> *seq = new MutableArraySequence<int>(arr, 10);
    InsertionSorter<int> iSorter(cmpInt);
    iSorter.Sort(seq); 
    assert(CheckCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = new MutableArraySequence<int>;
    iSorter.Sort(seq2);
    assert(CheckCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;

}

void AutomaticallyGeneratedDataInsertionTests()
{
    Sequence<int> *seq = GenerateArraySequenceInt(100);
    InsertionSorter<int> iSorter(cmpInt);
    iSorter.Sort(seq);
    assert(CheckCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = GenerateArraySequenceInt(0);
    iSorter.Sort(seq2);
    assert(CheckCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;
}
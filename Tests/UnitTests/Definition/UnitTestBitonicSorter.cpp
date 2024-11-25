#include "Sequence.h"
#include "ArraySequence.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
#include "BitonicSorter.h"
#include "GenerateArraySequenceInt.h"
#include "PrintSeq.h"
#include <cassert>

void HandWrittenBitonicTests()
{
    int arr[16] = {1, 2, 3, -4, -5, -6, 0, 0, 0, 13, 136, 1, 1, 1, -1, 4};
    Sequence<int> *seq = new MutableArraySequence<int>(arr, 16);
    BitonicSorter<int> bSorter(cmpInt);
    bSorter.Sort(seq); 
    //PrintSeq(seq);
    assert(CheckCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = new MutableArraySequence<int>;
    bSorter.Sort(seq2);
    assert(CheckCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;

}

void AutomaticallyGeneratedDataBitonicTests()
{
    Sequence<int> *seq = GenerateArraySequenceInt(128);
    BitonicSorter<int> bSorter(cmpInt);
    bSorter.Sort(seq);
    assert(CheckCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = GenerateArraySequenceInt(0);
    bSorter.Sort(seq2);
    assert(CheckCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;
}
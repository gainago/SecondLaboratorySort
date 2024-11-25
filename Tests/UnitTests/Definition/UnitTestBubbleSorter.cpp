#include "Sequence.h"
#include "ArraySequence.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
#include "BubbleSorter.h"
#include "GenerateArraySequenceInt.h"
#include "PrintSeq.h"
#include <cassert>

void HandWrittenBubbleTests()
{
    int arr[10] = {1, 2, 3, -4, -5, -6, 0, 0, 0, 13};
    Sequence<int> *seq = new MutableArraySequence<int>(arr, 10);
    BubbleSorter<int> bSorter(cmpInt);
    bSorter.Sort(seq); 
    assert(CheckCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = new MutableArraySequence<int>;
    bSorter.Sort(seq2);
    assert(CheckCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;

}

void AutomaticallyGeneratedDataBubbleTests()
{
    Sequence<int> *seq = GenerateArraySequenceInt(100);
    BubbleSorter<int> bSorter(cmpInt);
    bSorter.Sort(seq);
    assert(CheckCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = GenerateArraySequenceInt(0);
    bSorter.Sort(seq2);
    assert(CheckCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;
}
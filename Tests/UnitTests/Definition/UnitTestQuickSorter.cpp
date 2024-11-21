#include "Sequence.h"
#include "ArraySequence.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
#include "QuickSorter.h"
#include "GenerateArraySequenceInt.h"
#include <cassert>

void HandWrittenQuickTests()
{
    int arr[10] = {1, 2, 3, -4, -5, -6, 0, 0, 0, 13};
    Sequence<int> *seq = new MutableArraySequence<int>(arr, 10);
    QuickSorter<int> qSorter(cmpInt);
    qSorter.Sort(seq);
    
    assert(SeqIsCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = new MutableArraySequence<int>;
    qSorter.Sort(seq2);
    assert(SeqIsCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;

}

void AutomaticallyGeneratedDataQuickTests()
{
    Sequence<int> *seq = GenerateArraySequenceInt(100);
    QuickSorter<int> qSorter(cmpInt);
    qSorter.Sort(seq);
    assert(SeqIsCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = GenerateArraySequenceInt(0);
    qSorter.Sort(seq2);
    assert(SeqIsCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;
}
#include "Sequence.h"
#include "ArraySequence.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
#include "ShellSorter.h"
#include "GenerateArraySequenceInt.h"
#include "PrintSeq.h"
#include <cassert>

void HandWrittenShellTests()
{
    int arr[10] = {1, 2, 3, -4, -5, -6, 0, 0, 0, 13};
    Sequence<int> *seq = new MutableArraySequence<int>(arr, 10);
    ShellSorter<int> sSorter(cmpInt);
    sSorter.Sort(seq); 
    assert(SeqIsCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = new MutableArraySequence<int>;
    sSorter.Sort(seq2);
    assert(SeqIsCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;

}

void AutomaticallyGeneratedDataShellTests()
{
    Sequence<int> *seq = GenerateArraySequenceInt(100);
    ShellSorter<int> sSorter(cmpInt);
    sSorter.Sort(seq);
    assert(SeqIsCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = GenerateArraySequenceInt(0);
    sSorter.Sort(seq2);
    assert(SeqIsCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;
}
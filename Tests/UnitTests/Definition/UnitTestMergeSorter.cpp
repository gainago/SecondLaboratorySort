#include "Sequence.h"
#include "ArraySequence.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
#include "MergeSorter.h"
#include "GenerateArraySequenceInt.h"
#include "PrintSeq.h"
#include <cassert>

void HandWrittenMergeTests()
{
    int arr[10] = {1, 2, 3, -4, -5, -6, 0, 0, 0, 13};
    Sequence<int> *seq = new MutableArraySequence<int>(arr, 10);
    MergeSorter<int> mSorter(cmpInt);
    mSorter.Sort(seq);
    
    assert(SeqIsCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    // Sequence<int> *seq2 = new MutableArraySequence<int>;
    // mSorter.Sort(seq2);
    // assert(SeqIsCorrectlySorted<int>(seq2, cmpInt));
    // delete seq2;

}

void AutomaticallyGeneratedDataMergeTests()
{
    Sequence<int> *seq = GenerateArraySequenceInt(100);
    MergeSorter<int> mSorter(cmpInt);
    mSorter.Sort(seq);
    assert(SeqIsCorrectlySorted<int>(seq, cmpInt));
    delete seq;

    Sequence<int> *seq2 = GenerateArraySequenceInt(0);
    mSorter.Sort(seq2);
    assert(SeqIsCorrectlySorted<int>(seq2, cmpInt));
    delete seq2;
}
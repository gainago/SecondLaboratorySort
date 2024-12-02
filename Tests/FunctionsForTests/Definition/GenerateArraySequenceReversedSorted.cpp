#include "Sequence.h"
#include "ArraySequence.h"

Sequence<int>* GenerateArraySequenceReversedSorted(int size)
{
    Sequence<int>* seq = new MutableArraySequence<int>(size);
    int j = size;
    for(int i = 0; i < size; i++)
    {
        seq->Set(i, j);
        j--;
    }

    return seq;
}
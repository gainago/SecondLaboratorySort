#include "Sequence.h"
#include "ArraySequence.h"

Sequence<int>* GenerateArraySequenceSortedInt(int size)
{
    Sequence<int>* seq = new MutableArraySequence<int>(size);
    for(int i = 0; i < size; i++)
    {
        seq->Set(i, i);
    }

    return seq;
}
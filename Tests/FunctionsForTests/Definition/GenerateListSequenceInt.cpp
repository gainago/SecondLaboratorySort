#include <cstdlib>
#include <time.h>
#include "ListSequence.h"
Sequence<int>* GenerateListSequenceInt(int const count)
{
    Sequence<int> *seq = new MutableListSequence<int>(count);
    srand(time(NULL));
    for(int i = 0; i < count; i++)
    {
        seq->Set(i, rand());
    } 
    return seq;
}
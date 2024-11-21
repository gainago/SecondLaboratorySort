#include <cstdlib>
#include <time.h>
#include "ArraySequence.h"
Sequence<int>* GenerateArraySequenceInt(int const count)
{
    Sequence<int> *seq = new MutableArraySequence<int>(count);
    srand(time(NULL));
    for(int i = 0; i < count; i++)
    {
        seq->Set(i, rand());
    } 
    return seq;
}
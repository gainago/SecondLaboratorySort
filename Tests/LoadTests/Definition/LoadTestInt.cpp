
#include <chrono>
#include <cassert>

#include "MyString.h"
#include "Sequence.h"
#include "DynamicArray.h"
#include "AbstractSorter.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
//do not use that function for BitonicSort
double LoadTestInt(Sequence<int>* seqToSort, Sorter<int> *sorter)
{
        auto start = std::chrono::high_resolution_clock::now();
        sorter->Sort(*seqToSort);
        auto end = std::chrono::high_resolution_clock::now();
        assert(CheckCorrectlySorted(seqToSort, cmpIntCheck));

        const std::chrono::duration<double> diff = end - start;
        return std::chrono::duration<double>(diff).count();
}

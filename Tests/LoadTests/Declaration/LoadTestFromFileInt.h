#ifndef FILE_TEST_H
#define FILE_TEST_H

#include "MyString.h"
#include "Sequence.h"
#include "AbstractSorter.h"
//do not use that function for BitonicSort
 double LoadTestFromFileInt(MyString fileName, Sequence<int> *seq, Sorter<int> *sorter);

#endif
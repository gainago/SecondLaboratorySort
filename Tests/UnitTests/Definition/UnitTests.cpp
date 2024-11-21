#include "UnitTestBubbleSorter.h"
#include "UnitTestQuickSorter.h"
#include "UnitTestMergeSorter.h"
#include "UnitTestInsertionSorter.h"
#include "UnitTestPiramidSorter.h"
#include "UnitTestShellSorter.h"
#include "UnitTestBitonicSorter.h"

void UnitTests()
{
    HandWrittenBubbleTests();
    AutomaticallyGeneratedDataBubbleTests();
    HandWrittenQuickTests();
    AutomaticallyGeneratedDataQuickTests();
    HandWrittenMergeTests();
    AutomaticallyGeneratedDataMergeTests();
    HandWrittenInsertionTests();
    AutomaticallyGeneratedDataInsertionTests();
    HandWrittenPiramidTests();
    AutomaticallyGeneratedDataPiramidTests();
    HandWrittenShellTests();
    AutomaticallyGeneratedDataShellTests();
    HandWrittenBitonicTests();
    AutomaticallyGeneratedDataBitonicTests();
}
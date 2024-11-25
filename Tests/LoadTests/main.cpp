#include <iostream>
#include "MyString.h"
#include "Sequence.h"
#include "FileTest.h"
#include "ArraySequence.h"
#include "BubbleSorter.h"
#include "Comporators.h"

int main(int argc, char **argv)
{
    Sequence<int> *seq = new MutableArraySequence<int>;
    BubbleSorter<int> bSorter(cmpInt);
    MyString fileName("")
}
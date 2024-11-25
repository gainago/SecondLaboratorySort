#ifndef LOAD_TEST_FROM_FILE_PERSON_H
#define LOAD_TEST_FROM_FILE_PERSON_H

#include "MyString.h"
#include "Sequence.h"
#include "Person.h"
#include "AbstractSorter.h"

double LoadTestFromFilePerson(MyString fileName, Sequence<Person*> *seqBased, Sorter<Person*> *sorter);

#endif //LOAD_TEST_FROM_FILE_H
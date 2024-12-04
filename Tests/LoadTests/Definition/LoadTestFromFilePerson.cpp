#include <fstream>
#include <chrono>

#include "MyString.h"
#include "Sequence.h"
#include "DynamicArray.h"
#include "AbstractSorter.h"
#include "Person.h"
//do not use that function for BitonicSort
double LoadTestFromFilePerson(MyString fileName, Sequence<Person*> *seqBased, Sorter<Person*> *sorter)
{
     auto GetSize{ [](MyString inputStr)->int //GetLength
        {
            int strSize = 0;
            for(int i = 0; i < inputStr.GetLength(); i++)
            {
                if((48 <= (int)inputStr[i]) && ((int)inputStr[i] <= 57)){

                    if(strSize <= (__INT_MAX__  - 9)/ 10)
                    {
                        strSize*=10;
                        strSize+=((int)inputStr[i] - 48);
                    }
                    else{
                        throw "size more than __INT_MAX__";
                    }
                }
            }

            return strSize;

        }};

        Sequence<Person*> *seqToSort = seqBased->GetNewSequence(GetSize(fileName));
        //DynamicArray<int> arr(GetSize(fileName));
        std::ifstream ifs;
        MyString fileLocation("../DataToTests/");
        MyString fullName = fileLocation + fileName;
        char const *tmpptr = fullName.Seize();
        ifs.open(tmpptr, std::ios::in);
        delete tmpptr;
        if(!ifs.is_open()){
            throw " can not open file";
        }

        for(int i = 0; i < seqToSort->GetLength(); i++)
        {
            char strId[Person::GetMaxLength()];
            char strFirstName[Person::GetMaxLength()];
            char strMiddleName[Person::GetMaxLength()];
            char strLastName[Person::GetMaxLength()];
            int bornAge;
            ifs >> strId >> strFirstName >> strMiddleName >> strLastName >> bornAge;
            //std::cout << strId << "\t" << strFirstName << "\t" << strMiddleName << "\t" << strLastName << "\t" << bornAge << std::endl;
            Person* tmpPerson = new Person(strId, strFirstName, strMiddleName, strLastName, bornAge);
            seqToSort->Set(i, tmpPerson);

        }

        auto start = std::chrono::high_resolution_clock::now();
        sorter->Sort(*seqToSort);
        auto end = std::chrono::high_resolution_clock::now();

        const std::chrono::duration<double> diff = end - start;
        for(int i = 0; i < seqToSort->GetLength(); i++)
        {
            delete seqToSort->Get(i);

        }
        delete seqToSort;
        return std::chrono::duration<double>(diff).count();
}
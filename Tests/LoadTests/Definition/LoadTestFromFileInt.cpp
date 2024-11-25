#include <fstream>
#include <chrono>
#include <cassert>

#include "MyString.h"
#include "Sequence.h"
#include "DynamicArray.h"
#include "AbstractSorter.h"
#include "CheckCorrectlySorted.h"
#include "Comporators.h"
//do not use that function for BitonicSort
double LoadTestFromFileInt(MyString fileName, Sequence<int> *seqBased, Sorter<int> *sorter)
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

        Sequence<int> *seqToSort = seqBased->GetNewSequence(GetSize(fileName));
        //DynamicArray<int> arr(GetSize(fileName));
        std::ifstream ifs;
        MyString fileLocation("../DataToTests/");
        MyString fullName = fileLocation + fileName;
        char const *tmpFileName = fullName.Seize();
        ifs.open(tmpFileName, std::ios::in);
        delete tmpFileName;
        if(!ifs.is_open()){
            throw " can not open file";
        }

        for(int i = 0; i < seqToSort->GetLength(); i++)
        {
            int tmpInt = 0;
            ifs >> tmpInt;
            seqToSort->Set(i, tmpInt);
        }

        auto start = std::chrono::high_resolution_clock::now();
        sorter->Sort(seqToSort);
        auto end = std::chrono::high_resolution_clock::now();
        assert(CheckCorrectlySorted(seqToSort, cmpInt));
        const std::chrono::duration<double> diff = end - start;
        delete seqToSort;

        return std::chrono::duration<double>(diff).count();
}
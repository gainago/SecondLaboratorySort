#include <fstream>
#include <chrono>

#include "MyString.h"
#include "Sequence.h"
#include "DynamicArray.h"
#include "AbstractSorter.h"

#include "MyString.h"

double LoadTestDynamicArrayIntFile(MyString fileName)
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

        //Sequence<int> *seqToSort = seqBased->GetNewSequence(GetSize(fileName));
        DynamicArray<int> arr(GetSize(fileName));
        std::ifstream ifs;
        MyString fileLocation("../DataToTests/");
        MyString fullName = fileLocation + fileName;
        ifs.open(fullName.Seize(), std::ios::in);
        if(!ifs.is_open()){
            throw " can not open file";
        }

        for(int i = 0; i < arr.GetCapacity(); i++)
        {
            int tmpInt = 0;
            ifs >> tmpInt;
            arr.Set(i, tmpInt);
        }

        auto start = std::chrono::high_resolution_clock::now();

        //sorter->Sort(seqToSort);

            
    
        for(int i = 0; i < arr.GetCapacity(); i++)
        {
            for(int j = 0; j < arr.GetCapacity() - i - 1; j++)
            {
                if(arr[j + 1] < arr[j]){

                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
            std::cout << "i = " << i << std::endl;
        }

    
        auto end = std::chrono::high_resolution_clock::now();

        const std::chrono::duration<double> diff = end - start;

        return std::chrono::duration<double>(diff).count();
}
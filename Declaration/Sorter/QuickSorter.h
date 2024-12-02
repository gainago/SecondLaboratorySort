#ifndef QUICK_SORTER_H
#define QUICK_SORTER_H

//#include <iostream> //актульно для сиквенсов. функции отладочной печати нужно изолировать 
// не актульно печать в консоль
//это много варинтов как сделать 
//#include <cstdlib> // не использовать файл исходного тектса как архив
//можно объявить в основном файле
//написать в общий чат тегнул Михаила завтра как выносить зависимости от iostream из Sequence
#include "AbstractSorter.h"
//#include "PrintSeq.h"

template <typename Type>  class QuickSorter : public Sorter<Type>
{
public:

    QuickSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    QuickSorter(QuickSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>& seq) override
    {
        //Sequence<Type>* seqToSort = seq->GetInstance();
        quickSort(seq, 0, seq.GetLength() - 1);

    }

private:

    void quickSort(Sequence<Type>& seq, int low, int high) //ошибка в именовании 
                                                            // 
    {
        if(high <= low)
            return;

        int mainNumber = (high - low) / 2 + low;

        Type midElement = seq.Get(mainNumber);

        int left = low, right = high;

        while(left <= right)
        {

        // for(int i = low; i <= high; i++)
        // {
        //     //std::cout << i << ". " << seq->Get(i) << std::endl;
        //     printf("%2d. %d", i, seq->Get(i));
        //     std::cout << std::endl;
        // }

            while(this->cmp_(seq.Get(left), midElement))
                left++;
                
            while(this->cmp_(midElement, seq.Get(right)))
            {    right--;
            }
                if(left <= right) {

                    Type tmp = seq.Get(left);
                    seq.operator[](left) = seq.Get(right);
                    seq.operator[](right) = tmp;

                    left++;
                    right--;
                }
        }
        if(right > low)
            quickSort(seq, low, right);
        if(left < high)
            quickSort(seq, left, high);

    }

};

#endif
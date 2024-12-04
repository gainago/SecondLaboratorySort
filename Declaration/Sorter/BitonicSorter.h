#ifndef BITONIC_SORTER_H
#define BITONIC_SORTER_H

#include "AbstractSorter.h"

//работает только на массивах длины равной степени двойки
template <typename Type>  class BitonicSorter : public Sorter<Type>
{
public:

    BitonicSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    BitonicSorter(BitonicSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>& seq) override
    {
         auto IsPower2{ [](int size)->bool //checkSizeSeq 
        {
            if(size == 0)
                return true;
            while(size != 1)
            {
                if(size % 2 != 0)
                {
                    return false;
                }
                size = size / 2;
            }

            return true;

        }};
        if(!IsPower2(seq.GetLength()))
            throw "size of seq must be power of 2";

        BitonicSort(seq, 0, seq.GetLength(), 1);
    }
private:

    
    void SortOrder(Sequence<Type>& seq, int i, int j, int order)
    {
        if( order == this->cmp_(seq.Get(j), seq.Get(i))){
            Type tmp = seq.Get(i);
            seq.Set(i, seq.Get(j));
            seq.Set(j, tmp);
        }
    }

        /* Pекурсивно сортирует последовательность в порядке возрастания
    (dir == 1), или убывания (dir == 0).
    Сортируемая последовательность начинается с младшей позиции индекса,
    параметр cnt - это количество элементов для сортировки. */


    
    void Merge(Sequence<Type>& seq, int lowIndex, int quantity, int order)
    {
        if(quantity > 1){
            int k = quantity / 2;
            
            for(int i = lowIndex; i < lowIndex + k; i++)
            {
                SortOrder(seq, i, i + k, order);
            }
            Merge(seq, lowIndex, k, order);
            Merge(seq, lowIndex + k, k, order);
        }
    }
    
    
    void BitonicSort(Sequence<Type>& seq, int lowIndex, int quantity, bool order)
    {
        if(quantity > 1){
            int k = quantity / 2;
            BitonicSort(seq, lowIndex, k, 1);
            BitonicSort(seq, lowIndex + k, k, 0);
            Merge(seq, lowIndex, quantity, order);
        }
    }
};

#endif
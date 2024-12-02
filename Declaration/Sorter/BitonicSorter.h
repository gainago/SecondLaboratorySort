#ifndef BITONIC_SORTER_H
#define BITONIC_SORTER_H

#include "AbstractSorter.h"
#include "PrintSeq.h"
#include <stdio.h>
#include <iostream>
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

    // void sortdir(int a[], int i, int j, int dir) { //возрастание или убывание
    //      if (dir == (a[i] > a[j])) swap(a[i], a[j]);
    // }
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


    // void merge(int a[], int low, int cnt, int dir) {
    //     if (cnt > 1) {
    //     int k = cnt / 2;
    //     for (int i = low; i < low + k; i++) sortdir(a, i, i + k, dir);
    //     merge(a, low, k, dir);
    //     merge(a, low + k, k, dir);
    //     }
    // }
    void Merge(Sequence<Type>& seq, int lowIndex, int quantity, int order)
    {
        if(quantity > 1){
            int k = quantity / 2;
            // for(int i = lowIndex; i < lowIndex + k; i++)
            // {
            //     printf("%2d. %d", i, seq->Get(i));
            //     std::cout << std::endl;
            // }
            for(int i = lowIndex; i < lowIndex + k; i++)
            {
                SortOrder(seq, i, i + k, order);
            }
            Merge(seq, lowIndex, k, order);
            Merge(seq, lowIndex + k, k, order);
        }
    }
    
    /* Создаём последовательность рекурсивно.
    Сортируем две половинки, затем вызываем merge */
    // void sort(int a[], int low, int cnt, int dir) {
    //     if (cnt > 1) {
    //     int k = cnt / 2;
    //     sort(a, low, k, 1);
    //     sort(a, low + k, k, 0);
    //     merge(a, low, cnt, dir);
    //     }
    // }
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
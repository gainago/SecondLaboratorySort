#ifndef INSERTION_SORTER_H
#define INSERTION_SORTER_H

#include "AbstractSorter.h"

template <typename Type>  class InsertionSorter : public Sorter<Type>
{
public:

    InsertionSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    InsertionSorter(InsertionSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>& seq) override
    {
        InsertionSort(seq);
    }
private:

    void InsertionSort(Sequence<Type>& seq)
    {
        for(int i = 1; i < seq.GetLength(); i++)
        {     
	        for(int j = i; j > 0 && this->cmp_(seq.Get(j), seq.Get(j - 1));j--)
            {                            // пока j>0 и элемент j-1 > j, x-массив int
			                               // меняем местами элементы j и j-1
                Type tmp = seq.Get(j);
                seq.Set(j, seq.Get(j - 1));
                seq.Set(j - 1, tmp);
            }
        }
    }
};

#endif
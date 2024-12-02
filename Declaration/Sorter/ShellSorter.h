#ifndef SHELL_SORTER_H
#define SHELL_SORTER_H

#include "AbstractSorter.h"

template <typename Type>  class ShellSorter : public Sorter<Type>
{
public:

    ShellSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    ShellSorter(ShellSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>& seq) override
    {
        ShellSort(seq);
    }
private:

    void ShellSort(Sequence<Type>& seq)
    {
        int i = 0, j = 0, step = 0;
        Type tmp;
        for (step = seq.GetLength() / 2; step > 0; step /= 2)
            for (i = step; i < seq.GetLength(); i++)
            {
                tmp = seq.Get(i);
                for (j = i; j >= step; j -= step)
                {
                    if (this->cmp_(tmp, seq.Get(j - step)))
                       // mass[j] = mass[j - step];
                       seq.Set(j, seq.Get(j - step));
                    else
                        break;
                }
                //mass[j] = tmp;
                seq.Set(j, tmp);
            }
    }
};

#endif
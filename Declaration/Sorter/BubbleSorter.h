#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

#include "AbstractSorter.h"

template <typename Type>  class BubbleSorter : public Sorter<Type>
{
public:

    BubbleSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    BubbleSorter(BubbleSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>* seq) override
    {
        //Sequence<Type>* seqToSort = seq->GetInstance();// так делать плохо потому что пользователь при получении результата
                                                        //может дважды очистить пямять 
                                                        //делать только с мутабельными сиквенсами
                                                        // и соответственно ничего не возаращаьб
                                                        //метод гет инстанс в целом  плохая идея из зи этой же проблемы
        BubbleSort(seq);

    }
private:

    void BubbleSort(Sequence<Type>* seq)
    {
        for(int i = 0; i < seq->GetLength(); i++)
        {
            for(int j = 0; j < seq->GetLength() - i - 1; j++)
            {
                if(this->cmp_(seq->Get(j + 1), seq->Get(j))){

                    Type tmp = seq->Get(j);
                    seq->Set(j, seq->Get(j + 1));
                    seq->Set(j + 1, tmp);
                }
            }
        }

    }

};

#endif
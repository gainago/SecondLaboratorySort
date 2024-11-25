#ifndef CHECK_CORRECTLY_SORTED_H
#define CHECK_CORRECTLY_SORTED_H

#include <iostream>

#include "Sequence.h"
#include "PrintSeq.h"

template <typename Type> bool CheckCorrectlySorted(Sequence<Type> const *seq, bool (*cmp)(Type const &, Type const &))
{
    //PrintSeq(seq);
    for(int i = 0; i < seq->GetLength() - 1; i++)
    {
        if((!cmp(seq->Get(i), seq->Get(i + 1)) && (seq->Get(i) != seq->Get(i + 1))))
        {
           /* std::cout << "i = " << i << std::endl;
            std::cout << "i element = " << std::cout << seq->Get(i) << std::endl;
            std::cout << "i + 1 element = " << std::cout << seq->Get(i + 1) << std::endl;*/
            return false;
        }
            
    }

    return true;
}

//template bool SeqIsCorrectlySorted<int>(Sequence<int> const *seq, bool (*cmp)(int const &, int const &));


#endif //CHECK_CORRECTLY_SORTED_H
#ifndef ABSTRACT_SORTER_H
#define ABSTRACT_SORTER_H

#include "Sequence.h"

template <typename Type> class Sorter{

protected:

    
    bool (*cmp_)(Type const &, Type const &); // isLeftLessRight

public:

    Sorter(bool (*cmp)(Type const &, Type const &)) : cmp_(cmp) {} // лучше вынести в protected
    Sorter(Sorter<Type>* other) : cmp_(other->cmp_) {} // Сортер абстрактный так что в этом конструкторе нет смысла

    virtual void Sort(Sequence<Type>& seq) = 0;         //only for Mutable Sequences 
                                                        //заменить указатель на ссылку и избавимся от указателя являющегося nullptr

    virtual ~Sorter() {};

};

#endif
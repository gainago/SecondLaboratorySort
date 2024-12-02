#ifndef PIRAMID_SORTER_H
#define PIRAMID_SORTER_H

#include "AbstractSorter.h"

template <typename Type>  class PiramidSorter : public Sorter<Type>
{
public:

    PiramidSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    PiramidSorter(PiramidSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>& seq) override
    {
        //Sequence<Type>* seqToSort = seq->GetInstance();
        piramidSort(seq, seq.GetLength());

    }
    
private:

    void piramidSort(Sequence<Type>& seq, int n)
    {   
                                        // Построение кучи (перегруппируем массив)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(seq, n, i);

                                         // Один за другим извлекаем элементы из кучи
        for (int i = n-1; i >= 0; i--)
        {
                                        // Перемещаем текущий корень в конец
            //PrintSeq(seq);                           //swap(arr[0], arr[i]);
            Type tmp = seq.Get(0);
            seq.Set(0, seq.Get(i));
            seq.Set(i, tmp);       
            //PrintSeq(seq);  

                                        // вызываем процедуру heapify на уменьшенной куче
            heapify(seq, i, 0);
        }   
    }
    
    void heapify(Sequence<Type>& seq, int n, int i)
    {
        int largest = i;   
                                        // Инициализируем наибольший элемент как корень
        int l = 2*i + 1; // левый = 2*i + 1
        int r = 2*i + 2; // правый = 2*i + 2

                                        // Если левый дочерний элемент больше корня
        //if (l < n && seq->Get(l) > seq->Get(largest))
        if(l < n && this->cmp_(seq.Get(largest), seq.Get(l)))
            largest = l;

                                        // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
        //if (r < n && seq->Get(r) > seq->Get(largest))
        if(r < n && this->cmp_(seq.Get(largest), seq.Get(r)))
            largest = r;

                                        // Если самый большой элемент не корень
        if (largest != i)
        {
            //swap(arr[i], arr[largest]);
            //PrintSeq(seq);  
            Type tmp = seq.Get(i);
            seq.Set(i, seq.Get(largest));
            seq.Set(largest, tmp);

            //PrintSeq(seq);                            // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
            heapify(seq, n, largest);
        }
}   



};

#endif
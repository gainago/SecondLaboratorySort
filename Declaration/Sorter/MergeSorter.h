#ifndef MERGE_SORTER_H
#define MERGE_SORTER_H

#include "AbstractSorter.h"

template <typename Type>  class MergeSorter : public Sorter<Type>
{
public:

    MergeSorter(bool (*cmp)(Type const &, Type const &)) : Sorter<Type>(cmp) {}
    MergeSorter(MergeSorter<Type> const & other) : Sorter<Type>(other.cmp_) {}

    void Sort(Sequence<Type>& seq) override
    {
        //Sequence<Type>* seqToSort = seq->GetInstance();
        if(seq.GetLength() <= 1)
            return;
        Sequence<Type>* seqResult = mergeSortFirst(&seq);

        for(int i = 0; i < seq.GetLength(); i++)
        {
            seq.Set(i, seqResult->Get(i));
        }

        delete seqResult;

    }

private:

        Sequence<Type>* mergeSortFirst(Sequence<Type>* seq) {           // сперва вызываем эту функцию 
                                                                        //чтобы не удалить исходный Sequence 
                                                                        
        if (seq->GetLength() <= 1) {
            return seq;
        }
        
        Sequence<Type>* seqLeft = seq->GetSubSequence(0, seq->GetLength() / 2); 
       
        Sequence<Type>* seqRight = seq->GetSubSequence(seqLeft->GetLength(), seq->GetLength());
        
        Sequence<Type>* seqMerged = merge(mergeSort(seqLeft), mergeSort(seqRight));
        

        

        return seqMerged;
        }

        Sequence<Type>* mergeSort(Sequence<Type>* seq) {
        if (seq->GetLength() <= 1) {
            return seq;
        }
        
        Sequence<Type>* seqLeft = seq->GetSubSequence(0, seq->GetLength() / 2);
       
        Sequence<Type>* seqRight = seq->GetSubSequence(seqLeft->GetLength(), seq->GetLength());
        
        Sequence<Type>* seqMerged = merge(mergeSort(seqLeft), mergeSort(seqRight));
        

        delete seq;

        return seqMerged;
    }

        Sequence<Type>* merge(Sequence<Type>* seqLeft, Sequence<Type>* seqRight) {
        int index = 0, indexL = 0, indexR = 0;
        Sequence<Type>* seqResult = seqLeft->GetNewSequence(seqLeft->GetLength() + seqRight->GetLength());                 //new int[left.length + right.length];
        while (indexL < seqLeft->GetLength() && indexR < seqRight->GetLength()) {
            //result[index++] = left[indexL] < right[indexR] ? left[indexL++] : right[indexR++]; //краткий смысл цикла
            if(this->cmp_(seqLeft->Get(indexL), seqRight->Get(indexR))){
                seqResult->Set(index++, seqLeft->Get(indexL++));
            }
            else{
                seqResult->Set(index++, seqRight->Get(indexR++));
            }
        }
        while (index < seqResult->GetLength()) {
            //result[index++] = indexL != left.length ? left[indexL++] : right[indexR++];
            if(indexL != seqLeft->GetLength()){
                seqResult->Set(index++, seqLeft->Get(indexL++));
            }
            else{
                seqResult->Set(index++, seqRight->Get(indexR++));
            }
        }

        delete seqLeft;
        delete seqRight;                                            //память нигде не уекает все проверил через valgrind
        return seqResult;
    }
    

};

#endif
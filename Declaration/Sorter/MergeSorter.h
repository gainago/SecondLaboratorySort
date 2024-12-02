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
        //int[] left = Arrays.copyOfRange(src, 0, src.length / 2);
        Sequence<Type>* seqLeft = seq->GetSubSequence(0, seq->GetLength() / 2);
       //PrintSeq(seqLeft);
        //int[] right = Arrays.copyOfRange(src, left.length, src.length);
        Sequence<Type>* seqRight = seq->GetSubSequence(seqLeft->GetLength(), seq->GetLength());
        //PrintSeq(seqRight);
        Sequence<Type>* seqMerged = merge(mergeSort(seqLeft), mergeSort(seqRight));
        //PrintSeq(seqMerged);

        

        return seqMerged;
        }

        Sequence<Type>* mergeSort(Sequence<Type>* seq) {
        if (seq->GetLength() <= 1) {
            return seq;
        }
        //int[] left = Arrays.copyOfRange(src, 0, src.length / 2);
        Sequence<Type>* seqLeft = seq->GetSubSequence(0, seq->GetLength() / 2);
       //PrintSeq(seqLeft);
        //int[] right = Arrays.copyOfRange(src, left.length, src.length);
        Sequence<Type>* seqRight = seq->GetSubSequence(seqLeft->GetLength(), seq->GetLength());
        //PrintSeq(seqRight);
        Sequence<Type>* seqMerged = merge(mergeSort(seqLeft), mergeSort(seqRight));
        //PrintSeq(seqMerged);

        delete seq;

        return seqMerged;
    }

        Sequence<Type>* merge(Sequence<Type>* seqLeft, Sequence<Type>* seqRight) {
        int index = 0, indexL = 0, indexR = 0;
        Sequence<Type>* seqResult = seqLeft->GetNewSequence(seqLeft->GetLength() + seqRight->GetLength());                 //new int[left.length + right.length];
        while (indexL < seqLeft->GetLength() && indexR < seqRight->GetLength()) {
            //result[index++] = left[indexL] < right[indexR] ? left[indexL++] : right[indexR++];
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
        delete seqRight;
        //PrintSeq(seqResult);
        return seqResult;
    }
    

};

#endif
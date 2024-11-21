#include <fstream>

#include "Sequence.h"
#include "GenerateArraySequencePerson.h"
#include "MyString.h"
#include "Person.h"
#include "DynamicArray.h"


void WritePersonToFile(int const count, DynamicArray<MyString> *Names, DynamicArray<MyString> *Sournames)
{
    Sequence<Person*> *seq = GenerateArraySequencePerson(count, Names, Sournames);
    std::ofstream ofs;
    MyString strFile("../DataToTests/GeneratedPerson"); //make name to file
    strFile = strFile + MyString::IntToMyString(count);

    char* nameFile = strFile.Seize();
    ofs.open(nameFile);
    delete nameFile;

    if(!ofs.is_open()){
        throw "can not open file";
    }
    //std::cout << "AAAAAAAAAa" << std::endl;
    for(int i = 0; i < count; i++)
    {
        ofs << *(seq->Get(i));
        std::cout << "size of Person is: " << sizeof(*(seq->Get(i))) <<std::endl;
    }

    for(int i = 0; i < seq->GetLength(); i++)
    {
        delete seq->Get(i);
    }
    delete seq;
    

}

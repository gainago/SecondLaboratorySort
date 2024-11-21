#include <fstream>

#include "Sequence.h"
#include "GenerateArraySequenceInt.h"
#include "MyString.h"


void WriteIntToFile(int const count)
{
    Sequence<int> *seq = GenerateArraySequenceInt(count);

    std::ofstream ofs;
    MyString strFile("../DataToTests/GeneratedInt");   //make name to file
    strFile = strFile + MyString::IntToMyString(count);

    char* nameFile = strFile.Seize();
    ofs.open(nameFile);
    delete nameFile;

    if(!ofs.is_open()){
        throw "can not open file";
    }
    for(int i = 0; i < count; i++)
    {
        ofs << seq->Get(i) << "\n";
    }
    

}

//Exercise 12.20
//Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr to point to ench element in that StrBlob

#include <fstream>
#include <iostream>
#include "ch12_StrBlob.h"

int main() {

    std::ifstream ifs("ex11_33_inputFile.txt");
    StrBlob blob;

    for(std::string str; std::getline(ifs, str); ) 
        blob.push_back(str);

    for(StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
}

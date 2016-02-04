#include "ch12_StrBlob.h"
#include <iostream>

int main() {
    
    const StrBlob csb{ "aaa", "bbb", "ccc", "const" };
    StrBlob sb{ "aaa", "no const" };
    
    std::cout << csb.front() << " " << csb.back() << std::endl;
    std::cout << sb.front() << " " << sb.back() << std::endl;
    sb.back() = "change back";
    std::cout << sb.front() << " " << sb.back() << std::endl;

}

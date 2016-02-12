//Exercise 9.14:
//Write a program to assign the elements from a list of char* pointers to 
//C-style character strings

#include <iostream>
#include <list>
#include <vector>
#include <string>

int main() {
    
    std::list<const char*> list1{"AAA", "BBB", "CCC"};
    std::vector<std::string> v;
    v.assign(list1.cbegin(), list1.cend());
    for(auto &c : v) {
        std::cout << c << std::endl;
    }
}

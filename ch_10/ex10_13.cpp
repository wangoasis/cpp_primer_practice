//Exercise 10.13:
//The library defines an algorithm named partition.
//Write a function that takes a string and returns a bool indicating whether the string has more than four characters.
//Use that function to partition a vector of string and pick strings that has more than 4 characters.

#include <iostream>
#include <string>
#include <algorithm>
using std::string;

bool longerThanFour(const string& s) {
    return s.size() > 4;
}

int main() {
    std::vector<string> vec{"the","quick","red","fox","jumps","over","the","slow", "red","tuttle"};
    auto par_end = partition(vec.begin(), vec.end(), longerThanFour);
    for(auto iter = vec.cbegin(); iter != par_end; iter++) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

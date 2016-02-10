//Exercise 14.43
//Using library function objects, determine whether a given int value is divisible by any element in a container of int S

#include <vector>
using std::vector;
#include <functional>
using namespace std::placeholders;
#include <iostream>
#include <algorithm>

bool isDivided(const int& n1, const int &n2) {
    
    return (n2%n1==0);   
}
int main() {
    
    vector<int> vec1{2, 3, 5, 7};  

    while(true) {
        int input;
        std::cout << "Enter a number to test or 0 to quit ";
        std::cin >> input;
        if(input) {
            bool divided = std::all_of(vec1.cbegin(), vec1.cend(), std::bind(isDivided, _1, input));
            std::cout << (divided? "Yes" : "No") << std::endl;
        } else 
            break;
    }
}

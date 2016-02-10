//Exercise 14.42
//Use library function objects and adaptors, define an expression to 
//1. count the number of values that are greater than 1024
//2. Find the first string that is not equal to "pooh"
//3. Multiply all values by 2

#include <iostream>
using std::cout; using std::endl;

#include <algorithm>
using std::count_if;
#include <functional>

using namespace std::placeholders;

#include <vector>
#include <string>
using std::vector; using std::string;

bool biggerThan(const int &num1, const int &num2) {

    return (num1 > num2);
}

bool NotEqualTo(const string &s1, const string &s2 ) {
    
    return (s1 != s2);
}

int& MultiplyByTwo(int &n) {

    n *= 2;
    return n;
}

int main() {

    vector<int> vec1{123, 125, 1025, 1024, 2048};
    vector<string> vec2{ "pooh", "pooh", "aaaa", "pooh", "bbbb" };

    // using functions declared in functional files
    int count1 = count_if(vec1.cbegin(), vec1.cend(), std::bind(std::greater<int>(),_1,1024));
    cout << count1 << endl;

    auto count2 = find_if(vec2.cbegin(), vec2.cend(), std::bind(std::not_equal_to<string>(),_1,"pooh"));
    cout << *count2 << endl;

    std::transform(vec1.begin(), vec1.end(), vec1.begin(), std::bind(std::multiplies<int>(),_1,2));
    for(auto &m : vec1)
        cout << m << " ";
    cout << endl;

    // using self-defined function
    int count4 = count_if(vec1.cbegin(), vec1.cend(), std::bind(biggerThan,_1,1024));
    cout << count4 << endl;

    auto count5 = find_if(vec2.cbegin(), vec2.cend(), std::bind(NotEqualTo,_1,"pooh"));
    cout << *count5 << endl;

    std::transform(vec1.begin(), vec1.end(), vec1.begin(), std::bind(MultiplyByTwo,_1));
    for(auto &m : vec1)
        cout << m << " ";
    cout << endl;
}

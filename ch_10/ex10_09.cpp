//Exercise 10.09:
//Implement your own version of elimDups.
//elimDups: delete repeated string in a vector

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using std::vector; using std::string;
using namespace std::placeholders;

bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    // remove repeated string
    words.erase(unique_end, words.end());
}

int main() {
    vector<string> vec{"the","quick","red","fox","jumps","over","the","slow", "red","tuttle"};

    for(auto &s :vec) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    elimDups(vec);

    // pass a method pointer
//  stable_sort(vec.begin(), vec.end(), isShorter);

    // pass a lambda method
    stable_sort(vec.begin(), vec.end(), std::bind(isShorter, _1, _2));
    for(auto &s :vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    // changing the placeholders in bind function will create the result of sorting in reverse order
    stable_sort(vec.begin(), vec.end(), std::bind(isShorter, _2, _1));
    for(auto &s :vec) {
        std::cout << s << " ";
    }

    std::cout << std::endl;
}

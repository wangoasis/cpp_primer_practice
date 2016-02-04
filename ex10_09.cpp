//Exercise 10.09:
//Implement your own version of elimDups.
//elimDups: delete repeated string in a vector

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using std::vector; using std::string;

bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

int main() {
    vector<string> vec{"the","quick","red","fox","jumps","over","the","slow", "red","tuttle"};

    for(auto &s :vec) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    for(auto &s :vec) {
        std::cout << s << " ";
    }
}

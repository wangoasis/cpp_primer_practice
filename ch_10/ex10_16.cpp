//Exercise 10.16, 10.20

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using std::vector; using std::string;

void elimDups(vector<string> &words) {
     sort(words.begin(), words.end());
     auto unique_end = unique(words.begin(), words.end());
     words.erase(unique_end, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);

    stable_sort(words.begin(), words.end(), 
    [](const string &s1, const string &s2){ return s1.size() < s2.size(); });
    
    auto iter_wc = find_if(words.begin(), words.end(),
    [sz](const string &s){ return s.size() >= sz; });

    for_each(iter_wc, words.end(), [](const string &s){ std::cout << s << " "; });

    std::cout << std::endl;
}

int countLongerThan(vector<string> &words, vector<string>::size_type sz) {
    
    return count_if(words.begin(), words.end(), [sz](const string &s){ return s.size() >= sz; });
}

int main() {
    vector<string> vec{"the","quick","red","fox","jumps","over","the","slow", "red","tuttle"};
//    biggies(vec,4);
    std::cout << countLongerThan(vec, 4) << std::endl;
}

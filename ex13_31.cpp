#include "ch13_HasPtrValueLike.h"
#include <vector>
#include <algorithm>
using std::vector;

int main () {
    
    HasPtr s("s"), a("a"), b("b");
    vector<HasPtr> vec{s, a, b};
    sort(vec.begin(), vec.end());

    for(auto const& elem : vec)
        elem.show();
    std::cout << std::endl;
}

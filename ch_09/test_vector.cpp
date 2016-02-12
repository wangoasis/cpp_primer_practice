// this file is written to differentiate capacity and size of a vector

#include <vector>
#include <iostream>

using std::cout; using std::vector;

int main() {
    
    vector<int> ivec;
    cout << "ivec size: " << ivec.size() 
         << " ivec capacity: " << ivec.capacity() << std::endl;
         
    for(vector<int>::size_type ix = 0; ix != 24; ix++) {
        ivec.push_back(ix);  
    }
    cout << "ivec size: " << ivec.size() 
         << " ivec capacity: " << ivec.capacity() << std::endl;
}

#include "ch13_Message.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout; using std::endl;

int main() {
    
    Message msg1{"mag1"}, msg2{"msg2"}, msg3{"msg3"};

    Message msg4(msg1);
    const Message msg5 = msg1;

    cout << msg5 << endl;
    
    Folder fol1, fol2, fol3;

    msg1.save(fol3);
    msg2.save(fol2);
    msg3.save(fol3);

//    cout << fol3 << endl;

    Folder fol4(fol2);
    Folder fol5 = fol3;

//    cout << fol4 << endl;
//    cout << fol5 << endl;
}

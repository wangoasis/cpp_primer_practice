#include <fstream>
#include <iostream>
#include "ch12_TextQuery.h"

void runQueries(std::ifstream& ifs) {
    TextQuery tq(ifs);

    while(true) {
        
        std::cout << "enter a word to search or enter q to quit: " << std::endl;

        string s;
        if(!(std::cin >> s) || s == "q")
            break;
        print(std::cout, tq.query(s))  << std::endl;
    }
}

int main () {
    std::ifstream ifs("./example.txt");
    runQueries(ifs);
}

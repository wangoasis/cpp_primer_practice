#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>

int main () {
    
    std::ifstream file("./example.txt");
    TextQuery text(file);
    Query q = Query("it") & Query("the") | Query("to");
    std::cout << q.eval(text);
    return 0;
}

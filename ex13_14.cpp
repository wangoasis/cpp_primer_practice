#include <iostream>

class Numbered {
    
    public:
    Numbered() {
       mysn = unique++;
    }

//    for exercise 13.15
//    Numbered(const Numbered &nb) {
//        mysn = unique++;
//    }

    int mysn;
    static int unique ;
};

int Numbered::unique = 10;

void f(Numbered s)  {
//void f(Numbered& s) { // for exercise 13.16
    std::cout << s.mysn << std::endl;
}

int main() {
    
    Numbered a, b = a, c = b;
    f(a); f(b); f(c);
}

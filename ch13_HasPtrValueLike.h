//Exercise 13.30
//Write and test a swap function for your valuelike version of HasPtr,
//Give your swap a print statement that notes when it's executed

//Exercise 13.31
//Give your class a operator <

#ifndef CH13_HASPTR
#define CH13_HASPTR

#include <string>
using std::string;
#include <iostream>

class HasPtr {
    
    public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);

    HasPtr(const string &s=string())
    : ps(new string(s)), 
      i(0) 
      {}
    
    HasPtr(const HasPtr& hp)
    : ps(new string(*hp.ps)),
      i(hp.i)
      {}

//    HasPtr& operator = (const HasPtr& hp) {
//        
//        auto new_ps = new string(*hp.ps);
//        delete ps;
//        ps = new_ps;
//        i = hp.i;
//        return *this;
//    }

    // another version of operator = using swap function
    HasPtr& operator = (HasPtr rhs) {
        
        swap(*this, rhs);
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

    void show() const {
        std::cout << *ps << std::endl;
    }

    private:
    string *ps;
    int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    
    std::swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
    std::cout << "swap has been called" << std::endl;
}

bool operator < (const HasPtr& lhs, const HasPtr& rhs) {
    return *lhs.ps < *rhs.ps;
}
#endif

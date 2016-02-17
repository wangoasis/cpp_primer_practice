#ifndef CH12_StrBlob_H
#define CH12_StrBlob_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <exception>
using std::vector; using std::string; using std::make_shared; using std::initializer_list;

// class declaration
class StrBlobPtr;

class StrBlob {
    
    friend class StrBlobPtr;

    public:
    typedef vector<string>::size_type size_type;

    // construction function
    StrBlob() : data( make_shared<vector<string>>() ) {}
    StrBlob(initializer_list<string> il) : data( make_shared<vector<string>>(il) ) {}
    
    // test whether the vector is empty
    bool empty() const { return data->empty(); }

    // the size of vector
    size_type size() const { return data->size();}

    // add an element to vector
    void push_back(const string &s) {
        data->push_back(s);
    }

    // delete an element in vector
    void pop_back() {
        check(0, "pop back on empty StrBlob");
        data->pop_back();
    }

    // get the value of the vector 
    string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    const string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    // a safe pointer class
    StrBlobPtr begin();

    StrBlobPtr end();

    private:
    // a shared_ptr to a vector
    std::shared_ptr<vector<string>> data;

    // test whether size_type i is out of range
    void check(size_type i, const string &msg) const {
        if(i >= data->size())
            throw std::out_of_range(msg);    
    }
};

class StrBlobPtr {
    
    public:
    // construction method
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    // operator *
    string& deref() const {
        auto p = check(curr, "deference past end");
        return (*p)[curr];    
    }

    // operator ++
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;    
    }

    // operator !=
    bool operator != (const StrBlobPtr &rhs) {
        return curr != rhs.curr;
    }

    private:
    // a weak_ptr correponds to the shared_ptr in class StrBlob
    std::weak_ptr<vector<string>> wptr;
    // the index in vector
    std::size_t curr;

    std::shared_ptr<vector<string>> check(std::size_t i, const string& msg) const {

        auto ret = wptr.lock();
        if(!ret) 
            throw std::runtime_error("Unbound StrBlobPtr");
        
        if(i >= ret->size()) 
            throw std::out_of_range(msg);

        return ret;
    }
};

#endif

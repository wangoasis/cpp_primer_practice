#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
    
    public:
    Quote() = default;

    Quote(const std::string &s, double p) :
    bookNo(s), price(p) {}

    std::string isbn() const {
        return bookNo;
    }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual void debug() const {
        std::cout << "bookNo=" << bookNo << " price=" << price << " ";
    }

    virtual ~Quote() = default;

    private:
    std::string bookNo;

    protected:
    double price = 0.0;
};

#endif

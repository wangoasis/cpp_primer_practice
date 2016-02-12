#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "ex15_15_Disc_Quote.h"

class Bulk_quote : public Disc_quote {
    
    public:
    Bulk_quote() = default;

    Bulk_quote(const std::string &s, double p, std::size_t q, double disc) :
    Disc_quote(s, p, q, disc) {}

    double net_price(std::size_t n) const override {
        return n * price * (n >= quantity ? (1-discount) : 1);
    }

    void debug() const override {
        Quote::debug();
        std::cout << "min_qty=" << quantity << " discount=" << discount << " ";
    }
};

#endif

#include <iostream>
#include <string>

#include "ex15_15_Quote.h"
#include "ex15_15_Disc_Quote.h"
#include "ex15_15_Bulk_Quote.h"

int main () {

    Quote quote("quote", 53.00);
    quote.debug();
    std::cout << std::endl;

    Bulk_quote bulk_quote("bulk_quote", 100.00, 10, 0.7);
    std::cout << bulk_quote.net_price(20) << std::endl;
    bulk_quote.debug();
    std::cout << std::endl;
}


#include "Query.h"
#include <algorithm>

QueryResult OrQuery::eval(const TextQuery &t) const {
    
    auto left = lhs.eval(t);
    auto right = rhs.eval(t);

    auto ret_lines = std::make_shared<set<line_no>>(left.begin(), left.end());

    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &t) const {
    
    auto left = lhs.eval(t);
    auto right = rhs.eval(t);

    auto ret_lines = std::make_shared<set<line_no>>();

    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->end()));

    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& t) const {

    auto result = query.eval(t);
    // an empty set to store results
    auto ret_lines = std::make_shared<set<line_no>>();
    // get the iterator 
    auto beg = result.begin(), end = result.end();

    auto sz = result.get_file()->size();
    for(size_t n = 0; n != sz; ++n) {
        
        if(*beg != n || beg == end) 
            ret_lines->insert(n);
        else if(beg != end)
            ++beg;
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}

#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"

class QueryBase {

    friend class Query;

    protected:
    using line_no = TextQuery::line_no;

    // virtual destruction method
    virtual ~QueryBase() =default;

    private:
    // returns the QueryResult that matches the Query
    virtual QueryResult eval(const TextQuery&) const =0;

    // rep is a string representing the query
    virtual std::string rep() const =0;
};

class WordQuery : public QueryBase {
    
    friend class Query;

    WordQuery(const std::string &s) :
    queryWord(s) {
        
        std::cout << "WordQuery's constructor" << std::endl;    
    }

    QueryResult eval(const TextQuery &t) const {
        
        return t.query(queryWord);
    }

    std::string rep() const override {
        
        return queryWord;
    }

    std::string queryWord;
};

class Query {

    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);

    public:
    Query(const std::string &s) :
    q(new WordQuery(s)) {
        
        std::cout << "Query's constructor" << std::endl;    
    };

    QueryResult eval(const TextQuery &t) const {
        
        return q->eval(t);
    }

    std::string rep() const {
        
        return q->rep();
    }

    private:
    // a pointer to Query objects
    std::shared_ptr<QueryBase> q;
    // construction method
    Query(std::shared_ptr<QueryBase> query) :
    q(query) {}
};

inline std::ostream& operator<< (std::ostream& os, const Query &query) {
    
    return os << query.rep();
}


class NotQuery : public QueryBase {
    
    friend Query operator~ (const Query &operand) {
        
        return std::shared_ptr<QueryBase>(new NotQuery(operand));
    }

    NotQuery(const Query &q) :
    query(q) {}
    
    std::string rep() const {
        
        return "~(" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery&) const override;

    Query query;
};

class BinaryQuery : public QueryBase {

    protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) :
    lhs(l), rhs(r), opSym(s) {
        
        std::cout << "BinaryQuery's constructor" << std::endl;    
    }

    std::string rep() const {
        
        return "("+lhs.rep()+opSym+rhs.rep()+")";
    }

    Query lhs, rhs;
    // name of operator, & or |
    std::string opSym;

};

class AndQuery : public BinaryQuery {
    
    friend Query operator&(const Query&, const Query&);

    AndQuery(const Query &l, const Query &r):
    BinaryQuery(l, r, "&") {
        
        std::cout << "AndQuery's constructor" << std::endl;    
    }

    QueryResult eval(const TextQuery&) const override;
    
};

inline Query operator&(const Query &lhs, const Query &rhs) {

    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
    
    friend Query operator|(const Query&, const Query&);

    OrQuery(const Query &l, const Query &r):
    BinaryQuery(l, r, "|") {
        std::cout << "OrQuery's constructor" << std::endl;    
        
    }

    QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs) {

    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}
#endif

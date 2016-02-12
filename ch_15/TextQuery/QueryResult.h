#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include "TextQuery.h"
#include <iostream>

class QueryResult {
    
    friend std::ostream& operator<< (std::ostream&, const QueryResult&);

    public:
    // construction function
    QueryResult(string, shared_ptr<set<TextQuery::TextQuery::line_no>>, shared_ptr<vector<string>>);

    set<TextQuery::line_no>::iterator begin() {
        
        return lines->begin();
    }
    
    set<TextQuery::line_no>::iterator end() {
        
        return lines->end();
    }

    const shared_ptr<vector<string>> get_file() const {
        return file;
    }

    private:
    // a word to search
    string sought;
    // a set of lines containing sought
    shared_ptr<set<TextQuery::line_no>> lines;
    // input file
    shared_ptr<vector<string>> file;
};

#endif

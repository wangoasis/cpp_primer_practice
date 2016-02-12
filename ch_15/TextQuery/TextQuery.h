#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

#include <map>
using std::map;

#include <set>
using std::set;

class QueryResult;

class TextQuery {
    public:
    using line_no = vector<string>::size_type;   
    
    // construction function
    TextQuery(std::ifstream&);

    // type a string to search and returns a QueryResult class
    QueryResult query(const string&) const;

    private:
    // a pointer to the content of input file
    shared_ptr<vector<string>> file;

    // first: word
    // second: a pointer to a set, which contains the line number containing the word
    map<string, shared_ptr<set<line_no>>> wm;
};

#endif

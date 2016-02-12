#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
#include <iostream>
#include <fstream>
using std::istringstream;

class QueryResult;

TextQuery::TextQuery(std::ifstream& infile)
: file(new vector<string>)  {
    string text;

    // process every line
    while(getline(infile, text)) {
        // save a line to vector
        file->push_back(text);
        int n = file->size() - 1;

        // process every word in a line
        istringstream line(text);
        string word;

        while(line >> word) {
            
            // add to the map wm
            // if word doesn's exist in wm, wm will create a new pair. Therefore, we use [] instead of insert
            auto& lines = wm[word];
            if(!lines) 
                lines.reset(new set<line_no>);
            // add the line number to the set of a word
            lines->insert(n);
        }
    }
}


QueryResult TextQuery::query(const string &s) const {
    
    static shared_ptr<set<TextQuery::line_no>> nodata(new set<TextQuery::line_no>);

    auto loc = wm.find(s);
    if(loc == wm.end())
        return QueryResult(s, nodata, file);
    else
        return QueryResult(s, loc->second, file);
}   


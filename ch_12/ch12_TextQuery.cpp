#include "ch12_TextQuery.h"
#include <sstream>
#include <iostream>
#include <fstream>
using std::istringstream;

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

QueryResult::QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> v) 
: sought(s) ,
  lines(p)  ,
  file(v)   {

}

QueryResult TextQuery::query(const string &s) const {
    
    static shared_ptr<set<TextQuery::line_no>> nodata(new set<TextQuery::line_no>);

    auto loc = wm.find(s);
    if(loc == wm.end())
        return QueryResult(s, nodata, file);
    else
        return QueryResult(s, loc->second, file);
}   

std::ostream& print(std::ostream& os, const QueryResult &qr) {
    
    os << qr.sought  << " occurs " << qr.lines->size() << " times " << std::endl;
    for(auto num : *(qr.lines))
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin()+num) << std::endl;
    return os;
}

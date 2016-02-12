#include "QueryResult.h"

QueryResult::QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> v) 
: sought(s) ,
  lines(p)  ,
  file(v)   {

}

std::ostream& operator<<(std::ostream& os, const QueryResult &qr) {
    
    os << qr.sought  << " occurs " << qr.lines->size() << " times " << std::endl;
    for(auto num : *(qr.lines))
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin()+num) << std::endl;
    return os;
}

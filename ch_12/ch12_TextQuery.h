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

class QueryResult {
    
    friend std::ostream& print(std::ostream&, const QueryResult&);

    public:
    // construction function
    QueryResult(string, shared_ptr<set<TextQuery::TextQuery::line_no>>, shared_ptr<vector<string>>);

    private:
    // a word to search
    string sought;
    // a set of lines containing sought
    shared_ptr<set<TextQuery::line_no>> lines;
    // input file
    shared_ptr<vector<string>> file;
};

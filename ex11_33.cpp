//Exercise 11.33
//Implement your own version of the word-transformation program

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using std::string; using std::cout; using std::map; using std::ifstream;
using std::istringstream;

//build a transformation map based on file
map<string, string> buildMap(ifstream&);
//transform a word based on a map
const string& wordTransform(const string&, const map<string, string>&);

void fileTransform(ifstream &inputFile, ifstream &mapFile) {
    map<string, string> transMap = buildMap(mapFile);   
    string text;
    while(getline(inputFile, text)) {
        istringstream line(text);
        string word;
        bool beginLine = true;
        while(line >> word) {
            if(beginLine)
                beginLine = false;
            else
                cout << " ";
            cout << wordTransform(word, transMap);
        }
        cout << std::endl;
    }
}

map<string, string> buildMap(ifstream &mapFile) {
    map<string, string> transMap;
    string text;
    string key;
    string value;
    string::size_type space_index;

    while(getline(mapFile, text)) {
        string::size_type length = text.size();
        space_index = text.find(" ");
        key = text.substr(0, space_index);
        value = text.substr(space_index+1, length-1);
        transMap[key] = value;        
    }

    return transMap;
}

const string& wordTransform(const string &s, const map<string, string> &transMap) {
    auto map_it = transMap.find(s);
    if(map_it != transMap.cend()) 
        return map_it->second;
    else
        return s;
}

int main() {
    
    ifstream inputFile("./ex11_33_inputFile.txt");
    ifstream mapFile("./ex11_33_mapFile.txt");
    fileTransform(inputFile, mapFile);
}

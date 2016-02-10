#ifndef CH13_MESSAGE
#define CH13_MESSAGE

#include <string>
using std::string;

#include <set>
using std::set;

#include <iostream>
using std::ostream; using std::cout; using std::endl;

class Folder; // forward declaration

class Message {
    
    friend class Folder;
    friend ostream& operator<<(ostream&, const Message&);

    public:
    explicit Message(const string& s="")
    : contents(s) {}

    Message(const Message&);

    Message& operator=(const Message&);

    ~Message();

    // save to a folder
    void save(Folder&);

    // remove from a folder
    void remove(Folder&);

    private:
    // contents of message
    string contents;

    // Folders containing this message
    set<Folder*> folders;

    // add to another message's folder
    void addToFolders(const Message&);

    // remove from current folders
    void removeFromFolders();

    // add a folder that saves this message
    void addFolder(Folder*);

    // remove from a folder
    void remFolder(Folder*);
};

class Folder {

    friend ostream& operator<<(ostream&, const Folder&);

    public:
    Folder() = default;

    Folder(const Folder&);

    Folder& operator=(const Folder&);

    ~Folder();

    // add a message
    void addMsg(Message*);

    // remove a message
    void remMsg(Message*);

    private:
    // all Messages this Folder saves
    set<Message*> messages;

    // add to message 
    void addToMessage(const Folder&);

    // remove from message
    void remFromMessage();
};

#endif

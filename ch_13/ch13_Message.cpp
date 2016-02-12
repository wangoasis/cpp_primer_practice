#include "ch13_Message.h"

void Message::save(Folder& f) {
    
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f) {
    
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addToFolders(const Message &m) {
    
    for(auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message& m) :
contents(m.contents),
folders(m.folders) {

    addToFolders(m);
}

void Message::removeFromFolders() {
    
    for(auto f : folders)
        f->remMsg(this);
}

Message::~Message() {
    removeFromFolders();
}

Message& Message::operator=(const Message &rhs) {
    
    removeFromFolders();
    contents = rhs.contents;
    folders = rhs.folders;
    addToFolders(rhs);
    return *this;
}

void Message::addFolder(Folder* f) {
    
    folders.insert(f);
}

void Message::remFolder(Folder* f) {
    
    folders.erase(f);
}
    
ostream& operator<<(ostream& os, const Message& msg) {
    os << msg.contents;
    return os;
}

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

void Folder::addToMessage(const Folder &f) {
    
    for(auto m : f.messages)
        m->addFolder(this);
}

void Folder::remFromMessage() {
    
    for(auto m : messages) 
        m->remFolder(this);
}

Folder::Folder(const Folder &f) :
messages(f.messages) {

    addToMessage(f);
}

Folder::~Folder() {
    remFromMessage();
}

Folder& Folder::operator=(const Folder &rhs) {
    remFromMessage();
    messages = rhs.messages;
    addToMessage(rhs);
    return *this;
}

ostream& operator<<(ostream &os, const Folder &f) {
    
    for(auto m : f.messages)
        cout << *m << endl;

    return os;
}

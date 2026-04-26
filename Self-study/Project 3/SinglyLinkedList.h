#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>
#include <optional>
#include <iostream>

using namespace std;

class SinglyLinkedNode {
public:
    string            data;
    SinglyLinkedNode* next;
    SinglyLinkedNode(const string& nodeData);
};

class SinglyLinkedList {
public:
    SinglyLinkedList();
    void append(string item);
    void prepend(string item);
    SinglyLinkedNode* search(const string& item) const;
    bool insertAfter(const string& currentItem, const string& newItem);
    SinglyLinkedNode* nodeAt(size_t index) const;
    optional<string>  at(size_t index)     const;
    void set(size_t index, const string& item);
    bool remove(const string& itemToRemove);
    void print() const;

private:
    SinglyLinkedNode* head;
    SinglyLinkedNode* tail;
    void appendNode(SinglyLinkedNode* newNode);
    void prependNode(SinglyLinkedNode* newNode);
    void insertNodeAfter(SinglyLinkedNode* currentNode, SinglyLinkedNode* newNode);
    void removeNodeAfter(SinglyLinkedNode* currentNode);
};

#endif

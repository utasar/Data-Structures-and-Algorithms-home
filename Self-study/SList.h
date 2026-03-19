//
// Created by achar on 3/18/2026.

#ifndef HOMEWORK_1_SLIST_H
#define HOMEWORK_1_SLIST_H

#include <iostream>
#include "LNode.h"
using namespace std;

// SList Template Class Declaration
template <class Elem>
class SList {
private:
    LNode<Elem>* head;
public:
    SList() { head = nullptr; }
    ~SList() { clear(); }
    bool insertfront(const Elem& i);
    bool insertend(const Elem& i);
    bool getfirst(Elem& val);
    bool getlast(Elem& val);
    void clear();
    void printList() const;
};

// Method Implementations
template <class Elem>
bool SList<Elem>::insertfront(const Elem& i) {
    LNode<Elem>* newnode = new LNode<Elem>(i);
    newnode->next = head;
    head = newnode;
    return true;
}

template <class Elem>
bool SList<Elem>::insertend(const Elem& i) {
    LNode<Elem>* newnode = new LNode<Elem>(i);
    if (head == nullptr) {
        head = newnode;
        return true;
    }
    LNode<Elem>* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newnode;
    return true;
}

template <class Elem>
bool SList<Elem>::getfirst(Elem& val) {
    if (head == nullptr) return false;
    LNode<Elem>* oldhead = head;
    val = head->data;
    head = head->next;
    delete oldhead;
    return true;
}

template <class Elem>
bool SList<Elem>::getlast(Elem& val) {
    if (head == nullptr) return false;
    if (head->next == nullptr) {
        val = head->data;
        delete head;
        head = nullptr;
        return true;
    }
    LNode<Elem>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    val = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    return true;
}

template <class Elem>
void SList<Elem>::clear() {
    while (head != nullptr) {
        LNode<Elem>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class Elem>
void SList<Elem>::printList() const {
    LNode<Elem>* current = head;
    bool first = true;
    while (current != nullptr) {
        if (!first) cout << ", ";
        cout << current->data;
        first = false;
        current = current->next;
    }
    cout << endl;
}

#endif //HOMEWORK_1_SLIST_H
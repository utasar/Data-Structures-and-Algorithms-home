//
// Created by achar on 3/18/2026.
//

#ifndef HOMEWORK_1_LNODE_H
#define HOMEWORK_1_LNODE_H

template <class Elem>
class LNode {
public:
    Elem data;
    LNode* next;
    LNode(const Elem& newvalue) {
        data = newvalue;
        next = nullptr;
    }
};


#endif //HOMEWORK_1_LNODE_H
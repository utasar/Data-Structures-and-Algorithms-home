#include "SinglyLinkedList.h"


// SinglyLinkedNode  (Slide 10)


SinglyLinkedNode::SinglyLinkedNode(const string& nodeData) {
    data = nodeData;
    next = nullptr;
}


// SinglyLinkedList – Constructor  (Slide 9)


SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
}


// append / appendNode  (Slides 11–12)
//
//  Public  append(item)    – creates a new node then delegates to appendNode
//  Private appendNode(node) – handles the pointer logic:
//    • Empty list  → head = tail = newNode
//    • Non-empty   → tail->next = newNode; tail = newNode


void SinglyLinkedList::append(string item) {
    SinglyLinkedNode* newNode = new SinglyLinkedNode(item);
    appendNode(newNode);
}

void SinglyLinkedList::appendNode(SinglyLinkedNode* newNode) {
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail       = newNode;
    }
}


// prepend / prependNode  (Slides 14–15)
//
//  Public  prepend(item)     – creates a new node then delegates
//  Private prependNode(node) – handles the pointer logic:
//    • Empty list  → head = tail = newNode
//    • Non-empty   → newNode->next = head; head = newNode

void SinglyLinkedList::prepend(string item) {
    SinglyLinkedNode* newNode = new SinglyLinkedNode(item);
    prependNode(newNode);
}

void SinglyLinkedList::prependNode(SinglyLinkedNode* newNode) {
    if (head == nullptr) {   // could also call empty()
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head          = newNode;
    }
}


// search  (Slides 16–17)
//
//  Traverses list from head.
//  Returns a pointer to the first node whose data matches item,
//  or nullptr if the item is not found.


SinglyLinkedNode* SinglyLinkedList::search(const string& item) const {
    SinglyLinkedNode* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


// insertNodeAfter  (Slides 18–19)
//
//  Inserts newNode immediately after currentNode.
//  Three cases:
//    1. Empty list (head == nullptr)          → head = tail = newNode
//    2. Insert after tail (next == nullptr)   → extend tail
//    3. Insert in the middle                  → rewire next pointers


void SinglyLinkedList::insertNodeAfter(SinglyLinkedNode* currentNode,
                                       SinglyLinkedNode* newNode) {
    if (head == nullptr) {
        // Case 1: empty list
        head = newNode;
        tail = newNode;
    } else if (currentNode->next == nullptr) {
        // Case 2: inserting after the tail
        tail->next = newNode;
        tail       = newNode;
    } else {
        // Case 3: inserting in the middle
        newNode->next     = currentNode->next;
        currentNode->next = newNode;
    }
}


// insertAfter  (Slides 20–21)
//
//  Public interface: accepts item strings rather than raw node pointers.
//  1. Searches for currentItem.
//  2. If found, creates newNode and calls insertNodeAfter.
//  Returns true on success, false if currentItem was not found.


bool SinglyLinkedList::insertAfter(const string& currentItem,
                                   const string& newItem) {
    SinglyLinkedNode* currentNode = search(currentItem);
    if (currentNode != nullptr) {
        SinglyLinkedNode* newNode = new SinglyLinkedNode(newItem);
        insertNodeAfter(currentNode, newNode);
        return true;
    }
    return false;
}


// nodeAt  (Slides 22–23)
//
//  Returns a pointer to the node at the given index.
//  Returns nullptr if the index is out of bounds.
//  Marked const – does not modify the list.
//  size_t is unsigned; no need to check for negative indices.


SinglyLinkedNode* SinglyLinkedList::nodeAt(size_t index) const {
    SinglyLinkedNode* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
        if (current == nullptr) {
            return nullptr;   // index exceeds list length
        }
    }
    return current;
}


// at  (Slides 24–25)
//
//  Returns optional<string>:
//    • The data at the given index if the index is valid.
//    • nullopt if the index is out of bounds.


optional<string> SinglyLinkedList::at(size_t index) const {
    SinglyLinkedNode* result = nodeAt(index);
    if (result != nullptr) {
        return result->data;
    }
    return nullopt;
}


// set  (Slide 26)
//
//  Modifies the data field of the node at the given index.
//  Silently does nothing if the index is out of bounds.


void SinglyLinkedList::set(size_t index, const string& item) {
    SinglyLinkedNode* toUpdate = nodeAt(index);
    if (toUpdate != nullptr) {
        toUpdate->data = item;
    }
}


// removeNodeAfter  (Slides 27–28)
//
//  Removes the node that comes after currentNode.
//  Special case: if currentNode == nullptr, the head is removed.
//
//  After deletion:
//    • If the list is now empty → tail = nullptr
//    • If the tail was removed  → tail = currentNode
//
//  Always calls delete to release heap memory.


void SinglyLinkedList::removeNodeAfter(SinglyLinkedNode* currentNode) {
    if (currentNode == nullptr) {
        // Special case: remove the head
        SinglyLinkedNode* nodeToRemove = head;
        head = head->next;
        delete nodeToRemove;   // release the memory pointed to by nodeToRemove

        if (head == nullptr) {
            tail = nullptr;    // last item was removed
        }
    } else if (currentNode->next != nullptr) {
        SinglyLinkedNode* nodeToRemove   = currentNode->next;
        SinglyLinkedNode* succeedingNode = nodeToRemove->next;
        currentNode->next = succeedingNode;
        delete nodeToRemove;   // release the memory pointed to by nodeToRemove

        if (succeedingNode == nullptr) {
            tail = currentNode; // tail was removed; update tail pointer
        }
    }
}

// remove  (Slides 29–30)
//
//  Public interface: accepts the item string to remove.
//  Traverses the list, tracking both current and previous nodes.
//  When found, calls removeNodeAfter(previous).
//  Returns true on success, false if item is not in the list.


bool SinglyLinkedList::remove(const string& itemToRemove) {
    // Traverse to the node whose data equals itemToRemove;
    // keep track of the previous node
    SinglyLinkedNode* previous = nullptr;
    SinglyLinkedNode* current  = head;

    while (current != nullptr) {
        if (current->data == itemToRemove) {
            removeNodeAfter(previous);
            return true;
        }
        // Advance to the next node
        previous = current;
        current  = current->next;
    }
    // Traversed entire list — element not found
    return false;
}


// print  (Slides 31–32)
//
//  Traverses the list from head to tail and prints every element.
//  Output format: {first, second, third}


void SinglyLinkedList::print() const {
    SinglyLinkedNode* current = head;
    cout << "{";
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}
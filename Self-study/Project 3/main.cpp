#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    SinglyLinkedList list;
    int choice;

    do {
        cout << "Choose a valid option: " << endl;
        cout << endl;
        cout << "1. Append" << endl;
        cout << "2. Prepend" << endl;
        cout << "3. Insert At" << endl;
        cout << "4. Remove At" << endl;
        cout << "5. Search" << endl;
        cout << "6. Exit" << endl;
        cout << " Enter your choice:";
        cin >> choice;

        if (choice == 1) {
            string value;
            cout << "Enter a value to append:";
            cin >> value;
            list.append(value);
            list.print();

        } else if (choice == 2) {
            string value;
            cout << "Enter a value to prepend:";
            cin >> value;
            list.prepend(value);
            list.print();

        } else if (choice == 3) {
            string value;
            size_t index;
            cout << "Enter a value and index:";
            cin >> value >> index;
            if (index == 0) {
                list.prepend(value);
            } else {
                SinglyLinkedNode* prev = list.nodeAt(index - 1);
                if (prev != nullptr) {
                    list.insertAfter(prev->data, value);
                } else {
                    cout << "Index out of bounds." << endl;
                }
            }
            list.print();

        } else if (choice == 4) {
            size_t index;
            cout << "Enter an index to remove:";
            cin >> index;
            SinglyLinkedNode* node = list.nodeAt(index);
            if (node != nullptr) {
                list.remove(node->data);
                list.print();
            } else {
                cout << "Index out of bounds." << endl;
            }

        } else if (choice == 5) {
            string value;
            cout << "Enter a value to search:";
            cin >> value;
            SinglyLinkedNode* found = list.search(value);
            if (found != nullptr) {
                size_t idx = 0;
                optional<string> item = list.at(idx);
                while (item.has_value()) {
                    if (item.value() == value) {
                        cout << "Found at index: " << idx << endl;
                        break;
                    }
                    idx++;
                    item = list.at(idx);
                }
            } else {
                cout << "Value not found." << endl;
            }

        } else if (choice == 6) {
            // Exit

        } else {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
#include <iostream>
#include <string>
#include "SList.h"
using namespace std;

int main() {
    // Test 1: Integer List
    cout << "--- Testing Integer List ---" << endl;
    SList<int> intList;
    intList.insertfront(10);
    intList.insertfront(20);
    intList.insertend(30);
    cout << "Expected: 20, 10, 30" << endl;
    cout << "Actual:   ";
    intList.printList();
    int val;
    if (intList.getfirst(val)) {
        cout << "Removed first: " << val << endl;
    }
    cout << "List after removal: ";
    intList.printList();
    cout << endl;

    // Test 2: String List
    cout << "--- Testing String List ---" << endl;
    SList<string> strList;
    strList.insertfront("World");
    strList.insertfront("Hello");
    strList.insertend("!");
    cout << "Full phrase: ";
    strList.printList();
    string sVal;
    if (strList.getlast(sVal)) {
        cout << "Removed last: " << sVal << endl;
    }
    cout << "Final string list: ";
    strList.printList();
    return 0;
}
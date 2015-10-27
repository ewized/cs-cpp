/*
    Chapter 12.1
*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

void downsize(list<string>&);

int main() {
    list<string> list;
    string element;

    cout << "Enter a sentence then use CTRL+D to end: ";
    while (cin >> element) {
        list.push_back(element);
    }
    downsize(list);
    for (auto value : list) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}

/** This will remove every other element */
void downsize(list<string> &list) {
    auto copy(list);
    bool toggle = false;
    for (auto value : copy) {
        if (toggle) {
            list.remove(value);
        }
        toggle = !toggle;
    }
}

/*
    Chapter 12.4
*/
#include <iostream>
#include <list>

using namespace std;

list<char> merge(list<char> &, list<char> &);

int main() {
    list<char> a = {'A','B','C'};
    list<char> b = {'D','E','F','G','H'};
    for (auto value : merge(a, b)) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}

list<char> merge(list<char> &left, list<char> &right) {
    list<char> merged;
    while (left.size() > 0 || right.size() > 0) {
        if (left.size() > 0) {
            char value = *left.begin();
            left.pop_front();
            merged.push_back(value);
        }
        if (right.size() > 0) {
            char value = *right.begin();
            right.pop_front();
            merged.push_back(value);
        }
    }
    return merged;
}

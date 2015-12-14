/*
    Chapter 10.6
*/
#include <iostream>
#include <string>

using namespace std;

int index_of(string word, string str, int count = 0) {
    int length = str.size();
    if (word.size() < length) {
        return -1;
    }
    // compare return 0 for strings that are equal
    if (!word.substr(0, length).compare(str)) {
        return count;
    }
    return index_of(word.substr(1), str, count + 1);
}

int main() {
    cout << "Word: Mississippi!" << endl;
    cout << "index_of: sip " << index_of("Mississippi!", "sip") << endl;
    cout << "index_of: sips " << index_of("Mississippi!", "sips") << endl;
    return 0;
}

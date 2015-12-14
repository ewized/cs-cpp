/*
    Chapter 10.5
*/
#include <iostream>
#include <string>

using namespace std;

bool find(string word, string str) {
    int length = str.size();
    if (word.size() < length) {
        return false;
    }
    // compare return 0 for strings that are equal
    if (!word.substr(0, length).compare(str)) {
        return true;
    }
    return find(word.substr(1), str);
}

string pretty(bool value) {
    return value ? "true" : "false";
}

int main() {
    cout << "Word: Mississippi!" << endl;
    cout << "find: sip " << pretty(find("Mississippi!", "sip")) << endl;
    cout << "find: sips " << pretty(find("Mississippi!", "sips")) << endl;
    return 0;
}

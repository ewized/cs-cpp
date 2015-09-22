#include <iostream>
#include <string>

using namespace std;

/** Check is the string is the same forward as backwards */
bool is_reversed(string str) {
    // Single letters are the same forward and backwards
    if (str.length() <= 1) {
        return true;
    }
    // Check if the two letters the same
    else if (str.length() == 2) {
        return str[0] == str[1];
    }

    // Make a string shorter by taking the first and last letter off
    string shorter = str.substr(1, str.length() - 2);
    // return the shorter is reversed as well as the two letter taken off
    return str[0] == str[str.length() - 1] && is_reversed(shorter);
}

int main() {
    string str;

    cout << "Enter a word: ";
    cin >> str;

    cout << is_reversed(str) << endl;
    return main();
}

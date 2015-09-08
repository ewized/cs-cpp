/*
Exercise P9.1. Write a program that asks the user for a file name and displays the
number of characters, words, and lines in that file. Then have the program ask for
the name of the next file. When the user enters a file that doesn’t exist (such as the
empty string), the program should exit.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/** Print the stats of the file */
void print_stats(ifstream &file) {
    string line;
    int lines = 0, chars = 0, words = 0;

    while (getline(file, line)) {
        for (char ch : line) {
            if (ch == ' ') {
                words++;
            }

            chars++;
        }

        lines++;
        words++;
    }

    cout << "Lines: " << lines << " Chars: " << chars << " Words: " << words << endl;
}

int main() {

    string file_name;
    cout << "Enter file name: " << endl << "> ";
    getline(cin, file_name);

    ifstream file;
    file.open(file_name.c_str());

    print_stats(file);
    
    return 0;
}


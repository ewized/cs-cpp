/*
Exercise R9.1. Write C++ code to open a file with the name Hello.txt , store the mes-
sage “Hello, World!” in the file, and close the file. Then open the same file again and
read the message into a string variable. Close the file again.
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const string FILE_NAME = "Hello.txt";

int main() {
    ofstream out_file;
    out_file.open(FILE_NAME.c_str());

    out_file << "Hello, World!";
    out_file.close();

    ifstream input_file;
    input_file.open(FILE_NAME.c_str());

    string aa;
    string ab;
    input_file >> aa;
    input_file >> ab;

    input_file.close();

    cout << aa << " " << ab << endl;

    return 1;
}

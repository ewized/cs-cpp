#include <string>
#include <list>
#include <iostream>

using namespace std;

int menu() {
    int selection;
    cout << "0) Exit" << endl;
    cout << "1) Add Name" << endl;
    cout << "2) Remove Name" << endl;
    cout << "3) Print Names" << endl;
    cout << "> ";
    cin >> selection;
    return selection;
}

int main() {
    list<string> names;
    int in;
    do {
        in = menu();
        string name;
        // Add a name
        if (in == 1) {
            cout << "Enter a name to add to top: ";
            cin >> name;
            names.push_front(name);
        }
        // Remove a name
        else if (in == 2) {
            cout << "Enter name to be removed: ";
            cin >> name;
            for (auto it = names.begin(); it != names.end(); it++) {
                if (*it == name) {
                    names.erase(it);
                    cout << "Removed" << endl;
                    break;
                }
            }
        }
        // Print all the names
        else if (in == 3) {
            cout << "--- Names ---" << endl;
            for (auto it = names.begin(); it != names.end(); it++) {
                cout << &*it << " " << *it << endl;
            }
            cout << "---- end ----" << endl;
        }
    }
    while (in > 0);
    return 0;
}

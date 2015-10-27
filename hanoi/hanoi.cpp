#include <iostream>

using namespace std;

int size;

void print(int size, int tower_one, int tower_two, int tower_three) {
    for (int i = 0; i < size ; i++) {
        if (--tower_one >= 0) {
            cout << "[]";
        }
        else {
            cout << "  ";
        }

        cout << " | ";

        if (--tower_two >= 0) {
            cout << "[]";
        }
        else {
            cout << "  ";
        }

        cout << " | ";
    
        if (--tower_three >= 0) {
            cout << "[]";
        }
        else {
            cout << "  ";
        }
        cout << endl;
    }

    cout << endl;
}

void solve(int tower_one, int tower_two, int tower_three) {
    if (tower_three == size) {
        cout << "Tower is solved" << endl;
    }
    else if (size % 2 == 0) {
        tower_one--;tower_two++;
        print(size, tower_one, tower_two, tower_three);

        tower_one--;tower_three++;
        print(size, tower_one, tower_two, tower_three);

        tower_two--;tower_three++;
        print(size, tower_one, tower_two, tower_three);

        solve(tower_one, tower_two, tower_three);
    }
    else {
        if (tower_one > 0 && tower_one >= tower_three) {
        tower_one--;tower_three++;
        print(size, tower_one, tower_two, tower_three);
        }

        if (tower_one > 0 && tower_one >= tower_two) {
        tower_one--;tower_two++;
        print(size, tower_one, tower_two, tower_three);
        }

        if (tower_three > 0 && tower_three >= tower_two) {
        tower_three--;tower_two++;
        print(size, tower_one, tower_two, tower_three);
        }

        solve(tower_one, tower_two, tower_three);
    }
}

void solve(int size) {
    solve(size, 0, 0);
}

int main() {
    cout << "Enter size: ";
    cin >> size;

    solve(size);

    return 0;
}

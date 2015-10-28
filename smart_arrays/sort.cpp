/*
    Chapter 12.3
*/
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void sort(list<int> &);

int main() {
    list<int> sort_me = {1,3,5,7,9,2,4,6,8,0};
    sort(sort_me);
    for (auto value : sort_me) {
        cout << value << " ";
    }
    cout << endl; 
    return 0;
}

void sort(list<int> &sort) {
    bool swapped;
    do {
        swapped = false;
        for (auto it = next(sort.begin(), 1); it != sort.end(); it++) {
            auto last = prev(it, 1);
            int a = *last;
            int b = *it;
            if (a > b) {
                *last = b;
                *it = a;
                swapped = true;
            }
        }
    } while(swapped);
}

/**
    Chapter 10.1
*/
#include <iostream>

using namespace std;


unsigned long long int factorial(unsigned long long int number) {
    if (number < 1) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

int main() {
    for (int i = 1 ; i <= 20 ; i++) {
        cout << "Factorial of " << i << ": " << factorial(i) << endl;
    }
    return 0;
}

/*
    10.2
*/
#include <iostream>
#include <string>

using namespace std;

class Text {
    private:
        string value;
        inline string __reverse(string data) {
            if (data.length() <= 1) {
                return data;
            }

            int length = data.length() - 1;
            return data[length] + __reverse(data.substr(0, length));
        };
    public:
        inline Text(string __value) {
            value = __value;
        };
        inline string get_text() {
            return value;
        };
        inline void reverse() {
            value = __reverse(value);
        };
};

int main() {
    Text text = Text("The cow jumped over the moon.");
    cout << "Before: " << text.get_text() << endl;
    text.reverse();
    cout << "After:  " << text.get_text() << endl;
    return 0;
}


/*
    Chapter 12.15
*/
#include<iostream>
#include<string>

using namespace std;

template<typename T> class LinkedStack {
    private:
        struct Node {
            Node* _next;
            Node* _last;
            T _type;
            Node(T type) {
                _type = type;
            };
        };
        Node* _head;
        Node* _tail;
        int _size = 0;
    public:
        /** Grab the size of the stack */
        inline int size() const {
            return _size;
        };
        /** Push a node to the tail of the stack */
        inline void push(const T &type) {
            Node* node = new Node(type);
            if (_size == 0) {
                _head = node;
                _tail = node;
            } else {
                node->_last = _tail;
                _tail->_next = node;
                _tail = node;
            }
            _size++;
        };
        /** Get and remove the top element of the stack */
        inline T pop() {
            if (_size == 0) {
                return NULL;
            } else {
                _size--;
                T type = _tail->_type; 
                if (_tail->_last == NULL) {
                    _tail = NULL;
                    _head = NULL;
                } else {
                    _tail->_last->_next = NULL;
                    _tail = _tail->_last;
                }
                return type;
            }
        };
        /** Get the element that is in the back */
        inline T top() const {
            return _tail == NULL ? NULL : _tail->_type;
        };
        /** Go over the stack and print each element */
        inline void print() const {
            if (_size > 0) {
                Node* node = _head;
                do {
                    cout << node->_type << endl;
                    node = node->_next;
                } while (node != NULL);
            }
        };
};

/** Display the stats of the queue */
template <typename T> void display(const LinkedStack<T> &stack) {
    cout << endl << "STACK STATS" << endl;
    cout << "Size:  " << stack.size() << endl;
    cout << "Top:  " << stack.top() << endl;
    cout << "Elements;" << endl;
    stack.print();
    cout << endl << "----------------" << endl;
}

int main() {
    cout << endl << "----------------" << endl;
    LinkedStack<string> s;
    s.push("ryan");
    s.push("josh");
    s.push("asff");
    s.push("qwer");
    s.push("kyle");
    display(s);
    s.pop();
    s.pop();
    s.pop();
    display(s);
    return 0;
}


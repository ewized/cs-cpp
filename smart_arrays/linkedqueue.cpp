/*
    Chapter 12.6
*/
#include<iostream>
#include<string>

using namespace std;

template<typename T> class LinkedQueue {
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
        /** Grab the size of the queue */
        inline int size() const {
            return _size;
        };
        /** Push a node to the tail of the queue */
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
        /** Get and remove the first element of the queue */
        inline T pop() {
            if (_size == 0) {
                return NULL;
            } else {
                _size--;
                T type = _head->_type; 
                if (_head->_next == NULL) {
                    _tail = NULL;
                    _head = NULL;
                } else {
                    _head->_next->_last = NULL;
                    _head = _head->_next;
                }
                return type;
            }
        };
        /** Get the node that is in front */
        inline T front() const {
            return _head == NULL ? NULL : _head->_type;
        };
        /** Get the element that is in the back */
        inline T back() const {
            return _tail == NULL ? NULL : _tail->_type;
        };
        /** Go over the queue and running the consumer */
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
template <typename T> void display(const LinkedQueue<T> &queue) {
    cout << endl << "QUEUE STATS" << endl;
    cout << "Site:  " << queue.size() << endl;
    cout << "Front: " << queue.front() << endl;
    cout << "Back:  " << queue.back() << endl;
    cout << "Elements;" << endl;
    queue.print();
    cout << endl << "----------------" << endl;
}

int main() {
    cout << endl << "----------------" << endl;
    LinkedQueue<string> q;
    q.push("ryan");
    q.push("josh");
    q.push("asff");
    q.push("qwer");
    q.push("kyle");
    display(q);
    q.pop();
    q.pop();
    q.pop();
    display(q);
    return 0;
}


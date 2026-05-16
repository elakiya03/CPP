#include <iostream>
using namespace std;

class Stack {
    vector<int> s;

   public:
    bool isEmpty() {
        return s.empty();
    }

    void push(int data) {
        s.push_back(data);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        s.pop_back();
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return s.back();
    }

    int size() {
        return s.size();
    }

    void display() {
        for (int i = s.size() - 1; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.display();
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.display();
    cout << s.peek() << endl;
    cout << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
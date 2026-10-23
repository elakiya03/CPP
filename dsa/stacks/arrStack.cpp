#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;

   public:
    Stack(int cap) : capacity(cap), top(-1) {
        arr = new int[cap];  // allocate fixed array on heap
    }

    bool isEmpty() { return top == -1; }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int data) {
        if (top == capacity - 1) {
            throw overflow_error("Stack Overflow");
        }
        arr[++top] = data;
    }

    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack Underflow");
        }
        arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            throw underflow_error("Stack Underflow");
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);
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
    cout << (s.isFull() ? "Yes" : "No") << endl;
    return 0;
}
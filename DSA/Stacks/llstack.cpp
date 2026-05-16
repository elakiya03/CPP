#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
   public:
    Node* top;
    int size;

    Stack() : top(NULL), size(0) {}

    bool isEmpty() { return top == NULL; }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (top == NULL) {
            throw underflow_error("Stack Underflow");
        }
        Node* temp = top;
        top = top->next;
        size--;
        delete temp;
    }

    int count() { return size; }

    int peek() {
        if (top == NULL) {
            throw underflow_error("Stack Underflow");
        }
        return top->data;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    while (1) {
        cout << "\n1. Push" << endl
             << "2. Pop" << endl
             << "3. Display" << endl
             << "4. Peek" << endl
             << "5. Size" << endl
             << "6. Exit" << endl;

        int d, n;
        cout << "Enter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                cout << "Enter value: ";
                cin >> d;
                s.push(d);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Top element: " << s.count() << endl;
                break;
            case 5:
                cout << "Size of stack: " << s.peek() << endl;
                break;
            case 6:
                exit(1);
        }
    }
    return 0;
}
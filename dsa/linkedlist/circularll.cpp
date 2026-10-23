#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CLL {
   private:
    Node* tail;

   public:
    CLL() : tail(nullptr) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            newNode->next = newNode;
            tail = newNode;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void deleteAt(int pos) {
        if (pos < 1 || !tail)
            return;

        Node* head = tail->next;

        // delete first node
        if (pos == 1) {
            // only one node
            if (tail == head) {
                delete head;
                tail = nullptr;
                return;
            }
            tail->next = head->next;
            delete head;
            return;
        }

        Node* curr = head;
        // move to previous node
        for (int i = 1; i < pos - 1 && curr->next != head; i++) {
            curr = curr->next;
        }
        // invalid position
        if (curr->next == head)
            return;
        Node* temp = curr->next;
        curr->next = temp->next;
        // deleting tail
        if (temp == tail) {
            tail = curr;
        }
        delete temp;
    }

    void display() {
        if (!tail) return;

        Node* curr = tail->next;
        Node* temp = curr;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != curr);
    }

    bool isCircular() {
        if (!tail) return true;
        Node* slow = tail;
        Node* fast = tail->next;

        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
int main() {
    CLL cll;

    while (1) {
        cout << "\n1. Insert" << endl
             << "2. Insert Beginning" << endl
             << "3. Delete At" << endl
             << "4. Display" << endl
             << "5. Exit" << endl;

        int data, pos;
        int n;
        cout << endl
             << "Enter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                cout << "Enter value: ";
                cin >> data;
                cll.insertEnd(data);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> data;
                cll.insertBeginning(data);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cll.deleteAt(pos);
                break;
            case 4:
                cll.display();
                break;
            case 5:
                exit(1);
            default:
                cout << "Invalid" << endl;
                break;
        }
    }
    return 0;
}
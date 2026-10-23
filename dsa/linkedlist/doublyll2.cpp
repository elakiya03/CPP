#include <iostream>
using namespace std;

// ================= NODE =================
class Node {
   public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// ============== DLL CLASS ==============
class DLL {
   private:
    Node* head;
    Node* tail;

   public:
    // constructor
    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    // insert at beginning
    void insertBeginning(int val) {
        Node* newNode = new Node(val);

        // empty list
        if (!head) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        // empty list
        if (!head) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // insert at position
    void insertAt(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid Position\n";
            return;
        }

        // beginning
        if (pos == 1) {
            insertBeginning(val);
            return;
        }

        Node* curr = head;

        for (int i = 1; i < pos - 1 && curr; i++) {
            curr = curr->next;
        }

        // invalid position
        if (!curr) {
            cout << "Position out of range\n";
            return;
        }

        // end insertion
        if (curr == tail) {
            insertEnd(val);
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;
    }

    // delete beginning
    void deleteBeginning() {
        if (!head)
            return;

        // only one node
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;

        head = head->next;
        head->prev = nullptr;

        delete temp;
    }

    // delete end
    void deleteEnd() {
        if (!head)
            return;

        // one node
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = tail;

        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
    }

    // delete at position
    void deleteAt(int pos) {
        if (!head || pos < 1)
            return;

        // delete first
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* curr = head;

        for (int i = 1; i < pos && curr; i++) {
            curr = curr->next;
        }

        // invalid position
        if (!curr) {
            cout << "Position out of range\n";
            return;
        }

        // delete last
        if (curr == tail) {
            deleteEnd();
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
    }

    // display forward
    void displayForward() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // display backward
    void displayBackward() {
        Node* temp = tail;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

// ================= MAIN =================
int main() {
    DLL dll;

    while (1) {
        cout << "\n1. Insert" << endl
             << "2. Insert Beginning" << endl
             << "3. Insert At" << endl
             << "4. Delete Beginning" << endl
             << "5. Delete End" << endl
             << "6. Delete At" << endl
             << "7. Forward Display" << endl
             << "8. Backward Display" << endl
             << "9. Exit" << endl;

        int data, pos;
        int n;
        cout << endl
             << "Enter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                cout << "Enter value: ";
                cin >> data;
                dll.insertEnd(data);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> data;
                dll.insertBeginning(data);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> data;
                cout << "Enter Position: ";
                cin >> pos;
                dll.insertAt(data, pos);
                break;
            case 4:
                dll.deleteBeginning();
                break;
            case 5:
                dll.deleteEnd();
                break;
            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                dll.deleteAt(pos);
                break;
            case 7:
                dll.displayForward();
                break;
            case 8:
                dll.displayBackward();
                break;
            case 9:
                exit(1);
            default:
                cout << "Invalid" << endl;
                break;
        }
    }
    return 0;
}
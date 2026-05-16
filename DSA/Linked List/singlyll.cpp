#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    // construtor
    Node(int val) : data(val), next(nullptr) {}
};

typedef Node* LIST;

LIST createNode(int data) {
    LIST temp;
    temp = (LIST)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

LIST insert(LIST head, int data) {
    if (!head) return createNode(data);
    LIST temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}
// insert at beginning
LIST insertBeginning(LIST head, int val) {
    LIST newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

// insert at
LIST insertAt(LIST head, int pos, int val) {
    if (pos < 1) return head;
    if (pos == 1) {
        LIST newNode = createNode(val);
        newNode->next = head;
        return newNode;
    }
    LIST curr = head;
    for (int i = 1; i < pos - 1 && curr; i++) {
        curr = curr->next;
    }
    LIST newNode = createNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// delete at beginning
LIST deleteFront(LIST head) {
    if (head == nullptr) return nullptr;
    LIST temp = head;
    temp = head->next;
    head = temp;
    return head;
}

// delete at end
LIST deleteEnd(LIST head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    LIST curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return head;
}

// delete at
LIST deleteAt(LIST head, int pos) {
    if (!head)
        return nullptr;

    // delete head
    if (pos == 1) {
        LIST temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    LIST curr = head;

    // move to node before target
    for (int i = 1; i < pos - 1 && curr->next; i++) {
        curr = curr->next;
    }

    // invalid position
    if (!curr->next)
        return head;

    LIST temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

// search
bool search(LIST head, int val) {
    LIST temp = head;

    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

// reverse
LIST reverseLinkedList(LIST head) {
    LIST prev = nullptr;
    LIST curr = head;

    while (curr) {
        LIST next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// length of linkedlist
int length(LIST head) {
    int count = 0;
    LIST curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// display
void display(LIST head) {
    LIST temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int middle(LIST head) {
    LIST slow = head;
    LIST fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

// insert a new node after a given node
LIST insertAfter(LIST head, int key, int val) {
    LIST curr = head;
    while (curr) {
        if (curr->data == key) {
            LIST newNode = createNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
            break;
        }
        curr = curr->next;
    }
    return head;
}

// insert a new node before the given key
LIST insertBefore(LIST head, int key, int val) {
    if (!head) return nullptr;
    LIST curr = head;
    if (curr->data == key) return insertBeginning(head, val);
    while (curr->next) {
        if (curr->next->data == key) {
            LIST newNode = createNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
            break;
        }
        curr = curr->next;
    }
    return head;
}

LIST deleteList(LIST head) {
    if (head == NULL) return NULL;
    deleteList(head->next);
    delete head;
}

int getNthStart(LIST head, int pos) {
    LIST curr = head;
    if (length(head) < pos) return -1;
    if (curr == NULL) return -1;
    if (pos == 1) return curr->data;
    return getNthStart(curr->next, pos - 1);
}

int getNthLast(LIST head, int pos) {
    int l = length(head);
    if (l < pos) return -1;

    LIST curr = head;
    for (int i = 1; i < l - pos + 1; i++) {
        curr = curr->next;
    }
    return curr->data;
}

int main() {
    LIST head = NULL;
    while (1) {
        cout << "1. Insert" << endl
             << "2. Insert At beginning" << endl
             << "3. Insert at Position" << endl
             << "4. Delete at begining" << endl
             << "5. Delete at Position" << endl
             << "6. Delete at end" << endl
             << "7. Search" << endl
             << "8. Reverse List" << endl
             << "9. Length" << endl
             << "10. Display" << endl
             << "11. Middle" << endl
             << "12. Exit" << endl
             << "13. InsertAfter" << endl
             << "14. Insert Before" << endl
             << "15. Delete List" << endl
             << "16. Get Nth node from start" << endl
             << "17. Get Nth node from last" << endl;

        int data, pos, key;
        int n;
        cout << endl
             << "Enter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                cout << "Enter value: ";
                cin >> data;
                head = insert(head, data);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> data;
                head = insertBeginning(head, data);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> data;
                cout << "Enter Position: ";
                cin >> pos;
                head = insertAt(head, pos, data);
                break;
            case 4:
                head = deleteFront(head);
                break;
            case 5:
                cout << "Enter Position: ";
                cin >> pos;
                head = deleteAt(head, pos);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                int data;
                cout << "Enter value: ";
                cin >> data;
                cout << (search(head, data) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                head = reverseLinkedList(head);
                break;
            case 9:
                cout << "Length: " << length(head) << endl;
                break;
            case 10:
                display(head);
                break;
            case 11:
                cout << "Middle: " << middle(head) << endl;
                break;
            case 12:
                exit(1);
            case 13:
                cout << "Enter Key Node: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> data;
                head = insertAfter(head, key, data);
                break;
            case 14:
                cout << "Enter Key Node: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> data;
                head = insertBefore(head, key, data);
                break;
            case 15:
                head = deleteList(head);
                break;
            case 16:
                cout << "Nth Node from start: " << getNthStart(head, pos);
                break;
            case 17:
                cout << "Nth node from last: " << getNthLast(head, pos);
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
    return 0;
}
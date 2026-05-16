#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
typedef Node* DLIST;

DLIST createNode(int data) {
    return new Node(data);
}

DLIST insert(DLIST head, int data) {
    if (!head) return createNode(data);
    DLIST temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = createNode(data);
    temp->next->prev = temp;
    return head;
}

DLIST insertBeginning(DLIST head, int data) {
    if (!head) return createNode(data);

    DLIST newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

DLIST insertAt(DLIST head, int data, int pos) {
    DLIST newNode = createNode(data);
    if (!head) return newNode;
    if (pos < 1) return head;
    if (pos == 1) {
        return insertBeginning(head, data);
    }

    DLIST curr = head;
    for (int i = 1; i < pos - 1 && curr; i++) {
        curr = curr->next;
    }
    // If the position is out of bounds
    if (curr == NULL) {
        delete newNode;
        return head;
    }
    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
    return head;
}

DLIST deleteBeginning(DLIST head) {
    if (!head) return NULL;
    DLIST curr = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete curr;
    return head;
}

DLIST deleteEnd(DLIST head) {
    if (!head) return nullptr;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    DLIST curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
    return head;
}

DLIST deleteAt(DLIST head, int pos) {
    if (!head) return NULL;
    if (pos == 1) return deleteBeginning(head);
    DLIST curr = head;
    for (int i = 1; i < pos && curr; i++) {
        curr = curr->next;
    }
    if (curr == NULL) return head;

    // if the node to delete is not the first node
    // update previous node's next
    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    // if the node to delete is not the last node
    // update next node's prev
    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    // if deleting the head, move head pointer to next node
    if (head == curr)
        head = curr->next;

    delete curr;
    return head;
}
void displayFrwd(DLIST head) {
    DLIST l = head;
    while (l != NULL) {
        cout << l->data << " ";
        l = l->next;
    }
}

void displayBack(DLIST head) {
    if (!head)
        return;

    DLIST temp = head;

    // move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // traverse backward
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

// length of linkedlist
int length(DLIST head) {
    int count = 0;
    DLIST curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    DLIST head = NULL;

    while (1) {
        cout << "\n1. Insert" << endl
             << "2. Insert Beginning" << endl
             << "3. Insert At" << endl
             << "4. Delete Beginning" << endl
             << "5. Delete End" << endl
             << "6. Delete At" << endl
             << "7. Forward Display" << endl
             << "8. Backward Display" << endl
             << "9. Length" << endl
             << "10. Exit" << endl;

        int data, pos;
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
                head = insertAt(head, data, pos);
                break;
            case 4:
                head = deleteBeginning(head);
                break;
            case 5:
                head = deleteEnd(head);
                break;
            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                head = deleteAt(head, pos);
                break;
            case 7:
                displayFrwd(head);
                break;
            case 8:
                displayBack(head);
                break;
            case 9:
                cout << "Length: " << length(head);
                break;
            case 10:
                exit(1);
            default:
                cout << "Invalid" << endl;
                break;
        }
    }
    return 0;
}
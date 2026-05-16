#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (!root) return new Node(data);

    Node* curr = root;
    while (curr) {
        if (curr->data > data && curr->left) {
            curr = curr->left;
        } else if (curr->data < data && curr->right) {
            curr = curr->right;
        } else
            break;
    }

    if (curr->data > data) {
        curr->left = new Node(data);
    } else {
        curr->right = new Node(data);
    }
    return root;
}

void inorder(Node* tree) {
    if (!tree) return;

    inorder(tree->left);
    cout << tree->data << " ";
    inorder(tree->right);
}

void preorder(Node* tree) {
    if (!tree) return;
    cout << tree->data << " ";
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(Node* tree) {
    if (!tree) return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << " ";
}

void levelorder(Node* tree) {
    if (!tree) return;
    queue<Node*> q;
    q.push(tree);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

void display(Node* root) {
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
    cout << "Level Order Traversal: ";
    levelorder(root);
    cout << endl;
}

bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    if (val > root->data)
        return search(root->right, val);
    else
        return search(root->left, val);
}

int findmin(Node* root) {
    if (!root) return -1;
    Node* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr->data;
}

int findmax(Node* root) {
    if (!root) return -1;
    Node* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    return curr->data;
}

bool isBST(Node* root, Node*& prev) {
    if (!root) return true;

    if (!isBST(root->left, prev)) return false;

    if (prev && root->data <= prev->data)
        return true;

    prev = root;
    return isBST(root->right, prev);
}

int main() {
    Node* root = NULL;
    int data, n;
    while (1) {
        cout << "\n1. Insertion" << endl
             << "2. Display" << endl
             << "3. Search" << endl
             << "4. Minimum" << endl
             << "5. Maximum" << endl
             << "6. isBST" << endl;

        cout << "\nEnter your choice: ";
        cin >> n;
        switch (n) {
            case 1:
                root = insert(root, 5);
                root = insert(root, 4);
                root = insert(root, 6);
                root = insert(root, 2);
                root = insert(root, 3);
                break;
            case 2:
                display(root);
                break;
            case 3:
                cout << (search(root, 4) ? "Found" : "Not found") << endl;
                cout << (search(root, 9) ? "Found" : "Not found") << endl;
                break;
            case 4:
                cout << "Min: " << findmin(root) << endl;
                break;
            case 5:
                cout << "Max: " << findmax(root) << endl;
                break;
            case 6:
                Node* prev = NULL;
                cout << (isBST(root, prev) ? "Yes" : "No") << endl;
                break;
        }
    }
    return 0;
}
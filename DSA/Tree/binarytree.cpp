#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Binary {
    Node* root;

    Node* createTree() {
        int data;
        cout << "Enter value (-1 for NULL): ";
        cin >> data;

        if (data == -1) return nullptr;
        Node* root = new Node(data);

        cout << "Left of " << data << endl;
        root->left = createTree();
        cout << "Right of " << data << endl;
        root->right = createTree();

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

    int height(Node* tree) {
        if (!tree) return -1;
        int left = height(tree->left);
        int right = height(tree->right);
        return max(left, right) + 1;
    }

    int depth(Node* tree, int target, int d) {
        if (!tree) return -1;
        if (tree->data == target) return d;

        int left = depth(tree->left, target, d + 1);
        if (left != -1) return left;
        return depth(tree->right, target, d + 1);
    }

    bool search(Node* tree, int val) {
        if (!tree) return false;

        if (tree->data == val) return true;
        bool left = search(tree->left, val);
        if (left) return true;
        bool right = search(tree->right, val);
        return right;
    }

    int totalcount(Node* tree) {
        if (!tree) return 0;
        return 1 + totalcount(tree->left) + totalcount(tree->right);
    }

    int totalleaves(Node* tree) {
        if (!tree) return 0;
        if (!tree->left && !tree->right) return 1;
        return totalleaves(tree->left) + totalleaves(tree->right);
    }

   public:
    Binary() { root = nullptr; }

    // level order insertion
    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            // front element in queue
            Node* curr = q.front();
            q.pop();

            // insert left
            if (!curr->left) {
                curr->left = newNode;
                return;
            } else {
                q.push(curr->left);
            }

            // insert right
            if (!curr->right) {
                curr->right = newNode;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }

    void buildTree() {
        root = createTree();
    }

    void display() {
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

    int calculateHeight() {
        return height(root);
    }

    int depth(int target) {
        return depth(root, target, 0);
    }

    bool search(int val) {
        return search(root, val);
    }

    int totalcount() {
        return totalcount(root);
    }

    int totalleaves() {
        return totalleaves(root);
    }
};

int main() {
    Binary b;

    while (1) {
        cout << "\n1. Create Tree" << endl
             << "2. Insert" << endl
             << "3. Display" << endl
             << "4. Height/Depth" << endl
             << "5. Level of a Node" << endl
             << "6. Search" << endl
             << "7. Total nodes" << endl
             << "8. Total Leaves " << endl
             << "9. Exit" << endl;

        int n, data;
        cout << "\nEnter your choice: ";
        cin >> n;

        switch (n) {
            case 1:
                b.buildTree();
                break;
            case 2:
                // cout << "Enter your value: ";
                // cin >> data;
                b.insert(1);
                b.insert(2);
                b.insert(3);
                b.insert(4);
                b.insert(5);
                b.insert(6);
                break;
            case 3:
                b.display();
                break;
            case 4:
                b.calculateHeight();
                break;
            case 5:
                cout << "Enter your value: ";
                cin >> data;
                cout << b.depth(data) << endl;
                break;
            case 6:
                cout << "Enter your value: ";
                cin >> data;
                cout << (b.search(data) ? "Found" : "Not Found") << endl;
                break;
            case 7:
                cout << "total nodes count: " << b.totalcount() << endl;
                break;
            case 8:
                cout << "Total leaves count: " << b.totalleaves() << endl;
                break;
            case 9:
                exit(1);
        }
    }
    return 0;
}
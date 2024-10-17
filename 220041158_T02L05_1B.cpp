#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node *left, *right, *parent;

    Node(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinarySearchTree {
private:
    Node *root;

    Node* insertNode(Node* node, int value) {
        Node *current = node, *parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }

        Node *newNode = new Node(value);
        newNode->parent = parent;
        if (parent == nullptr) {
            root = newNode;
        } else if (value < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        return root;
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }

    void levelOrderTraversal(Node* node) {
        if (node == nullptr) return;
        queue<Node*> q;
        q.push(node);
        int level = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            cout << "Level " << level << ": ";
            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();
                cout << current->value << " ";
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }
            cout << endl;
            ++level;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void printInorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void printPreorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void printPostorder() {
        postorderTraversal(root);
        cout << endl;
    }

    void printLevelOrder() {
        levelOrderTraversal(root);
    }
};

int main() {
    BinarySearchTree bst;
    int n, value;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        bst.insert(value);
    }

    cout << "Inorder: ";
    bst.printInorder();

    cout << "Preorder: ";
    bst.printPreorder();

    cout << "Postorder: ";
    bst.printPostorder();

    cout << "Level-order: " << endl;
    bst.printLevelOrder();

}
